#DEFINE __ARRAY_USED__
#ifndef __VARDATA__
#include once "VarData.bi"
#endif
Type FBArray
' **Public**
Declare sub Init()
Declare sub Add(begin As UInteger=0,data_ As vardata)
Declare sub Del(num As uinteger)
Declare Sub Destroy()
Declare function GetData(num As uinteger) As vardata
UsedData As uinteger
' **private:**
Declare Function Derefer(ref As vardata ptr,COUNT As integer=-1)As VarData PTR
InnerDatas As vardata ptr
End type

 Function FBArray.Derefer(ref As vardata ptr,COUNT As Integer=-1)As VarData PTR
Return IIf(COUNT=0 Or ref->VArray=null,ref,Derefer(ref->VArray,count-1))
 End function
 
Sub FBArray.Add(begin As UInteger=0,data_ As vardata)
 DIM NEXT_PTR As vardata Ptr=derefer(innerdatas,begin+1)
dim dts as VarData Ptr=New VarData(data_)
dts->VArray=iif(NEXT_PTR=derefer(innerdatas,begin),NULL,NEXT_PTR)
 derefer(innerdatas,begin)->VArray=dts
#IFDEF DBG
Print "dts PTR "+STR(dts)+"  "+str(dts->VArray)
#endif
UsedData             += 1
End sub

Function  FBArray.GetData(num As uinteger) As vardata
return *Derefer(InnerDatas,NUM)
End FUNCTION

 Sub fbarray.Del(num As uinteger)
Dim DST AS vardata Ptr =derefer(innerdatas,num)->VArray
Dim org as vardata Ptr =derefer(innerdatas,num)
derefer(innerdatas,num-1)->VArray=DST
Delete org->vstring
Delete org
useddata-=1
End sub
Sub FBArray.Destroy()
  For i As Integer=0 to useddata
 Delete derefer(innerdatas,useddata-i)->vstring
 Delete derefer(innerdatas,useddata-i)
#IFDEF DBG                             
Print "  @"+Str(useddata-i)+Chr(13,10)
#endif
 next
INNERDATAS->VArray=NULL
Delete INNERDATAS
UsedData=0
End sub
Sub FBArray.Init()
InnerDatas=New vardata
End sub
