#############################################################################
# Makefile for building ../../../../../lib/libta_pm_cmr.a
# Generated by tmake;
#     Project: ta_pm/ta_pm
#    Template: lib
#############################################################################

####### Compiler, tools and options

CC	=	gcc
CXX	=	g++
CFLAGS	=	-pipe -Wall -W -O2 -fno-strict-aliasing -D_REENTRANT -DQT_THREAD_SUPPORT
CXXFLAGS=	-pipe -Wall -W -O2 -fno-strict-aliasing -D_REENTRANT -DQT_THREAD_SUPPORT
INCPATH	=	-I../../../../../src/ta_common -I../../../../../src/ta_pm -I../../../../../src/ta_common/imatix/sfl -I../../../../../src/ta_common/kazlib -I../../../../../include
AR	=	ar cqs
RANLIB	=	
MOC	=	$(QTDIR)/bin/moc
UIC	=	$(QTDIR)/bin/uic

TAR	=	tar -cf
GZIP	=	gzip -9f

####### Files

HEADERS =	
SOURCES =	../../../../../src/ta_pm/ta_pm.c \
		../../../../../src/ta_pm/ta_pmvalue.c \
		../../../../../src/ta_pm/ta_pmarray.c \
		../../../../../src/ta_pm/ta_pmreport.c \
		../../../../../src/ta_pm/ta_pmstring.c \
		../../../../../src/ta_pm/ta_datalog.c \
		../../../../../src/ta_pm/ta_instrument.c
OBJECTS =	../../../../../temp/cmr/ta_pm.o \
		../../../../../temp/cmr/ta_pmvalue.o \
		../../../../../temp/cmr/ta_pmarray.o \
		../../../../../temp/cmr/ta_pmreport.o \
		../../../../../temp/cmr/ta_pmstring.o \
		../../../../../temp/cmr/ta_datalog.o \
		../../../../../temp/cmr/ta_instrument.o
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	../../../../../lib/libta_pm_cmr.a
INTERFACE_DECL_PATH = .

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules


all: $(TARGET)

staticlib: $(TARGET)

$(TARGET): $(UICDECLS) $(OBJECTS) $(OBJMOC) 
	-rm -f $(TARGET)
	$(AR) $(TARGET) $(OBJECTS) $(OBJMOC)

moc: $(SRCMOC)

clean:
	-rm -f $(OBJECTS) $(OBJMOC) $(SRCMOC) $(UICIMPLS) $(UICDECLS) $(TARGET)
	-rm -f *~ core

####### Sub-libraries


###### Combined headers


####### Compile

../../../../../temp/cmr/ta_pm.o: ../../../../../src/ta_pm/ta_pm.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_pm.o ../../../../../src/ta_pm/ta_pm.c

../../../../../temp/cmr/ta_pmvalue.o: ../../../../../src/ta_pm/ta_pmvalue.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_pmvalue.o ../../../../../src/ta_pm/ta_pmvalue.c

../../../../../temp/cmr/ta_pmarray.o: ../../../../../src/ta_pm/ta_pmarray.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_pmarray.o ../../../../../src/ta_pm/ta_pmarray.c

../../../../../temp/cmr/ta_pmreport.o: ../../../../../src/ta_pm/ta_pmreport.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_pmreport.o ../../../../../src/ta_pm/ta_pmreport.c

../../../../../temp/cmr/ta_pmstring.o: ../../../../../src/ta_pm/ta_pmstring.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_pmstring.o ../../../../../src/ta_pm/ta_pmstring.c

../../../../../temp/cmr/ta_datalog.o: ../../../../../src/ta_pm/ta_datalog.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_datalog.o ../../../../../src/ta_pm/ta_datalog.c

../../../../../temp/cmr/ta_instrument.o: ../../../../../src/ta_pm/ta_instrument.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o ../../../../../temp/cmr/ta_instrument.o ../../../../../src/ta_pm/ta_instrument.c

