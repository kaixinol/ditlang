# Development has been suspended ;(
### Language [README.md](README.md) | [README_zh-cn.md](README_zh-cn.md)
### Update logs [更新记录.txt](更新记录.txt)
## Brief introduction

This programming language is built by FreeBASIC language.

The original intention of creating this language is to make software upgrades easier.

Syntax is similar to assembly language.

## How to build
Use [VFB ide](http://www.yfvb.com/soft-48.htm) to compile directly under Window x64 environment.
## Example codes
```
var a
main:
var b
var c
mov a,'hello，i\'m obj-a!'
mov b,16
push c,a
push c,b
call <MessageBox c>
free a
var a
mov a,16
jnz a,$+5
mov c,<xor a,b>
ret c
nop
nop
hlt 1
end.
```
C language version:
```
#include"DitWinBasicConIO.h"
#include"DitWinAPICaLL.h"
#include"CVariant.h"
#include"DitRunTimeError.h"
CVariant a;
int main()
{
CVariant b,c;
a.setstrval("hello，i\'m obj-a!");
b.setintval(16);
c.push(a);
c.push(b);
CallWinAPI("MessageBox",c);
a.save();
free(a);
CVariant a;
a.setintval(16);
if(a.getintval()){goto line;}
c.setintval(a.getintval()^b.getintval());
return c;
(void)0;
(void)0;
line: __asm("lea");
}
```
## Todos
- Add function check
- Simple Dit code execution
## Dependent project
- [GetToken](https://github.com/3XDot/GetToken)
- [WinAPICall](https://github.com/3XDot/WinAPICall)
## License
[MIT License](https://github.com/3XDot/FreeBASICDit/blob/master/LICENSE) &  [The Star And Thank Author License](https://github.com/zTrix/sata-license) 
