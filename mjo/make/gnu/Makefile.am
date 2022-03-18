# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Dante University Foundation and
# Contributors has waived all copyright and related or neighboring
# rights to this file (Makefile.am). This work is published from:
# United States.
#
# Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#
level=$(srcdir)/../../

AUTOMAKE_OPTIONS = subdir-objects no-dependencies

lib_LIBRARIES = libmjo.a

libmjo_a_CPPFLAGS = -I ${level}/include

libmjo_a_SOURCES = \
	${level}/src/closedir.c \
	${level}/src/mabort.c \
	${level}/src/madd.c \
	${level}/src/mbsearch.c \
	${level}/src/mbsearcu.c \
	${level}/src/mcalc.c \
	${level}/src/mcalloc.c \
	${level}/src/mcompare.c \
	${level}/src/mcompose.c \
	${level}/src/mfree.c \
	${level}/src/mmalloc.c \
	${level}/src/mmul.c \
	${level}/src/mpathf.c \
	${level}/src/mpathj.c \
	${level}/src/mpunct.c \
	${level}/src/mquote.c \
	${level}/src/mr7hash.c \
	${level}/src/mr7zero.c \
	${level}/src/mread.c \
	${level}/src/mrealloc.c \
	${level}/src/mshiftl.c \
	${level}/src/mshiftr.c \
	${level}/src/mspace.c \
	${level}/src/mstrchr.c \
	${level}/src/mstrdup.c \
	${level}/src/mtrim.c \
	${level}/src/mtriml.c \
	${level}/src/mtrimr.c \
	${level}/src/mvalid.c \
	${level}/src/opendir.c \
	${level}/src/readdir.c 

include_HEADERS = \
	$(level)/include/mdirect.h \
	$(level)/include/mfcntl.h \
	$(level)/include/mr7.h \
	$(level)/include/mstddef.h \
	$(level)/include/mstdio.h \
	$(level)/include/mstdlib.h \
	$(level)/include/mstring.h \
	$(level)//include/msysstat.h \
	$(level)/include/mu8.h \
	$(level)/include/munistd.h \
	$(level)/include/mutf8.h \
	$(level)/include/mxywh.h 

dist_man_MANS = \
	${level}/man3/mjo_add_size_t.3 \
	${level}/man3/mjo_utf8_compose.3 \
	${level}/man3/mjo_u8_trim.3 \
	${level}/man3/mjo_search_binary.3 \
	${level}/man3/mjo_mul_size_t.3 \
	${level}/man3/mjo_path_full.3 \
	${level}/man3/mjo_r7_hash.3 \
	${level}/man3/mjo_path_join.3 \
	${level}/man3/mjo_malloc.3 \
	${level}/man3/mjo_read.3 \
	${level}/man3/mjo_utf8_is_whitespace.3 \
	${level}/man3/mjo_utf8_is_punctuation.3 \
	${level}/man3/mjo_utf8_is_quote.3 \
	${level}/man3/mjo_u8_calc.3 \
	${level}/man3/mjo_u8_validate.3 \
	${level}/man3/mjo_abort.3 \
	${level}/man7/mr7.h.7 \
	${level}/man7/mfcntl.h.7 \
	${level}/man7/mstdio.h.7 \
	${level}/man7/mutf8.h.7 \
	${level}/man7/mxywh.h.7 \
	${level}/man7/munistd.h.7 \
	${level}/man7/mstdlib.h.7 \
	${level}/man7/mstddef.h.7 \
	${level}/man7/mu8.h.7 \
	${level}/man7/msysstat.h.7 \
	${level}/man7/mdirect.h.7 
