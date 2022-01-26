sub Array.Init(byval num As short)
   ReDim This.place(1 To num)
   This.used(1) = num '*** Set total value.
End sub
Sub Array.Push(argv As VarData)
   Dim tmp as Short
   For tmp = 1 To used(1)
      If This.place(tmp) = NULL then
         This.place(tmp) = New VarData(argv)
         This.used(0) += 1
         Exit sub
      End If
   next
   
End sub
Sub Array.Pop()
   Dim tmp as Short
   
   For tmp = 1 To used(0)
      
      If This.place(tmp) <> NULL then
         
         Delete( *This.place(tmp)).vstring
         
         Delete This.place(tmp)
         
         This.place(tmp) = null
      End If
      
   next
   
End Sub