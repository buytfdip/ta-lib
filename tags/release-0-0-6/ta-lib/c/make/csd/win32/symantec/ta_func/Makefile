#############################################################################
# Makefile for building ta_func_csd
# Generated by tmake;
#     Project: ta_func/ta_func
#    Template: lib
#############################################################################

####### Compiler, tools and options

CC	=	sc
CXX	=	sc
CFLAGS	=	-mn -w2 -g -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32
CXXFLAGS=	-mn -w2 -g -DTA_DEBUG -D_DEBUG -DTA_SINGLE_THREAD -DWIN32
INCPATH	=	-I"..\..\..\..\..\src\ta_common" -I"\n" -I"..\..\..\..\..\include"
LIB	=	lib /C /N /NOI /P:32
MOC	=	moc

ZIP	=	zip -r -9

####### Files

HEADERS =	
SOURCES =	..\..\..\..\..\src\ta_func\ta_utility.c \
		..\..\..\..\..\src\ta_func\ta_MAX.c \
		..\..\..\..\..\src\ta_func\ta_MIN.c \
		..\..\..\..\..\src\ta_func\ta_BBANDS.c \
		..\..\..\..\..\src\ta_func\ta_DEMA.c \
		..\..\..\..\..\src\ta_func\ta_EMA.c \
		..\..\..\..\..\src\ta_func\ta_MA.c \
		..\..\..\..\..\src\ta_func\ta_SAR.c \
		..\..\..\..\..\src\ta_func\ta_SMA.c \
		..\..\..\..\..\src\ta_func\ta_TEMA.c \
		..\..\..\..\..\src\ta_func\ta_WMA.c \
		..\..\..\..\..\src\ta_func\ta_ADX.c \
		..\..\..\..\..\src\ta_func\ta_ADXR.c \
		..\..\..\..\..\src\ta_func\ta_APO.c \
		..\..\..\..\..\src\ta_func\ta_DX.c \
		..\..\..\..\..\src\ta_func\ta_MACD.c \
		..\..\..\..\..\src\ta_func\ta_MACDFIX.c \
		..\..\..\..\..\src\ta_func\ta_MINUS_DI.c \
		..\..\..\..\..\src\ta_func\ta_MINUS_DM.c \
		..\..\..\..\..\src\ta_func\ta_PPO.c \
		..\..\..\..\..\src\ta_func\ta_PLUS_DI.c \
		..\..\..\..\..\src\ta_func\ta_PLUS_DM.c \
		..\..\..\..\..\src\ta_func\ta_RSI.c \
		..\..\..\..\..\src\ta_func\ta_ATR.c \
		..\..\..\..\..\src\ta_func\ta_TRANGE.c \
		..\..\..\..\..\src\ta_func\ta_CCI.c \
		..\..\..\..\..\src\ta_func\ta_MOM.c \
		..\..\..\..\..\src\ta_func\ta_ROC.c \
		..\..\..\..\..\src\ta_func\ta_ROCR.c \
		..\..\..\..\..\src\ta_func\ta_STOCH.c \
		..\..\..\..\..\src\ta_func\ta_TRIX.c \
		..\..\..\..\..\src\ta_func\ta_OBV.c \
		..\..\..\..\..\src\ta_func\ta_STDDEV.c \
		..\..\..\..\..\src\ta_func\ta_VAR.c \
		..\..\..\..\..\src\ta_func\ta_MEDPRICE.c \
		..\..\..\..\..\src\ta_func\ta_TYPPRICE.c \
		..\..\..\..\..\src\ta_func\ta_WCLPRICE.c
