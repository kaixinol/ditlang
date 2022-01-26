#include Once "vbcompat.bi"     
#Include Once "crt/stdio.bi"
sub HandleFile(path as string)as string ptr
dim theline as uinteger
Dim Shared Line_Data() As String
'get total line & load datas.
Dim f As const Integer = FreeFile
Open path For Binary As #f
TheLine = Split(Input(LOF(1), #1),fbcrlf, Line_Data())
Close #f
'--------------------------------------------------------

end sub 
