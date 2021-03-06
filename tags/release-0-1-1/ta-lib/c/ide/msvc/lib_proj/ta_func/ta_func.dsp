# Microsoft Developer Studio Project File - Name="ta_func" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ta_func - Win32 CDD Multithread DLL Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ta_func.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ta_func.mak" CFG="ta_func - Win32 CDD Multithread DLL Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ta_func - Win32 CDR Multithread DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 CMD Multithread Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 CSD Single Thread Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 CSR Single Thread Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 CMR Multithread Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 Profiling" (based on "Win32 (x86) Static Library")
!MESSAGE "ta_func - Win32 CDD Multithread DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ta_func - Win32 CDR Multithread DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ta_func___Win32_CDR_Multithread_DLL_Release"
# PROP BASE Intermediate_Dir "ta_func___Win32_CDR_Multithread_DLL_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\cdr\ta_func"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MD /W3 /WX /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cmr.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cdr.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 CMD Multithread Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ta_func___Win32_CMD_Multithread_Debug"
# PROP BASE Intermediate_Dir "ta_func___Win32_CMD_Multithread_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\cmd\ta_func"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /Zi /Od /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_DEBUG" /D "WIN32" /D "_DEBUG" /D "_MBCS" /YX /FD /GZ /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MTd /W3 /WX /Gm /Zi /Od /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_DEBUG" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "TA_FUNC_NO_RANGE_CHECK" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cmd.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cmd.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 CSD Single Thread Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ta_func___Win32_CSD_Single_Thread_Debug"
# PROP BASE Intermediate_Dir "ta_func___Win32_CSD_Single_Thread_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\csd\ta_func"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_DEBUG" /D "TA_SINGLE_THREAD" /D "WIN32" /D "_DEBUG" /D "_MBCS" /YX /FD /GZ /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /W3 /WX /Gm /GX /Zi /Od /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_DEBUG" /D "TA_SINGLE_THREAD" /D "WIN32" /D "_DEBUG" /D "_MBCS" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csd.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csd.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 CSR Single Thread Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ta_func___Win32_CSR_Single_Thread_Release"
# PROP BASE Intermediate_Dir "ta_func___Win32_CSR_Single_Thread_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\csr\ta_func"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O2 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_SINGLE_THREAD" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /W3 /WX /O2 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_SINGLE_THREAD" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csr.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csr.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 CMR Multithread Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ta_func___Win32_CMR_Multithread_Release0"
# PROP BASE Intermediate_Dir "ta_func___Win32_CMR_Multithread_Release0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\cmr\ta_func"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /WX /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cmr.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cmr.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 Profiling"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ta_func___Win32_Profiling"
# PROP BASE Intermediate_Dir "ta_func___Win32_Profiling"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ta_func___Win32_Profiling"
# PROP Intermediate_Dir "ta_func___Win32_Profiling"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O2 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_SINGLE_THREAD" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /W3 /WX /O2 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "TA_SINGLE_THREAD" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csr.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_csr.lib"

!ELSEIF  "$(CFG)" == "ta_func - Win32 CDD Multithread DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ta_func___Win32_CDD_Multithread_DLL_Debug"
# PROP BASE Intermediate_Dir "ta_func___Win32_CDD_Multithread_DLL_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\lib"
# PROP Intermediate_Dir "..\..\..\..\temp\cdd\ta_libc"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MDd /W3 /WX /O1 /I "..\..\..\..\include" /I "..\..\..\..\src\ta_common" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cdr.lib"
# ADD LIB32 /nologo /out:"..\..\..\..\lib\ta_func_cdd.lib"

!ENDIF 

# Begin Target

# Name "ta_func - Win32 CDR Multithread DLL Release"
# Name "ta_func - Win32 CMD Multithread Debug"
# Name "ta_func - Win32 CSD Single Thread Debug"
# Name "ta_func - Win32 CSR Single Thread Release"
# Name "ta_func - Win32 CMR Multithread Release"
# Name "ta_func - Win32 Profiling"
# Name "ta_func - Win32 CDD Multithread DLL Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_AD.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ADOSC.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ADX.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ADXR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_APO.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_AROON.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_AROONOSC.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ATR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_AVGPRICE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_BBANDS.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_CCI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_CORREL.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_DEMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_DX.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_EMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_DCPERIOD.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_DCPHASE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_PHASOR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_SINE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_TRENDLINE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_HT_TRENDMODE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_KAMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_LINEARREG.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_LINEARREG_ANGLE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_LINEARREG_INTERCEPT.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_LINEARREG_SLOPE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MACD.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MACDEXT.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MACDFIX.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MAMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MAX.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MEDPRICE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MFI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MIDPOINT.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MIDPRICE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MIN.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MINUS_DI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MINUS_DM.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_MOM.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_NVI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_OBV.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_PLUS_DI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_PLUS_DM.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_PPO.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_PVI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ROC.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ROCP.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ROCR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_ROCR100.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_RSI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_SAR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_SAREXT.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_SMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_STDDEV.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_STOCH.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_STOCHF.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_STOCHRSI.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_T3.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TEMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TRANGE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TRIMA.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TRIX.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TSF.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_TYPPRICE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_utility.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_VAR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_WCLPRICE.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_WILLR.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_WMA.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\src\ta_func\ta_utility.h
# End Source File
# End Group
# End Target
# End Project
