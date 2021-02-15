function _Val_VO_VAR (byval _data as Var_NoName)as Variable'**Var_NoName     -> Variable
   dim tp as short
   if _data. _data_integer <> nullint then
      tp=INT_V
   elseif _data. _data_decimal <> nulldec then
      tp=SINGLE_V
   elseif _data. _data_string <> nullstr then
      tp=STR_V
   End If
  RETURN  CreateVar("^Initialized_NoName_Var^",Create_NoNameVar(_data._data_integer,_data._data_string,_data._data_decimal),TP)
   End Function
function _Val_VO_INT (byval _data as Var_NoName)as integer'**Var_NoName   -> integer
   if _data. _data_integer <> nullint then
 return _data. _data_integer
 elseif _data. _data_decimal <> nulldec then
ShowErrorMsg &H00A1
 elseif _data. _data_string <> nullstr then
 ShowErrorMsg &H00A1
 ELSEif _data. _data_integer = nullint then
 ShowErrorMsg &H00A1
 End If
End Function
function _Val_VO_STR (byval _data as Var_NoName)as string'**Var_NoName    -> string
      if _data. _data_integer <> nullint then
ShowErrorMsg &H00A1
 elseif _data. _data_decimal <> nulldec then
ShowErrorMsg &H00A1
 elseif _data. _data_string <> nullstr then
return _data. _data_string
 ELSEif _data. _data_string = nullstr then
ShowErrorMsg &H00A1
 End If
End Function
function _Val_VO_DOU (byval _data_ as Var_NoName)as double'**Var_NoName    -> double
if _data_. _data_integer <> nullint then
ShowErrorMsg &H00A1
 elseif _data_. _data_decimal <> nulldec then
return _data_. _data_decimal
 elseif _data_. _data_string <> nullstr then
ShowErrorMsg &H00A1
 ELSEif _data_. _data_decimal = nulldec then
ShowErrorMsg &H00A1
 End If
End Function
function _Val_VAR_INT (byval _data_ as Variable)as integer'**Variable          -> integer
   if _data_. _data_integer <> nullint then
return _data_._data_integer
 elseif _data_. _data_decimal <> nulldec then
ShowErrorMsg &H00A1
 elseif _data_. _data_string <> nullstr then
ShowErrorMsg &H00A1
 ELSEif _data_. _data_integer = nullint then
ShowErrorMsg &H00A1
 End If
End Function
function _Val_VAR_STR (byval _data_ as Variable)as string'**Variable        -> string
   if _data_. _data_integer <> nullint then
    ShowErrorMsg &H00A1
 elseif _data_. _data_decimal <> nulldec then
ShowErrorMsg &H00A1
 elseif _data_. _data_string <> nullstr then
return _data_._data_string
 ELSEif _data_. _data_integer = nullint then
ShowErrorMsg &H00A1
 End If
End Function
function _Val_VAR_DOU (byval _data_ as Variable)as double'**Variable        -> double
if _data_. _data_decimal <> nulldec then
return _data_._data_decimal
 elseif _data_. _data_integer <> nullint then
ShowErrorMsg &H00A1
 elseif _data_. _data_string <> nullstr then
ShowErrorMsg &H00A1
 ELSEif _data_. _data_decimal = nulldec then
ShowErrorMsg &H00A1
 End If
End Function
function _Val_VAR_VO(byval _data_ as Variable)as Var_NoName '**Variable           -> Var_NoName
 return  Create_NoNameVar(_data_._data_integer,_data_._data_string,_data_._data_decimal)
End Function
Sub CreateVar Overload(ByVal name_ As String, ByVal data_ As Var_NoName, ByVal Type_ As short , 变量空间() As Variable) '**创建变量
   name_ = Right(name_, Len(name_) -1)
   Dim l As short
   for L = 0 TO UBound(变量空间)
      IF CHECKVAR(变量空间(L)) = False Then
         变量空间(L). _type = Type_
         变量空间(L). _data_decimal = data_. _data_decimal
         变量空间(L). _data_integer = data_. _data_integer
         变量空间(L). _data_string = data_. _data_string
         变量空间(L). _name = name_
         #if __debug = "on"
         Printa "[代码行" + str( __LINE__) + "] 已经成功创建名为" + name_ + "的变量的值，在第" + Str(L) + "个位置存储"
         #endif
         Exit FOR
      End If
   Next
End Sub
Function CreateVar Overload(ByVal name_ As String, ByVal data_ As Var_NoName, ByVal Type_ As short) As Variable '**创建变量，并返回
   name_ = Right(name_, Len(name_) -1)
   Dim temp As Variable
   temp. _type = Type_
   temp. _data_decimal = data_. _data_decimal
   temp. _data_integer = data_. _data_integer
   temp. _data_string = data_. _data_string
   temp. _name = name_
   Return temp
   
End function
Function Create_NoNameVar(ByVal Int_ As Integer = UV._data_integer, ByVal String_ As string =UV._data_string, ByVal Double_ As double = UV._data_decimal) as Var_NoName  '**创建无名数据
   Dim T As Var_NoName
   T. _data_decimal = Double_
   T. _data_integer = Int_
   T. _data_string = String_
   Return T
End Function
Function GetVar overload(varname As String, 变量空间() As Variable) As Variable   '**用于获取变量
      Dim l As short
   for L = 1 TO UBound(变量空间)
      IF 变量空间(L)._name = varname Then
         Return 变量空间(L)
   #if __debug = "on"
   Printa "[代码行" + str( __LINE__) + "] 已经成功获取名为" + varname+"的变量的值，在第" +Str(L)+"个"
   #endif       
      Exit FOR
      End If
   Next
End Function