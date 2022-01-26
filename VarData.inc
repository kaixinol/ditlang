#define MG_NUM 2126
#define NULL 0
#define OTHER MG_NUM,MG_NUM
Type VarData
Vstring As String ptr
VDou As double
VInt As integer
VPtr as any ptr
#IFDEF __ARRAY_USED__
VArray As VarData ptr 
#ENDIF
Declare Function GetType()As short                      
Declare Function GetData()As string
End type
Function VarData.GetType ( )As SHORT

#define vStr 1
#define vDoub 2
#define vInte 3 
#define vPointer 4
#define vEmp 0

If this.VString<>NULL Then
Return vStr
ElseIf this.Vptr<>NULL THEN
Return vPointer
ElseIf this.Vint<>MG_NUM  Then
Return vInte
ElseIf this.Vdou<>MG_NUM Then
Return vDoub
else
Return vEmp
End if
End Function