OBJECTS =	..\..\..\..\..\temp\csd\ta_utility.obj \
		..\..\..\..\..\temp\csd\ta_MAX.obj \
		..\..\..\..\..\temp\csd\ta_MIN.obj \
		..\..\..\..\..\temp\csd\ta_BBANDS.obj \
		..\..\..\..\..\temp\csd\ta_DEMA.obj \
		..\..\..\..\..\temp\csd\ta_EMA.obj \
		..\..\..\..\..\temp\csd\ta_MA.obj \
		..\..\..\..\..\temp\csd\ta_SAR.obj \
		..\..\..\..\..\temp\csd\ta_SMA.obj \
		..\..\..\..\..\temp\csd\ta_TEMA.obj \
		..\..\..\..\..\temp\csd\ta_WMA.obj \
		..\..\..\..\..\temp\csd\ta_ADX.obj \
		..\..\..\..\..\temp\csd\ta_ADXR.obj \
		..\..\..\..\..\temp\csd\ta_APO.obj \
		..\..\..\..\..\temp\csd\ta_DX.obj \
		..\..\..\..\..\temp\csd\ta_MACD.obj \
		..\..\..\..\..\temp\csd\ta_MACDFIX.obj \
		..\..\..\..\..\temp\csd\ta_MINUS_DI.obj \
		..\..\..\..\..\temp\csd\ta_MINUS_DM.obj \
		..\..\..\..\..\temp\csd\ta_PPO.obj \
		..\..\..\..\..\temp\csd\ta_PLUS_DI.obj \
		..\..\..\..\..\temp\csd\ta_PLUS_DM.obj \
		..\..\..\..\..\temp\csd\ta_RSI.obj \
		..\..\..\..\..\temp\csd\ta_ATR.obj \
		..\..\..\..\..\temp\csd\ta_TRANGE.obj \
		..\..\..\..\..\temp\csd\ta_CCI.obj \
		..\..\..\..\..\temp\csd\ta_MOM.obj \
		..\..\..\..\..\temp\csd\ta_ROC.obj \
		..\..\..\..\..\temp\csd\ta_ROCR.obj \
		..\..\..\..\..\temp\csd\ta_STOCH.obj \
		..\..\..\..\..\temp\csd\ta_TRIX.obj \
		..\..\..\..\..\temp\csd\ta_OBV.obj \
		..\..\..\..\..\temp\csd\ta_STDDEV.obj \
		..\..\..\..\..\temp\csd\ta_VAR.obj \
		..\..\..\..\..\temp\csd\ta_MEDPRICE.obj \
		..\..\..\..\..\temp\csd\ta_TYPPRICE.obj \
		..\..\..\..\..\temp\csd\ta_WCLPRICE.obj
SRCMOC	=	
OBJMOC	=	
DIST	=	
TARGET	=	..\..\..\..\..\lib\ta_func_csd.lib

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .c

.cpp.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o$@ $<

.cxx.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o$@ $<

.cc.obj:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o$@ $<

.c.obj:
	$(CC) -c $(CFLAGS) $(INCPATH) -o$@ $<

####### Build rules

all: $(TARGET)

$(TARGET): $(OBJECTS) $(OBJMOC) 
	-del $(TARGET)
	$(LIB) $(TARGET) ..\..\..\..\..\temp\csd\ta_utility.obj \
+..\..\..\..\..\temp\csd\ta_MAX.obj \
+..\..\..\..\..\temp\csd\ta_MIN.obj \
+..\..\..\..\..\temp\csd\ta_BBANDS.obj \
+..\..\..\..\..\temp\csd\ta_DEMA.obj \
+..\..\..\..\..\temp\csd\ta_EMA.obj \
+..\..\..\..\..\temp\csd\ta_MA.obj \
+..\..\..\..\..\temp\csd\ta_SAR.obj \
+..\..\..\..\..\temp\csd\ta_SMA.obj \
+..\..\..\..\..\temp\csd\ta_TEMA.obj \
+..\..\..\..\..\temp\csd\ta_WMA.obj \
+..\..\..\..\..\temp\csd\ta_ADX.obj \
+..\..\..\..\..\temp\csd\ta_ADXR.obj \
+..\..\..\..\..\temp\csd\ta_APO.obj \
+..\..\..\..\..\temp\csd\ta_DX.obj \
+..\..\..\..\..\temp\csd\ta_MACD.obj \
+..\..\..\..\..\temp\csd\ta_MACDFIX.obj \
+..\..\..\..\..\temp\csd\ta_MINUS_DI.obj \
+..\..\..\..\..\temp\csd\ta_MINUS_DM.obj \
+..\..\..\..\..\temp\csd\ta_PPO.obj \
+..\..\..\..\..\temp\csd\ta_PLUS_DI.obj \
+..\..\..\..\..\temp\csd\ta_PLUS_DM.obj \
+..\..\..\..\..\temp\csd\ta_RSI.obj \
+..\..\..\..\..\temp\csd\ta_ATR.obj \
+..\..\..\..\..\temp\csd\ta_TRANGE.obj \
+..\..\..\..\..\temp\csd\ta_CCI.obj \
+..\..\..\..\..\temp\csd\ta_MOM.obj \
+..\..\..\..\..\temp\csd\ta_ROC.obj \
+..\..\..\..\..\temp\csd\ta_ROCR.obj \
+..\..\..\..\..\temp\csd\ta_STOCH.obj \
+..\..\..\..\..\temp\csd\ta_TRIX.obj \
+..\..\..\..\..\temp\csd\ta_OBV.obj \
+..\..\..\..\..\temp\csd\ta_STDDEV.obj \
+..\..\..\..\..\temp\csd\ta_VAR.obj \
+..\..\..\..\..\temp\csd\ta_MEDPRICE.obj \
+..\..\..\..\..\temp\csd\ta_TYPPRICE.obj \
+..\..\..\..\..\temp\csd\ta_WCLPRICE.obj \
+,;

