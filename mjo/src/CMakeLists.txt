# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (CMakeLists.txt). 
# This work is published from: United States.
#
# This file is part of the mjo library.
#
# Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

target_sources(libmjo PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/closedir.c
  ${CMAKE_CURRENT_LIST_DIR}/mabort.c
  ${CMAKE_CURRENT_LIST_DIR}/madd.c
  ${CMAKE_CURRENT_LIST_DIR}/mbsearch.c
  ${CMAKE_CURRENT_LIST_DIR}/mbsearcu.c
  ${CMAKE_CURRENT_LIST_DIR}/mcalc.c
  ${CMAKE_CURRENT_LIST_DIR}/mcalloc.c
  ${CMAKE_CURRENT_LIST_DIR}/mcompare.c
  ${CMAKE_CURRENT_LIST_DIR}/mcompose.c
  ${CMAKE_CURRENT_LIST_DIR}/mfree.c
  ${CMAKE_CURRENT_LIST_DIR}/mmalloc.c
  ${CMAKE_CURRENT_LIST_DIR}/mmul.c
  ${CMAKE_CURRENT_LIST_DIR}/mpathf.c
  ${CMAKE_CURRENT_LIST_DIR}/mpathj.c
  ${CMAKE_CURRENT_LIST_DIR}/mpunct.c
  ${CMAKE_CURRENT_LIST_DIR}/mquote.c
  ${CMAKE_CURRENT_LIST_DIR}/mr7hash.c
  ${CMAKE_CURRENT_LIST_DIR}/mr7zero.c
  ${CMAKE_CURRENT_LIST_DIR}/mread.c
  ${CMAKE_CURRENT_LIST_DIR}/mrealloc.c
  ${CMAKE_CURRENT_LIST_DIR}/mshiftl.c
  ${CMAKE_CURRENT_LIST_DIR}/mshiftr.c
  ${CMAKE_CURRENT_LIST_DIR}/mspace.c
  ${CMAKE_CURRENT_LIST_DIR}/mstrchr.c
  ${CMAKE_CURRENT_LIST_DIR}/mstrdup.c
  ${CMAKE_CURRENT_LIST_DIR}/mtrim.c
  ${CMAKE_CURRENT_LIST_DIR}/mtriml.c
  ${CMAKE_CURRENT_LIST_DIR}/mtrimr.c
  ${CMAKE_CURRENT_LIST_DIR}/mvalid.c
  ${CMAKE_CURRENT_LIST_DIR}/opendir.c
  ${CMAKE_CURRENT_LIST_DIR}/readdir.c
)
