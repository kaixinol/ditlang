#define DBG
#include once "Array.bi"

'Pass Type
enum 
mutable_parameter=0, 	'可变参数
no_parameter,			'无参数
immutable_parameter		'不可变参数
end enum
'Parameters Type
enum 
INT_TYPE=5,
STR_TYPE,
DOUBLE_TYPE,
PTR_TYPE
end enum
'Location
enum 
INNER,
SCRIPT
end enum

type ScriptFunction
 PassParameterType  as integer 'see Pass Type
 ParametersType(any) as integer'see Parameters Type
 begin as uinteger
 end as uinteger
 Location as integer			'see Location
 name as string ptr
End type

type FunctionTable
Declare Sub Add(obj as  ScriptFunction)
Declare function Find(its_name as string)as ScriptFunction ptr
dataset as FBarray
End type

Sub FunctionTable.Add(obj as ScriptFunction)
static Inited as integer=0
if Inited=0 then
dataset.init
Inited=1
endif
dataset.add(,type<vardata>(0,OTHER,new ScriptFunction(obj)))
END sub
function FunctionTable.find(its_name as string)as ScriptFunction ptr
if dataset.useddata=0 then  return 0 

dim i as integer
for i=-1 to dataset.UsedData
if *cast(ScriptFunction ptr,dataset.getdata(i).vptr)->name=its_name then
return dataset.getdata(i).vptr
endif
next 
return 0
END function