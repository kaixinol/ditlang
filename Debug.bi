#include Once "windows.bi"
Function CurrentTime() As String 
Dim st As  SYSTEMTIME
GetLocalTime @st
CurrentTime = st.wHour & ":" & st.wMinute & ":" & st.wSecond & "." & st.wMilliseconds
End Function
Sub PrintDbg(text As String)
Print "[Dbg]"+Chr(9)+text
end sub
sub LogDbg(text as string,test_name as string)
Print "[Dbg]"+Chr(9)+text

dim ff as integer=freefile

open "DBG-"+test_name+".log" For Append As #ff
Print #ff, CurrentTime+Chr(9,9)+"|"+text
close #ff

End Sub
