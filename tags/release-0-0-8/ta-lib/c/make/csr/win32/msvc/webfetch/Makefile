#############################################################################
# Makefile for building webfetch
# Generated by tmake;
#     Project: webfetch/webfetch
#    Template: app
#############################################################################

####### Compiler, tools and options

CC	=	cl
CXX	=	cl
CFLAGS	=	-nologo -W3 -O1 -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
CXXFLAGS=	-nologo -W3 -O1 -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
INCPATH	=	-I"..\..\..\..\..\src\ta_common" -I"..\..\..\..\..\include" -I"..\..\..\..\..\src\ta_common\imatix\sfl"
LINK	=	link
LFLAGS	=	/NOLOGO /SUBSYSTEM:console
LIBS	=	..\..\..\..\..\lib\ta_libc_csr.lib wininet.lib
MOC	=	moc
UIC	=	uic

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\demo\webfetch\webfetch.c
OBJECTS =	..\..\..\..\..\temp\csr\webfetch\webfetch.obj
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\bin\webfetch.exe
INTERFACE_DECL_PATH = .

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .c

.cpp.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -Fo$@ $<

.cxx.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -Fo$@ $<

.cc.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -Fo$@ $<

.c.obj:
	$(CC) -c $(CFLAGS) $(INCPATH) -Fo$@ $<

####### Build rules

all: $(TARGET)

$(TARGET): $(UICDECLS) $(OBJECTS) $(OBJMOC) 
	$(LINK) $(LFLAGS) /OUT:$(TARGET) @<<
	    $(OBJECTS) $(OBJMOC) $(LIBS)
<<

moc: $(SRCMOC)

tmake: ../csr/win32/msvc/webfetch/Makefile

../csr/win32/msvc/webfetch/Makefile: webfetch/webfetch.pro
	tmake webfetch/webfetch.pro -o ../csr/win32/msvc/webfetch/Makefile

dist:
	$(ZIP) webfetch/webfetch.zip webfetch/webfetch.pro $(SOURCES) $(HEADERS) $(DIST) $(INTERFACES)

clean:
        -del ..\..\..\..\..\temp\csr\webfetch\webfetch.obj
	-del $(TARGET)
	-del ../../../../../bin/*.map
	-del ../../../../../bin/*._xe
	-del ../../../../../bin/*.tds
	-del ../../../../../bin/*.pdb
	-del ../../../../../bin/*.pbo
	-del ../../../../../bin/*.pbi
	-del ../../../../../bin/*.pbt
	-del ../../../../../temp/csr/*.pch
	-del ../../../../../temp/csr/*.idb
	-del ../../../../../temp/csr/webfetch/*.pch
	-del ../../../../../temp/csr/webfetch/*.idb
	-del ../../../../../temp/csr/webfetch/*.obj

####### Compile

..\..\..\..\..\temp\csr\webfetch\webfetch.obj: ..\..\..\..\..\src\demo\webfetch\webfetch.c
	$(CC) -c $(CFLAGS) $(INCPATH) -Fo..\..\..\..\..\temp\csr\webfetch\webfetch.obj ..\..\..\..\..\src\demo\webfetch\webfetch.c

