>**You need to use a markdown editor that supports flowchart rendering for rendering**
```flow
st=>start: 
e=>end
op=>operation: show an error message.
op0=>operation: var a
op1=>operation: push a,'hello?'
op2=>operation: push a,16
op3=>operation: int 1
op4=>operation: call <Message>,a
op5=>operation: Show a message box 
cond=>condition: Does the function 'message' exist? 
st->op0->op1->op2->op3->op4->cond
cond(yes)->op5->e
cond(no)->op
```

```x86asm
var a
push a,'hello?'
push a,16
int 1
call <Message>,a
```
`int 0` makes the interpreter enter **virtual mode** *(function call requests will be forwarded to the interpreter for execution)*

`int 1` makes the interpreter enter **real mode** *(function call requests will be forwarded to the dynamic library for execution) *