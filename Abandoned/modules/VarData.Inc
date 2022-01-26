Function VarData.GetType ( )As SHORT
If this.VString<>(-1) And this.VString<>NULL Then
Return vStr
ElseIf this.VString=-1 THEN
Return vStk
ElseIf this.Vint<>0  Then
Return vInte
ElseIf this.Vdou<>0.0 Then
Return vDoub
else
Return vEmp
End if
End Function
#If DBG
function VarData.GetData()As string

   If This.gettype = vStr Then
      If This.vstring=NULL Then RETURN "" 
      return *(This.vstring) 'String
   End if
   If This.gettype = vDoub Then
      return str(This.vdou)'Double

   End if
   If This.gettype = vInte Then
      return str(This.vint)  'Integer
   End if
   If This.gettype = vStk Then
Dim iI as integer
Dim tmp as string
'DEBUG CODE:Print "USED="+Str( (*Cast(Array ptr,(THIS.vint))).used(0) ) CR
  For  iI=1 To (*Cast(Array ptr,(THIS.vint))).used(0)'Array Datas
tmp+=(*(*Cast(Array ptr,(THIS.vint))).place(iI).getdata)+","
  next
Return "{"+left(tmp,len(tmp)-1)+"}"
'去掉最后一个换行
   End if
    return "[Empty]" 'Empty
End function
#endif