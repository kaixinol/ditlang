#include once "parser.bi"
dim dataset() as string
dim i as integer
dim FinNum as integer=split(dataset(),LoadFile("我草2.txt"),chr(13,10),)-1
print str(FinNum)
for i=0 to FinNum
print "["+str(i)+"]"+VBTAB+dataset(i)
next

ParseFunc(dataset(),FinNum)