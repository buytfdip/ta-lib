#############################################################################
# Makefile for building gen_data
# Generated by tmake;
#     Project: gen_data/gen_data
#    Template: app
#############################################################################

####### Compiler, tools and options

CC	=	cl
CXX	=	cl
CFLAGS	=	-nologo -W3 -Zi -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
CXXFLAGS=	-nologo -W3 -Zi -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
INCPATH	=	-I"..\..\..\..\..\src\ta_common" -I"..\..\..\..\..\include"
LINK	=	link
LFLAGS	=	/NOLOGO /DEBUG /SUBSYSTEM:console
LIBS	=	..\..\..\..\..\lib\ta_libc_csd.lib wininet.lib
MOC	=	moc
UIC	=	uic

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\tools\gen_data\gen_data.c
OBJECTS =	..\..\..\..\..\temp\csd\gen_data.obj
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\bin\gen_data.exe
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

tmake: ../csd/win32/msvc/gen_data/Makefile

../csd/win32/msvc/gen_data/Makefile: gen_data/gen_data.pro
	tmake gen_data/gen_data.pro -o ../csd/win32/msvc/gen_data/Makefile

dist:
	$(ZIP) gen_data/gen_data.zip gen_data/gen_data.pro $(SOURCES) $(HEADERS) $(DIST) $(INTERFACES)

clean:
        -del ..\..\..\..\..\temp\csd\gen_data.obj
	-del $(TARGET)
	-del ../../../../../bin/*.map
	-del ../../../../../bin/*._xe
	-del ../../../../../bin/*.tds
	-del ../../../../../bin/*.pdb
	-del ../../../../../bin/*.pbo
	-del ../../../../../bin/*.pbi
	-del ../../../../../bin/*.pbt
	-del ../../../../../temp/csd/*.pch
	-del ../../../../../temp/csd/*.idb
	-del ../../../../../temp/csd/gen_data/*.pch
	-del ../../../../../temp/csd/gen_data/*.idb
	-del ../../../../../temp/csd/gen_data/*.obj
        -del gen_data.pdb
	-del vc*.pdb
	-del gen_data.ilk

####### Compile

..\..\..\..\..\temp\csd\gen_data.obj: ..\..\..\..\..\src\tools\gen_data\gen_data.c
	$(CC) -c $(CFLAGS) $(INCPATH) -Fo..\..\..\..\..\temp\csd\gen_data.obj ..\..\..\..\..\src\tools\gen_data\gen_data.c

