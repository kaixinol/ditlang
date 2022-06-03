#define UNICODE
#lang "FB"
#include Once "windows.bi"
#include once "crt.bi"
#include once "file.bi"
#include Once "vbcompat.bi"
#include once "Function.bi"
#include once "crt/limits.bi"
Function FileLength(filename As wstring Ptr)As Long
      Dim As wstring * 4 k="r"
      Var fp=_wfopen(filename,@k)
      If fp = 0 Then Print "Error opening file":Sleep:End
      fseek(fp, 0, SEEK_END)
      Var length=ftell(fp)
      fclose(fp)
      Return(length)
End Function


function LoadFile (filename As wString Ptr)as string
      Var l=Filelength(filename)
   dim as string content =String(l,0)
      Dim As wstring * 4 k="rb"
      Var fp= _wfopen(filename,@k,"rt+,ccs=UTF-8")
      If fp = 0 Then Print "Error loading file ";filename:Sleep:End
      fread(@content[0], 1,l, fp)
      fclose(fp)
      return content
End function

Sub SaveFile (content As String ,filename As wstring Ptr)
      Dim As wstring * 4 k="wb"
      Var fp= _wfopen(filename,@k)
      If fp = 0 Then Print "Error opening file":Sleep:End
      fwrite(@content[0], 1, Len(content), fp)
      fclose(fp)
End Sub

Function Exists(filename As wString Ptr) As boolean
      Dim As wstring * 4 k="r"
      Var fp= _wfopen(filename,@k)
      If fp=0 Then
            Return false
      Else
            fclose(fp)
            Return true
      End If
      
End Function
' FROM https://www.freebasic.net/forum/viewtopic.php?p=291479
function split(res() as string,strg as string,delim as string=" ",limit as integer=-1)as integer /' return value is total number of elements'/
	dim as integer resmax=0
	dim as integer strglen=len(strg),posinstrg=1,delimlen=len(delim),delimfound
	if strglen=0 then ''len = zero --> empty array
		return 0
	End If
	
	if len(delimlen)=0 or instr(posinstrg,strg,delim)=0 then ''One element the original string
		redim res(0)
		res(0)=strg
		return 1
	End If
	
	if limit=-1 then
		limit=INT_MAX
	End If
	
	while posinstrg<strglen and resmax<limit
		
		delimfound=instr(posinstrg,strg,delim)
		redim preserve res(resmax)
		if delimfound then
			res(resmax)=mid(strg,posinstrg,delimfound-posinstrg)
			posinstrg+=delimlen+len(res(resmax))
		else
			res(resmax)=mid(strg,posinstrg)
			posinstrg+=len(res(resmax))
		end if
		resmax+=1
	Wend
	
	return resmax
End FUNCTION



/'
Parse 模型
# comment
<ins> ...
 tab or space
'/

Function IsComment(byval s as string)as Boolean
trim(s)
trim(s,vbtab)
if instr(s,"#")=1  or len(s)=0 then 
return true
Else
return false
endif
end function

/'
Parse 模型
[<Type> :: ]<Name>           :
                |()          :   
                |(<Type>,...):
'/

sub ParseFunc(code() as string,SumLine as integer)
dim  as integer i,ii
For i=0 to SumLine 
   if instrrev(code(i),":")=len(code(i)) and  IsComment(code(i))=false/' 不为垃圾代码 '/ Then
      For ii=i+1 to  SumLine
         if code(ii)="end." Then 'begin & end
            Dim bar as ScriptFunction
            bar.begin=i
            bar.end=ii
            print "begin:"+Str(i)+" end:"+Str(ii)
            exit for
          '     if code(i)
                 'bar.PassParameterType
         endif
      next
   endif
next
End sub

