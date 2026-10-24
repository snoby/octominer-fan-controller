"""Small sequential AVR instruction executor for the captured EEPROM slice.
Not a full AVR, cycle-accurate peripheral model, or interrupt simulator.
Registers0..31 and their data-memory aliases share the SAME byte array.
"""
class AvrSlice:
    EECR=0x3f
    EEDR=0x40
    EEAR=0x41
    SREG=0x5f

    def __init__(self,flash,eeprom,interrupts_enabled=True):
        self.flash=bytes(flash)
        self.eeprom=bytearray(eeprom)
        self.mem=bytearray(0x900)
        self.mem[self.SREG]=0x80 if interrupts_enabled else 0
        self.reads=[]
        self.writes=[]
        self.strobes=[]
        self.busy_reads=0
        self.trace=[]
        self.callstack=[]
        self.completed=False

    def get16(self,reg):
        return self.mem[reg] | self.mem[reg+1]<<8

    def set16(self,reg,value):
        self.mem[reg]=value&255
        self.mem[reg+1]=(value>>8)&255

    def read_mem(self,address):
        value=self.mem[address]
        if address==self.EECR and self.busy_reads:
            self.busy_reads-=1
            if self.busy_reads==0:self.mem[address]&=~2
        return value

    def write_mem(self,address,value):
        value&=255
        old=self.mem[address]
        self.mem[address]=value
        if address==self.EECR and value&1:
            location=self.get16(self.EEAR)
            if not 0<=location<len(self.eeprom):raise ValueError('Out-of-range EEPROM address')
            self.mem[self.EEDR]=self.eeprom[location]
            self.reads.append(location)
            self.mem[address]&=~1
        if address==self.EECR and value&2:
            if not old&4:raise AssertionError('EEPROM write without master enable')
            enabled=bool(self.mem[self.SREG]&128)
            if enabled:raise AssertionError('EEPROM strobe with interrupts enabled')
            location=self.get16(self.EEAR)
            if not 0<=location<len(self.eeprom):raise ValueError('Out-of-range EEPROM address')
            self.eeprom[location]=self.mem[self.EEDR]
            self.writes.append((location,self.mem[self.EEDR]))
            self.strobes.append({'pc':self.pc,'interrupts_enabled':enabled})
            self.mem[address]=(value&~5)|2
            self.busy_reads=2

    @staticmethod
    def signed(value,bits):
        return value-(1<<bits) if value&(1<<(bits-1)) else value

    def flags_sub(self,a,b,carry=0,chain=False):
        old_zero=bool(self.mem[self.SREG]&2)
        result=(a-b-carry)&255
        c=int(a<b+carry);z=int(result==0 and (old_zero if chain else True))
        n=result>>7;v=int(bool((a^b)&(a^result)&128));s=n^v
        h=int(bool(((~a&b)|(b&result)|(result&~a))&8))
        self.mem[self.SREG]=(self.mem[self.SREG]&0xc0)|c|(z<<1)|(n<<2)|(v<<3)|(s<<4)|(h<<5)
        return result

    def instruction_size(self,pc):
        op=int.from_bytes(self.flash[pc:pc+2],'little')
        return 4 if op&0xfe0e in (0x940c,0x940e) or op&0xfe0f in (0x9000,0x9200) else 2

    def run(self,entry,max_steps=1000):
        pc=entry
        for _ in range(max_steps):
            if not 0x3880<=pc<0x3912:raise RuntimeError(f'Execution left EEPROM slice at {pc:#x}')
            self.pc=pc
            op=int.from_bytes(self.flash[pc:pc+2],'little');self.trace.append((pc,op));next_pc=pc+2
            d=(op>>4)&31;r=(op&15)|((op>>5)&16)
            if op&0xf000==0xe000: # LDI
                self.mem[16+((op>>4)&15)]=(op&15)|((op>>4)&240)
            elif op&0xff00==0x0100: # MOVW
                self.set16(((op>>4)&15)*2,self.get16((op&15)*2))
            elif op&0xf800==0xb000: # IN
                a=(op&15)|((op>>5)&0x30);self.mem[d]=self.read_mem(a+0x20)
            elif op&0xf800==0xb800: # OUT
                a=(op&15)|((op>>5)&0x30);self.write_mem(a+0x20,self.mem[d])
            elif op&0xfc00==0x2c00: # MOV
                self.mem[d]=self.mem[r]
            elif op&0xfc00==0x1400: # CP
                self.flags_sub(self.mem[d],self.mem[r])
            elif op==0x94f8: # CLI
                self.mem[self.SREG]&=127
            elif op&0xfc00==0x2400: # EOR, including CLR alias
                x=self.mem[d]^self.mem[r];self.mem[d]=x;n=x>>7
                self.mem[self.SREG]=(self.mem[self.SREG]&0xe1)|(int(x==0)<<1)|(n<<2)|(n<<4)
            elif op&0xff00==0x9900: # SBIC
                a=((op>>3)&31)+0x20;bit=op&7
                if not self.read_mem(a)&(1<<bit):next_pc+=self.instruction_size(next_pc)
            elif op&0xff00==0x9a00: # SBI
                a=((op>>3)&31)+0x20;self.write_mem(a,self.read_mem(a)|(1<<(op&7)))
            elif op&0xf000==0xc000: # RJMP
                next_pc+=2*self.signed(op&0xfff,12)
            elif op&0xfe0e in (0x940c,0x940e): # JMP/CALL
                if op&0xfe0e==0x940e:self.callstack.append(pc+4)
                w=int.from_bytes(self.flash[pc+2:pc+4],'little');next_pc=2*(((op&0x1f0)<<13)|((op&1)<<16)|w)
            elif op&0xfe0f==0x920d: # ST X+,Rr
                x=self.get16(26);self.write_mem(x,self.mem[d]);self.set16(26,x+1)
            elif op&0xf000 in (0x5000,0x4000): # SUBI/SBCI
                reg=16+((op>>4)&15);imm=(op&15)|((op>>4)&240);chain=op&0xf000==0x4000
                carry=(self.mem[self.SREG]&1) if chain else 0
                self.mem[reg]=self.flags_sub(self.mem[reg],imm,carry,chain)
            elif op&0xff00 in (0x9600,0x9700): # ADIW/SBIW
                reg=24+((op>>4)&3)*2;imm=(op&15)|((op>>2)&0x30);old=self.get16(reg)
                subtract=op&0xff00==0x9700;value=(old-imm if subtract else old+imm)&65535
                n=value>>15
                if subtract:v=int(bool(old&0x8000) and not(value&0x8000));c=int(not(old&0x8000) and bool(value&0x8000))
                else:v=int(not(old&0x8000) and bool(value&0x8000));c=int(bool(old&0x8000) and not(value&0x8000))
                self.set16(reg,value);self.mem[self.SREG]=(self.mem[self.SREG]&0xe0)|c|(int(value==0)<<1)|(n<<2)|(v<<3)|((n^v)<<4)
            elif op&0xfc00 in (0xf000,0xf400): # BRBS/BRBC
                flag=bool(self.mem[self.SREG]&(1<<(op&7)));set_branch=op&0xfc00==0xf000
                if flag==set_branch:next_pc+=2*self.signed((op>>3)&127,7)
            elif op==0x9508: # RET; outer call supplied by harness
                if self.callstack:next_pc=self.callstack.pop()
                else:self.completed=True;return self
            else:raise NotImplementedError(f'Unsupported opcode {op:#06x} at {pc:#06x}')
            pc=next_pc
        raise TimeoutError('EEPROM slice exceeded instruction budget')
