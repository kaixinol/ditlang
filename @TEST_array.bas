#define UNICODE                 
#lang "FB"                      
#include "Array.inc"
    Dim b as FBArray
	b.init
	dim ss as string ptr=New String("1")
   b.add(0,Type<vardata>(ss, OTHER))
    dim s2 as string ptr=New String("2")
   b.add(1,Type<vardata>(s2, OTHER))
    dim s3 as string ptr=New String("3")
   b.add(2,Type<vardata>(s3, OTHER))
    dim sChao as string ptr=New String("chaos")
   b.add(0,Type<vardata>(sChao, OTHER))
  print ("FACT"+*b.getdata(1).vstring)
  print ("FACT"+*b.getdata(2).vstring)
  print ("FACT"+*b.getdata(3).vstring)
  print ("FACT"+*b.getdata(4).vstring)
  b.del 1
  Print "---------------DEL THE chaos-------------"
  Print ("FACT"+*b.getdata(1).vstring)
  b.del 2
  Print "---------------DEL THE 2-------------"                                        
  Print ("FACT"+*b.getdata(2).vstring)
  Print "USED:"+str(B.UsedData)
    Print "---------------Destroy-------------" 
  b.Destroy  
  Print "---------------Check if memory leak-------------"
   print ("NEXT ADDESS"+str(b.getdata(1).varray))
   print ("NEXT ADDESS"+str(b.getdata(2).varray))
   print ("NEXT ADDESS"+str(b.getdata(3).varray))
   print ("NEXT ADDESS"+str(b.getdata(4).varray))       
getkey