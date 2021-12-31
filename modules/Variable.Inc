#If DBG
Sub Variable.PrintData()
      If Len(This.vname) = 0 Then
         This.vname="[Unused]"
      End if
   If This.gettype = vStr Then
      If Len(This.vname) = 0 Then
         printf "[Unused]::String->"+*(This.vstring)  + vbcrlf 'String
      else
         printf This.vname+ "::String->"+ *(This.vstring)  + vbcrlf 'String
      End if
      Exit sub
   End if
   If This.gettype = vStk Then
     printf This.vname + "::<Array>"+ vbcrlf 'Array
      Exit sub
   End if
   If This.gettype = vDoub Then
      printf This.vname + "::Double->" + str(This.vdou) + vbcrlf 'Double
      Exit sub
   End if
   If This.gettype = vInte Then
      printf This.vname + "::Integer->" + str(This.vint) + vbcrlf 'Integer
      Exit sub
   End if
   printf This.vname + "::Empty" + vbcrlf 'Empty
If This.vname = "[Unused]" Then
This.vname=""
End if
End Sub
#endif
function Variable.GetData()As string
   If This.gettype = vStr Then
      If This.vstring = NULL Then RETURN ""
      return * (This.vstring) 'String
   End if
   If This.gettype = vDoub Then
      return str(This.vdou) 'Double
      
   End if
   If This.gettype = vInte Then
      return str(This.vint) 'Integer
   End if
    If This.gettype = vStk Then
     ' return  'Array
   End if       
   return "[Empty]" 'Empty
End function

SUB Variable.SetData(vardata_ As VarData) '***Set variable value
   this.VDou    = vardata_.VDou
   this.VInt    = vardata_.VInt
   This.VString = vardata_.VString
End Sub
Function Variable.GetType() As Short
   If this.VString <> NULL Then
      Return vStr
   ElseIf this.Vint <> 0 Then
      Return vInte
   ElseIf this.Vdou <> 0.0 Then
      Return vDoub
   Else
      Return vEmp
   End if
End Function

Sub Variable.ClearData ( )
   THIS.VNAME="[Unused]"
   Delete This.vstring
   This.vstring=NULL
   This.vint=0
   This.vdou=0
End sub
