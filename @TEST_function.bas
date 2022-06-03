#define UNICODE
#include "Function.bi"
dim a as ScriptFunction
with a
REdim .ParametersType(1 to 2)
.PassParameterType=mutable_parameter
.ParametersType(1)=DOUBLE_TYPE
.ParametersType(2)=DOUBLE_TYPE
.begin=1
.end=10
.Location=DLL			
.name=new string("teist")
end with
dim fx as FunctionTable
'fx.Add(a)
if fx.dataset.useddata<>0 then
if *fx.find("teist")->name="teist" then
print "gret!"
else
print "not found!"
endif
else
print "EMPTY!"
endif