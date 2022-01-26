#include Once "windows.bi"

#define Errfunc __FUNCTION__

enum
ERR_READ_FAILED=1,
ERR_PARSE_ERR,
ERR_ARGU_TOO_LOT,
ERR_ARGU_TOO_LESS,
ERR_NO_INSTRUCTION,
ERR_CANNOT_LOAD_DLL,
ERR_UNACCEPTABLE_IDENTIFIER,
ERR_TYPE_NOT_DEFINED,
ERR_UNACCEPTABLE_TABLE,
ERR_FUNCTION_WITHOUT_END,
ERR_FUNCTION_WITHOUT_BEGIN,
ERR_UNACCEPTABLE_RETURN_VALUE_OR_TYPE
end enum
#define gui_type 1
#define con_type 0

#define Emsg "*"+Func+chr(10,13)
dim shared ErrType as integer

#define SetPromptType(type) ErrType=type
sub Meesage(context as const wstring ptr)
if ErrType=gui_type then
MessageBoxW(0,context,"Error",16)
else
print(*context)
end if
end sub
sub RaiseErr(num as integer,Func as const wstring)
Select Case num
Case ERR_READ_FAILED
 Meesage(Emsg+"ERR_READ_FAILED(1)")
Case ERR_PARSE_ERR
 Meesage(Emsg+"ERR_PARSE_ERR(2)")
Case ERR_ARGU_TOO_LOT
 Meesage(Emsg+"ERR_ARGU_TOO_LOT(3)")
Case ERR_ARGU_TOO_LESS    
 Meesage(Emsg+"ERR_ARGU_TOO_LESS(4)")
Case ERR_NO_INSTRUCTION   
  Meesage(Emsg+"ERR_NO_INSTRUCTION(5)")
Case ERR_CANNOT_LOAD_DLL
  Meesage(Emsg+"ERR_CANNOT_LOAD_DLL(6)")
Case ERR_UNACCEPTABLE_IDENTIFIER
  Meesage(Emsg+"ERR_UNACCEPTABLE_IDENTIFIER(7)")
Case ERR_TYPE_NOT_DEFINED
  Meesage(Emsg+"ERR_TYPE_NOT_DEFINED(8)")
Case ERR_UNACCEPTABLE_TABLE
  Meesage(Emsg+"ERR_UNACCEPTABLE_TABLE(9)")
Case ERR_FUNCTION_WITHOUT_END
  Meesage(Emsg+"ERR_FUNCTION_WITHOUT_END(10)")
Case ERR_FUNCTION_WITHOUT_BEGIN
  Meesage(Emsg+"ERR_FUNCTION_WITHOUT_BEGIN(11)")
Case ERR_UNACCEPTABLE_RETURN_VALUE_OR_TYPE
  Meesage(Emsg+"ERR_UNACCEPTABLE_RETURN_VALUE_OR_TYPE(12)")
Case Else  
' still WIP ...
  Meesage(Emsg+"ERR_UNKNOWN(0)")

End Select

end sub