moc: $(SRCMOC)

tmake: ../csd/win32/symantec/ta_func/Makefile

../csd/win32/symantec/ta_func/Makefile: ta_func/ta_func.pro
	tmake ta_func/ta_func.pro -o ../csd/win32/symantec/ta_func/Makefile

dist:
	$(ZIP) ta_func/ta_func.zip ta_func/ta_func.pro $(SOURCES) $(HEADERS) $(DIST)

clean:
	-del ..\..\..\..\..\temp\csd\ta_utility.obj
	-del ..\..\..\..\..\temp\csd\ta_MAX.obj
	-del ..\..\..\..\..\temp\csd\ta_MIN.obj
	-del ..\..\..\..\..\temp\csd\ta_BBANDS.obj
	-del ..\..\..\..\..\temp\csd\ta_DEMA.obj
	-del ..\..\..\..\..\temp\csd\ta_EMA.obj
	-del ..\..\..\..\..\temp\csd\ta_MA.obj
	-del ..\..\..\..\..\temp\csd\ta_SAR.obj
	-del ..\..\..\..\..\temp\csd\ta_SMA.obj
	-del ..\..\..\..\..\temp\csd\ta_TEMA.obj
	-del ..\..\..\..\..\temp\csd\ta_WMA.obj
	-del ..\..\..\..\..\temp\csd\ta_ADX.obj
	-del ..\..\..\..\..\temp\csd\ta_ADXR.obj
	-del ..\..\..\..\..\temp\csd\ta_APO.obj
	-del ..\..\..\..\..\temp\csd\ta_DX.obj
	-del ..\..\..\..\..\temp\csd\ta_MACD.obj
	-del ..\..\..\..\..\temp\csd\ta_MACDFIX.obj
	-del ..\..\..\..\..\temp\csd\ta_MINUS_DI.obj
	-del ..\..\..\..\..\temp\csd\ta_MINUS_DM.obj
	-del ..\..\..\..\..\temp\csd\ta_PPO.obj
	-del ..\..\..\..\..\temp\csd\ta_PLUS_DI.obj
	-del ..\..\..\..\..\temp\csd\ta_PLUS_DM.obj
	-del ..\..\..\..\..\temp\csd\ta_RSI.obj
	-del ..\..\..\..\..\temp\csd\ta_ATR.obj
	-del ..\..\..\..\..\temp\csd\ta_TRANGE.obj
	-del ..\..\..\..\..\temp\csd\ta_CCI.obj
	-del ..\..\..\..\..\temp\csd\ta_MOM.obj
	-del ..\..\..\..\..\temp\csd\ta_ROC.obj
	-del ..\..\..\..\..\temp\csd\ta_ROCR.obj
	-del ..\..\..\..\..\temp\csd\ta_STOCH.obj
	-del ..\..\..\..\..\temp\csd\ta_TRIX.obj
	-del ..\..\..\..\..\temp\csd\ta_OBV.obj
	-del ..\..\..\..\..\temp\csd\ta_STDDEV.obj
	-del ..\..\..\..\..\temp\csd\ta_VAR.obj
	-del ..\..\..\..\..\temp\csd\ta_MEDPRICE.obj
	-del ..\..\..\..\..\temp\csd\ta_TYPPRICE.obj
	-del ..\..\..\..\..\temp\csd\ta_WCLPRICE.obj
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
	-del ../../../../../temp/csd/ta_func/*.pch
	-del ../../../../../temp/csd/ta_func/*.idb
	-del ../../../../../temp/csd/ta_func/*.obj

####### Compile

..\..\..\..\..\temp\csd\ta_utility.obj: ..\..\..\..\..\src\ta_func\ta_utility.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_utility.obj ..\..\..\..\..\src\ta_func\ta_utility.c

..\..\..\..\..\temp\csd\ta_MAX.obj: ..\..\..\..\..\src\ta_func\ta_MAX.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MAX.obj ..\..\..\..\..\src\ta_func\ta_MAX.c

..\..\..\..\..\temp\csd\ta_MIN.obj: ..\..\..\..\..\src\ta_func\ta_MIN.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MIN.obj ..\..\..\..\..\src\ta_func\ta_MIN.c

..\..\..\..\..\temp\csd\ta_BBANDS.obj: ..\..\..\..\..\src\ta_func\ta_BBANDS.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_BBANDS.obj ..\..\..\..\..\src\ta_func\ta_BBANDS.c

..\..\..\..\..\temp\csd\ta_DEMA.obj: ..\..\..\..\..\src\ta_func\ta_DEMA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_DEMA.obj ..\..\..\..\..\src\ta_func\ta_DEMA.c

..\..\..\..\..\temp\csd\ta_EMA.obj: ..\..\..\..\..\src\ta_func\ta_EMA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_EMA.obj ..\..\..\..\..\src\ta_func\ta_EMA.c

..\..\..\..\..\temp\csd\ta_MA.obj: ..\..\..\..\..\src\ta_func\ta_MA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MA.obj ..\..\..\..\..\src\ta_func\ta_MA.c

..\..\..\..\..\temp\csd\ta_SAR.obj: ..\..\..\..\..\src\ta_func\ta_SAR.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_SAR.obj ..\..\..\..\..\src\ta_func\ta_SAR.c

..\..\..\..\..\temp\csd\ta_SMA.obj: ..\..\..\..\..\src\ta_func\ta_SMA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_SMA.obj ..\..\..\..\..\src\ta_func\ta_SMA.c

..\..\..\..\..\temp\csd\ta_TEMA.obj: ..\..\..\..\..\src\ta_func\ta_TEMA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_TEMA.obj ..\..\..\..\..\src\ta_func\ta_TEMA.c

..\..\..\..\..\temp\csd\ta_WMA.obj: ..\..\..\..\..\src\ta_func\ta_WMA.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_WMA.obj ..\..\..\..\..\src\ta_func\ta_WMA.c

..\..\..\..\..\temp\csd\ta_ADX.obj: ..\..\..\..\..\src\ta_func\ta_ADX.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_ADX.obj ..\..\..\..\..\src\ta_func\ta_ADX.c

..\..\..\..\..\temp\csd\ta_ADXR.obj: ..\..\..\..\..\src\ta_func\ta_ADXR.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_ADXR.obj ..\..\..\..\..\src\ta_func\ta_ADXR.c

..\..\..\..\..\temp\csd\ta_APO.obj: ..\..\..\..\..\src\ta_func\ta_APO.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_APO.obj ..\..\..\..\..\src\ta_func\ta_APO.c

..\..\..\..\..\temp\csd\ta_DX.obj: ..\..\..\..\..\src\ta_func\ta_DX.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_DX.obj ..\..\..\..\..\src\ta_func\ta_DX.c

..\..\..\..\..\temp\csd\ta_MACD.obj: ..\..\..\..\..\src\ta_func\ta_MACD.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MACD.obj ..\..\..\..\..\src\ta_func\ta_MACD.c

..\..\..\..\..\temp\csd\ta_MACDFIX.obj: ..\..\..\..\..\src\ta_func\ta_MACDFIX.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MACDFIX.obj ..\..\..\..\..\src\ta_func\ta_MACDFIX.c

..\..\..\..\..\temp\csd\ta_MINUS_DI.obj: ..\..\..\..\..\src\ta_func\ta_MINUS_DI.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MINUS_DI.obj ..\..\..\..\..\src\ta_func\ta_MINUS_DI.c

..\..\..\..\..\temp\csd\ta_MINUS_DM.obj: ..\..\..\..\..\src\ta_func\ta_MINUS_DM.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MINUS_DM.obj ..\..\..\..\..\src\ta_func\ta_MINUS_DM.c

..\..\..\..\..\temp\csd\ta_PPO.obj: ..\..\..\..\..\src\ta_func\ta_PPO.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_PPO.obj ..\..\..\..\..\src\ta_func\ta_PPO.c

..\..\..\..\..\temp\csd\ta_PLUS_DI.obj: ..\..\..\..\..\src\ta_func\ta_PLUS_DI.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_PLUS_DI.obj ..\..\..\..\..\src\ta_func\ta_PLUS_DI.c

..\..\..\..\..\temp\csd\ta_PLUS_DM.obj: ..\..\..\..\..\src\ta_func\ta_PLUS_DM.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_PLUS_DM.obj ..\..\..\..\..\src\ta_func\ta_PLUS_DM.c

..\..\..\..\..\temp\csd\ta_RSI.obj: ..\..\..\..\..\src\ta_func\ta_RSI.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_RSI.obj ..\..\..\..\..\src\ta_func\ta_RSI.c

..\..\..\..\..\temp\csd\ta_ATR.obj: ..\..\..\..\..\src\ta_func\ta_ATR.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_ATR.obj ..\..\..\..\..\src\ta_func\ta_ATR.c

..\..\..\..\..\temp\csd\ta_TRANGE.obj: ..\..\..\..\..\src\ta_func\ta_TRANGE.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_TRANGE.obj ..\..\..\..\..\src\ta_func\ta_TRANGE.c

..\..\..\..\..\temp\csd\ta_CCI.obj: ..\..\..\..\..\src\ta_func\ta_CCI.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_CCI.obj ..\..\..\..\..\src\ta_func\ta_CCI.c

..\..\..\..\..\temp\csd\ta_MOM.obj: ..\..\..\..\..\src\ta_func\ta_MOM.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MOM.obj ..\..\..\..\..\src\ta_func\ta_MOM.c

..\..\..\..\..\temp\csd\ta_ROC.obj: ..\..\..\..\..\src\ta_func\ta_ROC.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_ROC.obj ..\..\..\..\..\src\ta_func\ta_ROC.c

..\..\..\..\..\temp\csd\ta_ROCR.obj: ..\..\..\..\..\src\ta_func\ta_ROCR.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_ROCR.obj ..\..\..\..\..\src\ta_func\ta_ROCR.c

..\..\..\..\..\temp\csd\ta_STOCH.obj: ..\..\..\..\..\src\ta_func\ta_STOCH.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_STOCH.obj ..\..\..\..\..\src\ta_func\ta_STOCH.c

..\..\..\..\..\temp\csd\ta_TRIX.obj: ..\..\..\..\..\src\ta_func\ta_TRIX.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_TRIX.obj ..\..\..\..\..\src\ta_func\ta_TRIX.c

..\..\..\..\..\temp\csd\ta_OBV.obj: ..\..\..\..\..\src\ta_func\ta_OBV.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_OBV.obj ..\..\..\..\..\src\ta_func\ta_OBV.c

..\..\..\..\..\temp\csd\ta_STDDEV.obj: ..\..\..\..\..\src\ta_func\ta_STDDEV.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_STDDEV.obj ..\..\..\..\..\src\ta_func\ta_STDDEV.c

..\..\..\..\..\temp\csd\ta_VAR.obj: ..\..\..\..\..\src\ta_func\ta_VAR.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_VAR.obj ..\..\..\..\..\src\ta_func\ta_VAR.c

..\..\..\..\..\temp\csd\ta_MEDPRICE.obj: ..\..\..\..\..\src\ta_func\ta_MEDPRICE.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_MEDPRICE.obj ..\..\..\..\..\src\ta_func\ta_MEDPRICE.c

..\..\..\..\..\temp\csd\ta_TYPPRICE.obj: ..\..\..\..\..\src\ta_func\ta_TYPPRICE.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_TYPPRICE.obj ..\..\..\..\..\src\ta_func\ta_TYPPRICE.c

..\..\..\..\..\temp\csd\ta_WCLPRICE.obj: ..\..\..\..\..\src\ta_func\ta_WCLPRICE.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o..\..\..\..\..\temp\csd\ta_WCLPRICE.obj ..\..\..\..\..\src\ta_func\ta_WCLPRICE.c

