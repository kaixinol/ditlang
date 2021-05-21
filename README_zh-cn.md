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
```
main:
VAR FF 
VAR G
LET FF=1
LET G=<CALL <print FF>>
FREE FF
RET  G
END main
```
## 待办事项
- 添加函数检查
- 简单的Dit代码执行
## 依赖项目
- [GetToken](https://github.com/3XDot/GetToken)
- [WinAPICall](https://github.com/3XDot/WinAPICall)
## 执照
[MIT License](https://github.com/3XDot/FreeBASICDit/blob/master/LICENSE) &  [The Star And Thank Author License](https://github.com/zTrix/sata-license) 
