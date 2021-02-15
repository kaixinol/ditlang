sub ShowErrorMsg(ErrCode as DWORD = GETLASTERROR()) 'ErrMSG
   '&H00A1 变量类型不匹配
   '&H00A2 变量空间满
   '&H00A3 语法错误
   
   const as string H00A1 ="变量类型不匹配"
   const as string H00A2 = "变量空间满"
   const as string H00A3= "语法错误"
   const as string H00A4= "I/O脚本错误"
   const as string H00A5= "预处理脚本时意料之外的错误"
   const as string H00FF= "程序崩溃"
   Select case ErrCode
      Case &H00A1
         MsgBox ___, "ErrCode:" + str(&H00A1) + vbcrlf + H00A1 + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Run-Time Error", 16
      Case &H00A2
         MsgBox ___, "ErrCode:" + str(&H00A2) + vbcrlf + H00A2 + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Run-Time Error", 16
      Case &H00A3
         MsgBox ___, "ErrCode:" + str(&H00A3) + vbcrlf + H00A3 + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Run-Time Error", 16
      Case &H00A4
         MsgBox ___, "ErrCode:" + str(&H00A4) + vbcrlf + H00A4 + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Run-Time Error", 16
      Case &H00A5
         MsgBox ___, "ErrCode:" + str(&H00A5) + vbcrlf + H00A5 + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Run-Time Error", 16
      case else
         MsgBox ___, "ErrCode:" + str(&H00FF) + vbcrlf + H00FF + VBCRLF + "GetLastError=" + STR(getlasterror), App.EXEName + ":Dust Collapsed", 16
   End Select
   
End Sub



