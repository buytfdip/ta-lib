#############################################################################
# Makefile for building ta_sql
# Generated by tmake;
#     Project: ta_sql/ta_sql
#    Template: app
#############################################################################

####### Compiler, tools and options

CC	=	cl
CXX	=	cl
CFLAGS	=	-nologo -W3 -Zi -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
CXXFLAGS=	-nologo -W3 -Zi -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32 -D_MBCS -D_LIB
INCPATH	=	-I"..\..\..\..\..\src\ta_common" -I"..\..\..\..\..\include" -I"..\..\..\..\..\src\ta_common\imatix\sfl"
LINK	=	link
LFLAGS	=	/NOLOGO /DEBUG /SUBSYSTEM:console
LIBS	=	..\..\..\..\..\lib\ta_libc_csd.lib wininet.lib odbc32.lib odbccp32.lib
MOC	=	moc
UIC	=	uic

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\demo\ta_sql\ta_sql.c
OBJECTS =	..\..\..\..\..\temp\csd\ta_sql\ta_sql.obj
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\bin\ta_sql.exe
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

tmake: ../csd/win32/msvc/ta_sql/Makefile

../csd/win32/msvc/ta_sql/Makefile: ta_sql/ta_sql.pro
	tmake ta_sql/ta_sql.pro -o ../csd/win32/msvc/ta_sql/Makefile

dist:
	$(ZIP) ta_sql/ta_sql.zip ta_sql/ta_sql.pro $(SOURCES) $(HEADERS) $(DIST) $(INTERFACES)

clean:
        -del ..\..\..\..\..\temp\csd\ta_sql\ta_sql.obj
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
	-del ../../../../../temp/csd/ta_sql/*.pch
	-del ../../../../../temp/csd/ta_sql/*.idb
	-del ../../../../../temp/csd/ta_sql/*.obj
        -del ta_sql.pdb
	-del vc*.pdb
	-del ta_sql.ilk

####### Compile

..\..\..\..\..\temp\csd\ta_sql\ta_sql.obj: ..\..\..\..\..\src\demo\ta_sql\ta_sql.c
	$(CC) -c $(CFLAGS) $(INCPATH) -Fo..\..\..\..\..\temp\csd\ta_sql\ta_sql.obj ..\..\..\..\..\src\demo\ta_sql\ta_sql.c

