# Do not modify this file. It is automatically
# generated by make_pro.pl

TEMPLATE  = lib
CONFIG   -= qt
CONFIG   += staticlib

# Identify the temp dir
cmd:OBJECTS_DIR = ../../../../../temp/cmd
cmr:OBJECTS_DIR = ../../../../../temp/cmr
csd:OBJECTS_DIR = ../../../../../temp/csd
csr:OBJECTS_DIR = ../../../../../temp/csr

# Identify the target
LIBTARGET = ta_abstract
cmd:TARGET = ta_abstract_cmd
cmr:TARGET = ta_abstract_cmr
csd:TARGET = ta_abstract_csd
csr:TARGET = ta_abstract_csr

# Output info
DESTDIR     = ../../../../../lib

# Files to process
SOURCES	= ../../../../../src/ta_abstract/ta_abstract.c \ 
          ../../../../../src/ta_abstract/ta_def_ui.c \ 
          ../../../../../src/ta_abstract/ta_group_idx.c \ 
          ../../../../../src/ta_abstract/tables/table_a.c \ 
          ../../../../../src/ta_abstract/tables/table_b.c \ 
          ../../../../../src/ta_abstract/tables/table_c.c \ 
          ../../../../../src/ta_abstract/tables/table_d.c \ 
          ../../../../../src/ta_abstract/tables/table_e.c \ 
          ../../../../../src/ta_abstract/tables/table_f.c \ 
          ../../../../../src/ta_abstract/tables/table_g.c \ 
          ../../../../../src/ta_abstract/tables/table_h.c \ 
          ../../../../../src/ta_abstract/tables/table_i.c \ 
          ../../../../../src/ta_abstract/tables/table_j.c \ 
          ../../../../../src/ta_abstract/tables/table_k.c \ 
          ../../../../../src/ta_abstract/tables/table_l.c \ 
          ../../../../../src/ta_abstract/tables/table_m.c \ 
          ../../../../../src/ta_abstract/tables/table_n.c \ 
          ../../../../../src/ta_abstract/tables/table_o.c \ 
          ../../../../../src/ta_abstract/tables/table_p.c \ 
          ../../../../../src/ta_abstract/tables/table_q.c \ 
          ../../../../../src/ta_abstract/tables/table_r.c \ 
          ../../../../../src/ta_abstract/tables/table_s.c \ 
          ../../../../../src/ta_abstract/tables/table_t.c \ 
          ../../../../../src/ta_abstract/tables/table_u.c \ 
          ../../../../../src/ta_abstract/tables/table_v.c \ 
          ../../../../../src/ta_abstract/tables/table_w.c \ 
          ../../../../../src/ta_abstract/tables/table_x.c \ 
          ../../../../../src/ta_abstract/tables/table_y.c \ 
          ../../../../../src/ta_abstract/tables/table_z.c \ 
          ../../../../../src/ta_abstract/frames/ta_MAX_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MIN_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_BBANDS_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_DEMA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_EMA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_SAR_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_SMA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_TEMA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_WMA_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_APO_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MACD_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MACDFIX_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_PPO_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_RSI_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_ATR_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_TRANGE_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_CCI_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MOM_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_ROC_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_ROCR_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_STOCH_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_TRIX_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_OBV_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_STDDEV_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_VAR_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_MEDPRICE_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_TYPPRICE_frame.c \ 
          ../../../../../src/ta_abstract/frames/ta_WCLPRICE_frame.c 
# Compiler Options
INCLUDEPATH = ../../../../../src/ta_common \ 
              ../../../../../src/ta_abstract \ 
              ../../../../../src/ta_abstract/tables \ 
              ../../../../../src/ta_abstract/frames \ 
              ../../../../../include \ 

# debug/release dependent options.
debug:DEFINES   *= TA_DEBUG
debug:DEFINES   *= _DEBUG
DEFINES        += TA_SINGLE_THREAD
thread:DEFINES -= TA_SINGLE_THREAD

# Platform dependent options.
win32:DEFINES         *= WIN32
win32-msvc:DEFINES    *= _MBCS _LIB

cmd:TEMP_CLEAN_ALL = ../../../../../temp/cmd/*.pch
cmr:TEMP_CLEAN_ALL = ../../../../../temp/cmr/*.pch
csd:TEMP_CLEAN_ALL = ../../../../../temp/csd/*.pch
csr:TEMP_CLEAN_ALL = ../../../../../temp/csr/*.pch

cmd:TEMP_CLEAN_ALL2 = ../../../../../temp/cmd/*.idb
cmr:TEMP_CLEAN_ALL2 = ../../../../../temp/cmr/*.idb
csd:TEMP_CLEAN_ALL2 = ../../../../../temp/csd/*.idb
csr:TEMP_CLEAN_ALL2 = ../../../../../temp/csr/*.idb

cmd:TEMP_CLEAN_ALL3 = ../../../../../temp/cmd/$$LIBTARGET/*.pch
cmr:TEMP_CLEAN_ALL3 = ../../../../../temp/cmr/$$LIBTARGET/*.pch
csd:TEMP_CLEAN_ALL3 = ../../../../../temp/csd/$$LIBTARGET/*.pch
csr:TEMP_CLEAN_ALL3 = ../../../../../temp/csr/$$LIBTARGET/*.pch

cmd:TEMP_CLEAN_ALL4 = ../../../../../temp/cmd/$$LIBTARGET/*.idb
cmr:TEMP_CLEAN_ALL4 = ../../../../../temp/cmr/$$LIBTARGET/*.idb
csd:TEMP_CLEAN_ALL4 = ../../../../../temp/csd/$$LIBTARGET/*.idb
csr:TEMP_CLEAN_ALL4 = ../../../../../temp/csr/$$LIBTARGET/*.idb

cmd:TEMP_CLEAN_ALL5 = ../../../../../temp/cmd/$$LIBTARGET/*.obj
cmr:TEMP_CLEAN_ALL5 = ../../../../../temp/cmr/$$LIBTARGET/*.obj
csd:TEMP_CLEAN_ALL5 = ../../../../../temp/csd/$$LIBTARGET/*.obj
csr:TEMP_CLEAN_ALL5 = ../../../../../temp/csr/$$LIBTARGET/*.obj

win32:CLEAN_FILES = ../../../../../bin/*.map ../../../../../bin/*._xe ../../../../../bin/*.tds ../../../../../bin/*.pdb ../../../../../bin/*.pbo ../../../../../bin/*.pbi ../../../../../bin/*.pbt $$TEMP_CLEAN_ALL $$TEMP_CLEAN_ALL2 $$TEMP_CLEAN_ALL3 $$TEMP_CLEAN_ALL4 $$TEMP_CLEAN_ALL5
