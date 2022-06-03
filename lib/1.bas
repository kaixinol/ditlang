 extern "C" Lib "expansion"
Declare function split(arr as zstring ptr ptr, str as zstring ptr,del as const zstring ptr)as zstring ptr
Declare function te_interp(expression as const zstring ptr, error as integer ptr)as double
End Extern
'dim a as zstring ptr ptr
'a=callocate(10,sizeof(zstring ptr))

'dim st as zstring ptr
'st=allocate(len("hello|fghfgh"))
' *st="hello|fghfgh"
'split(a,st,"|")
'deallocate a[1]
'print *a[1]

dim  as zstring *4 t1=>"9+6"
print str(te_interp(t1,0))