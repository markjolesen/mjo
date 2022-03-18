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

lib_LIBRARIES = libmjoextra.a

libmjoextra_a_CPPFLAGS = \
	-I ${level}/../mjo/include \
	-I ${level}/include \
	-I ${level}/arg/include \
	-I ${level}/arg/src/lexer/include \
	-I ${level}/arg/src/ll/include \
	-I ${level}/istream/include \
	-I ${level}/vector/include

libmjoextra_a_SOURCES = \
	${level}/istream/src/sfree.c \
	${level}/istream/src/sblknew.c \
	${level}/istream/src/sfilenew.c \
	${level}/istream/src/spush.c \
	${level}/istream/src/sread.c \
	${level}/src/rdcsv.c \
	${level}/src/str.c \
	${level}/src/rdline.c \
	${level}/vector/src/vgrow.c \
	${level}/vector/src/vperpush.c \
	${level}/vector/src/vpush.c \
	${level}/vector/src/vdequeue.c \
	${level}/vector/src/vpop.c \
	${level}/vector/src/vnew.c \
	${level}/vector/src/vclear.c \
	${level}/vector/src/vvarfree.c \
	${level}/vector/src/vtype.c \
	${level}/vector/src/vfree.c \
	${level}/vector/src/vshiftl.c \
	${level}/vector/src/vshiftr.c \
	${level}/vector/src/vtag.c \
	${level}/vector/src/vcount.c \
	${level}/arg/src/new.c \
	${level}/arg/src/tostr.c \
	${level}/arg/src/parblock.c \
	${level}/arg/src/_push.c \
	${level}/arg/src/_rd.c \
	${level}/arg/src/value.c \
	${level}/arg/src/_parshrt.c \
	${level}/arg/src/option.c \
	${level}/arg/src/lexer/src/_rdstm.c \
	${level}/arg/src/lexer/src/_rdesc.c \
	${level}/arg/src/lexer/src/lexpush.c \
	${level}/arg/src/lexer/src/lexnew.c \
	${level}/arg/src/lexer/src/lexread.c \
	${level}/arg/src/lexer/src/lexfree.c \
	${level}/arg/src/_parlong.c \
	${level}/arg/src/free.c \
	${level}/arg/src/_lookup.c \
	${level}/arg/src/print.c \
	${level}/arg/src/_optval.c \
	${level}/arg/src/parfile.c \
	${level}/arg/src/parse.c \
	${level}/arg/src/tointern.c \
	${level}/arg/src/parvec.c \
	${level}/arg/src/_missing.c \
	${level}/arg/src/vecnew.c \
	${level}/arg/src/_parincl.c \
	${level}/arg/src/ll/src/rdlong.c \
	${level}/arg/src/ll/src/rdop.c \
	${level}/arg/src/ll/src/rdshort.c \
	${level}/arg/src/ll/src/scansep.c \
	${level}/arg/src/ll/src/rdarg.c \
	${level}/arg/src/ll/src/acquiesc.c \
	${level}/arg/src/ll/src/scansp.c \
	${level}/arg/src/ll/src/rdincl.c \
	${level}/arg/src/_parop.c 

include_HEADERS = \
	${level}/istream/include/mistream.h \
	${level}/include/mstr.h \
	${level}/include/mread.h \
	${level}/vector/include/mvector.h \
	${level}/arg/include/marg.h

dist_man_MANS = \
	${level}/man3/mjo_vector_count.3 \
	${level}/man3/mjo_vector_variant_tag.3 \
	${level}/man3/mjo_istream_read.3 \
	${level}/man3/mjo_arg_option.3 \
	${level}/man3/mjo_vector_dequeue.3 \
	${level}/man3/mjo_vector_clear.3 \
	${level}/man3/mjo_arg_print.3 \
	${level}/man3/mjo_vector_pop.3 \
	${level}/man3/mjo_vector_malloc.3 \
	${level}/man3/mjo_arg_parse.3 \
	${level}/man3/mjo_istream_malloc.3 \
	${level}/man3/mjo_arg_value.3 \
	${level}/man3/mjo_istream_push.3 \
	${level}/man3/mjo_vector_type.3 \
	${level}/man3/mjo_vector_permute_push.3 \
	${level}/man3/mjo_vector_push.3 \
	${level}/man3/mjo_arg_malloc.3
