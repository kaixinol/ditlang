# 已暂停开发 ;(
### Language [README.md](README.md) | [README_zh-cn.md](README_zh-cn.md)
### 更新记录 [更新记录.txt](更新记录.txt)
## 简要说明
这个编程语言是由FreeBASIC语言构建的

创造这个语言的初衷是为了使软件升级变得更加容易

语法类似于汇编语言

## 如何构建
Window x64环境下使用[VFB ide](http://www.yfvb.com/soft-48.htm)直接编译即可
## 示例代码
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
## 待办事项
- 添加函数检查
- 简单的Dit代码执行
## 依赖项目
- [GetToken](https://github.com/3XDot/GetToken)
- [WinAPICall](https://github.com/3XDot/WinAPICall)
## 执照
[MIT License](https://github.com/3XDot/FreeBASICDit/blob/master/LICENSE) &  [The Star And Thank Author License](https://github.com/zTrix/sata-license) 
