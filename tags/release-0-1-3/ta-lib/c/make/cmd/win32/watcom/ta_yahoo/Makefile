#############################################################################
# Makefile for building ta_yahoo
# Generated by tmake;
#     Project: ta_yahoo/ta_yahoo
#    Template: app
#############################################################################

####### Compiler, tools and options

CC	=	wcl386
CXX	=	wcl386
CFLAGS	=	-zq -w2 -d2 -d=TA_DEBUG -d=_DEBUG -d=WIN32
CXXFLAGS=	-zq -w2 -d2 -d=TA_DEBUG -d=_DEBUG -d=WIN32
INCPATH	=	-i="..\..\..\..\..\src\ta_common" -i="..\..\..\..\..\include" -i="..\..\..\..\..\src\ta_common\imatix\sfl"
LINK	=	wlink
LFLAGS	=	op quiet op c d all sys nt
LIBS	=	..\..\..\..\..\lib\ta_libc_cmd.lib wininet.lib odbc32.lib
MOC	=	moc

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\demo\ta_yahoo\ta_yahoo.c
OBJECTS =	..\..\..\..\..\temp\cmd\ta_yahoo\ta_yahoo.obj
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\bin\ta_yahoo.exe
TMPLIST =	ta_yahoo.lst

####### Build rules

all: $(TARGET)

$(TARGET): $(OBJECTS) $(OBJMOC) 
	@%create $(TMPLIST)
	@%append $(TMPLIST) NAME ta_yahoo
	@%append $(TMPLIST) FIL ..\..\..\..\..\temp\cmd\ta_yahoo\ta_yahoo.obj
	@%append $(TMPLIST) LIBR ..\..\..\..\..\lib\ta_libc_cmd.lib,wininet.lib,odbc32.lib
	$(LINK) $(LFLAGS) @$(TMPLIST)
	del $(TMPLIST)

moc: $(SRCMOC)

tmake: ../cmd/win32/watcom/ta_yahoo/Makefile

../cmd/win32/watcom/ta_yahoo/Makefile: ta_yahoo/ta_yahoo.pro
	tmake ta_yahoo/ta_yahoo.pro -o ../cmd/win32/watcom/ta_yahoo/Makefile

dist:
	$(ZIP) ta_yahoo/ta_yahoo.zip ta_yahoo/ta_yahoo.pro $(SOURCES) $(HEADERS) $(DIST)

clean:
	-del ..\..\..\..\..\temp\cmd\ta_yahoo\ta_yahoo.obj
	-del $(TARGET)
	-del ../../../../../bin/*.map
	-del ../../../../../bin/*._xe
	-del ../../../../../bin/*.tds
	-del ../../../../../bin/*.pdb
	-del ../../../../../bin/*.pbo
	-del ../../../../../bin/*.pbi
	-del ../../../../../bin/*.pbt
	-del ../../../../../temp/cmd/*.pch
	-del ../../../../../temp/cmd/*.idb
	-del ../../../../../temp/cmd/ta_yahoo/*.pch
	-del ../../../../../temp/cmd/ta_yahoo/*.idb
	-del ../../../../../temp/cmd/ta_yahoo/*.obj

####### Compile

..\..\..\..\..\temp\cmd\ta_yahoo\ta_yahoo.obj: ..\..\..\..\..\src\demo\ta_yahoo\ta_yahoo.c
	$(CC) -c $(CFLAGS) $(INCPATH) -fo=..\..\..\..\..\temp\cmd\ta_yahoo\ta_yahoo.obj ..\..\..\..\..\src\demo\ta_yahoo\ta_yahoo.c

