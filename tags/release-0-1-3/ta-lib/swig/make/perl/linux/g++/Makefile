# makefile for building a perl TA.pm module
# Handmade (experimental)
#
# Tested with SWIG v1.3.21

PERL5_VERSION=5.8.4
PERL5_INCLUDE=/usr/lib/perl/$(PERL5_VERSION)/CORE

TOPDIR=../../../..
WRAPDIR=$(TOPDIR)/temp/perl/wrap
TEMPDIR=$(TOPDIR)/temp/perl/wrap

CPPFLAGS   = -Dbool=char -D_REENTRANT -D_GNU_SOURCE \
	     -DTHREADS_HAVE_PIDS -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 \
	     -I$(PERL5_INCLUDE) \
	     -I$(TOPDIR)/../c/include
CFLAGS     = -pipe -Wall -Wno-unused -O2 -fpic -fno-strict-aliasing

CC         = gcc
LDFLAGS    = -shared
LDLIBS     = -lpthread -lcurl

all: $(TOPDIR)/lib/perl/TA.so $(TOPDIR)/lib/perl/Finance/TA.pm

clean:
	rm -f $(WRAPDIR)/*.c
	rm -f $(WRAPDIR)/*.pm
	rm -f $(TEMPDIR)/*.o

$(TOPDIR)/lib/perl/TA.so: \
		$(TEMPDIR)/ta_libc_wrap.o
	$(CC) $(LDFLAGS) -o $@ $< $(TOPDIR)/../c/lib/libta_libc_cmr.a $(LDLIBS)

$(TOPDIR)/lib/perl/Finance/TA.pm: \
		$(WRAPDIR)/TA.pm \
		$(TOPDIR)/src/interface/perl.pm
	perl -pe 's/^%(OWNER|ITERATORS)/our %\1/' $(WRAPDIR)/TA.pm >$@
	cat $(TOPDIR)/src/interface/perl.pm >>$@ 

$(WRAPDIR)/TA.pm $(WRAPDIR)/ta_libc_wrap.c: \
		$(TOPDIR)/src/interface/ta_libc.swg \
		$(TOPDIR)/src/interface/ta_func.swg
	swig -perl5 -proxy -Fstandard -o $(WRAPDIR)/ta_libc_wrap.c \
		-I$(TOPDIR)/src/interface -I$(TOPDIR)/../c/include \
		$<


.PHONY: all clean
