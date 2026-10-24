#!/usr/bin/env python3
"""Run bounded, read-only independent Claude reviews in parallel."""
import concurrent.futures,json,os,pathlib,subprocess,time
ROOT=pathlib.Path('/Users/snoby/octominer-re')
OUT=ROOT/'analysis/claude-review'
SCOPES=['fan-control','watchdog-and-usb','peripherals-and-decompiler-quality']
def run(scope):
    prompt=(OUT/(scope+'.prompt.txt')).read_text()
    args=['claude','-p',prompt,'--model','opus','--effort','medium','--output-format','json','--max-turns','24','--tools','Read,Grep,Glob','--allowedTools','Read,Grep,Glob','--permission-mode','dontAsk','--strict-mcp-config','--mcp-config','{"mcpServers":{}}','--settings','{"disableAllHooks":true}']
    env=os.environ.copy();env.setdefault('TERM','xterm-256color')
    start=time.time();print('START '+scope,flush=True)
    with (OUT/(scope+'.json')).open('w') as out,(OUT/(scope+'.stderr.txt')).open('w') as err:
        result=subprocess.run(args,cwd=ROOT,env=env,stdout=out,stderr=err)
    meta={'scope':scope,'exit_code':result.returncode,'seconds':round(time.time()-start,1)}
    try:
        doc=json.loads((OUT/(scope+'.json')).read_text())
        meta.update({k:doc.get(k) for k in ['subtype','is_error','num_turns','session_id','stop_reason','terminal_reason']})
        meta['model_usage']=list((doc.get('modelUsage') or {}).keys())
        text=doc.get('result')
        if text:(OUT/(scope+'.md')).write_text(text+'\n')
    except Exception as e:meta['parse_error']=str(e)
    (OUT/(scope+'.meta.json')).write_text(json.dumps(meta,indent=2)+'\n')
    print('COMPLETE '+json.dumps(meta),flush=True)
    return meta
with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
    results=list(pool.map(run,SCOPES))
(OUT/'batch-summary.json').write_text(json.dumps(results,indent=2)+'\n')
if any(x['exit_code'] or x.get('is_error') or x.get('subtype')!='success' for x in results):raise SystemExit(1)
