/* BYTE0x37c6; WORDcode:1be3; gcc_tablejump_helper */

/* WARNING: This is an inlined function */
/* GCC tablejump helper. Marked inline so each caller's flash-table base is visible. Actual12entry
   tables at BYTEcc/e4/fc/114; targets WORD-addressed. Verify generated switch output against source
   bytes. */

void gcc_tablejump_helper(void)

{
  R1 = 0;
  Z = (undefined2 *)CONCAT11(Z._1_1_ * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
  Z = (undefined2 *)*Z;
                    /* WARNING: Could not recover jumptable at 0x1be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)Z)();
  return;
}

