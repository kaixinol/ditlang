Type Bool2D
 IsLeft As BOOLEAN
 IsUsed As BOOLEAN=False
 RealDb As short
End Type
Type Str2D
str1 As String Ptr
str2 As String Ptr
End Type
Type VarData
Vstring As String ptr
VDou As double
VInt As integer
Declare Function GetType ()As short
Declare Function GetData()As string
End Type
Type Variable
#if DBG
Declare Sub PrintData ()
#endif
Declare Sub  SetData (vardata_ As VarData) 
Declare Function GetData ()As string
Declare Function GetType ()As short
Declare Sub ClearData( )
VName As String
VString As String ptr
VDou As Double
VInt As INTEGER
End type
Type Token
begin As Long=0
_end As long=0
End type
Type Array
Declare Sub Push (argv As VarData) 
Declare Sub Pop () 
Declare Sub Init (ByVal num As short)
used(1) As UShort 
/'
used(1):Number of allocated memory Space.
used(0):Number of used memory space.
To release the memory, only need to release 'used(0)' 
'/
place(any) As VarData ptr
End TYpe
Type Func
Argvs As Array
LineBegin As Short
LineEnd As Short
FuncName As String
Declare function GetArgv(num As uinteger) As VarData
End Type
Type FileA
Funcz(any) As Func
SharedVar(any) As Variable ptr
End type
Declare Operator = ( ByRef a As Variable, ByRef b As Variable ) As BOOLEAN
Operator = ( ByRef a As Variable, ByRef b As Variable ) As BOOLEAN
  Dim aq as short=0
  If a.vname=b.vname Then aq+=1
  If a.vstring=b.vstring Then aq+=1
  If a.vint = b.vint Then aq+=1
  If a.vdou =b.vdou Then aq+=1
  If a.gettype =b.gettype Then aq+=1
Return aq=5
End Operator
Declare Operator <> ( ByRef a As token, ByRef b As token ) As BOOLEAN
Operator <> ( ByRef a As token, ByRef b As token ) As BOOLEAN
If a.begin<>b.begin Or a._end<>b._end Then
 Return true
Else 
Return False
End if
End Operator
Declare Operator = ( ByRef a As token, ByRef b As token ) As BOOLEAN
Operator = ( ByRef a As token, ByRef b As token ) As BOOLEAN
If a.begin=b.begin and a._end=b._end Then
Return true
Else 
Return False
End if
End Operator
Declare Operator <> ( ByRef a As Variable, ByRef b As Variable ) As BOOLEAN
Operator <> ( ByRef a As Variable, ByRef b As Variable ) As BOOLEAN
  If a.vname<>b.vname Then Return true
  If a.vstring<>b.vstring Then Return true
  If a.vint <> b.vint Then Return true
  If a.vdou <>b.vdou Then Return true
  If a.gettype <>b.gettype Then Return true
Return false
End Operator
Declare Operator = ( ByRef a As VarData, ByRef b As VarData ) As BOOLEAN
Operator = ( ByRef a As VarData, ByRef b As VarData ) As BOOLEAN
  Dim aq as short=0
  If a.vstring=b.vstring Then aq+=1
  If a.vint = b.vint Then aq+=1
  If a.vdou =b.vdou Then aq+=1
Return aq=3
End Operator
Declare Operator <> ( ByRef a As VarData, ByRef b As VarData ) As BOOLEAN
Operator <> ( ByRef a As VarData, ByRef b As VarData ) As BOOLEAN
  If a.vstring<>b.vstring Then Return true
  If a.vint <> b.vint Then Return true
  If a.vdou <>b.vdou Then Return true
Return false
End Operator


 


'#inclib "GetToken"
'Extern "C++"
'Declare Sub match(sf As ZString Ptr,_data As Token ptr)
'End Extern   
Declare Function DUSTAPICALL Lib "WinAPICall" Alias "APICALL"(ZLNAME As String Ptr ,D(Any) As VarData Ptr) As BOOLEAN
Declare Sub ver Lib "WinAPICall" Alias "DLLVER"()