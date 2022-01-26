'下面内容由 VisualFreeBasic 5.7.1 自动产生，请勿自己修改
'[VFB_PROJECT_SETUP_START]
'NumObjects=1
'ProjectName=@TEST_debug
'CompilationMode=0
'CompilationDebug=0
'FunNameNumber=0
'CharSet=1
'CodePage=936
'ProjectType=GUI
'UseGDIPlus=0
'ShowConsole=0
'MultiLanguage=0
'OmitInformation=0
'StartupIcon=
'UseWinXPthemes=1
'StrUnicode=0
'UseAdminPriv=0
'DeleteGeneratedCode=0
'Namespace=0
'AddCompOps=
'LastRunFilename=@TEST_debug
'ImageManager=
'Major=0
'Minor=0
'Revision=0
'Build=0
'FileMajor=0
'FileMinor=0
'FileRevision=0
'FileBuild=2
'AutoIncrement=3
'DefaultCompiler=32
'Comments=
'CompanyName=
'FileDescription=
'LegalCopyrights=
'LegalTrademarks=
'ProductName=

'Module=.\@TEST_debug.bas|0|0||Yes|
'TopTab=.\@TEST_debug.bas|True|0|231
'[VFB_PROJECT_SETUP_END]
 'VFB函数库插入的位置(全部小写,在引用必要的基础库之后),这是让BAS工程支持使用VFB里的源码库和私库文件等,去掉后就无法支持。
#define UNICODE
#include "debug.inc"
PrintDbg "hello!"
LogDbg "hello","HELLO_TEST"
LogDbg "I'm better now.","HELLO_TEST"
LogDbg "Supertest","Super_TEST"
