#############################################################################
# Makefile for building webfetch
# Generated by tmake;
#     Project: webfetch/webfetch
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
LIBS	=	..\..\..\..\..\lib\ta_libc_cmd.lib wininet.lib
MOC	=	moc

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\demo\webfetch\webfetch.c
OBJECTS =	..\..\..\..\..\temp\cmd\webfetch\webfetch.obj
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\bin\webfetch.exe
TMPLIST =	webfetch.lst

####### Build rules

all: $(TARGET)

$(TARGET): $(OBJECTS) $(OBJMOC) 
	@%create $(TMPLIST)
	@%append $(TMPLIST) NAME webfetch
	@%append $(TMPLIST) FIL ..\..\..\..\..\temp\cmd\webfetch\webfetch.obj
	@%append $(TMPLIST) LIBR ..\..\..\..\..\lib\ta_libc_cmd.lib,wininet.lib
	$(LINK) $(LFLAGS) @$(TMPLIST)
	del $(TMPLIST)

moc: $(SRCMOC)

tmake: ../cmd/win32/watcom/webfetch/Makefile

../cmd/win32/watcom/webfetch/Makefile: webfetch/webfetch.pro
	tmake webfetch/webfetch.pro -o ../cmd/win32/watcom/webfetch/Makefile

dist:
	$(ZIP) webfetch/webfetch.zip webfetch/webfetch.pro $(SOURCES) $(HEADERS) $(DIST)

clean:
	-del ..\..\..\..\..\temp\cmd\webfetch\webfetch.obj
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
	-del ../../../../../temp/cmd/webfetch/*.pch
	-del ../../../../../temp/cmd/webfetch/*.idb
	-del ../../../../../temp/cmd/webfetch/*.obj

####### Compile

..\..\..\..\..\temp\cmd\webfetch\webfetch.obj: ..\..\..\..\..\src\demo\webfetch\webfetch.c
	$(CC) -c $(CFLAGS) $(INCPATH) -fo=..\..\..\..\..\temp\cmd\webfetch\webfetch.obj ..\..\..\..\..\src\demo\webfetch\webfetch.c

