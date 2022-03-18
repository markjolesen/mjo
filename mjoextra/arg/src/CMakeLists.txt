# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (CMakeLists.txt). 
# This work is published from: United States.
#
# This file is part of the mjo_extra library.
#
# Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

target_include_directories(libmjoextra PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/lexer/include
	${CMAKE_CURRENT_LIST_DIR}/ll/include)

add_subdirectory(lexer)
add_subdirectory(ll)

target_sources(libmjoextra PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/_lookup.c
  ${CMAKE_CURRENT_LIST_DIR}/_missing.c
  ${CMAKE_CURRENT_LIST_DIR}/_optval.c
  ${CMAKE_CURRENT_LIST_DIR}/_parincl.c
  ${CMAKE_CURRENT_LIST_DIR}/_parlong.c
  ${CMAKE_CURRENT_LIST_DIR}/_parop.c
  ${CMAKE_CURRENT_LIST_DIR}/_parshrt.c
  ${CMAKE_CURRENT_LIST_DIR}/_push.c
  ${CMAKE_CURRENT_LIST_DIR}/_rd.c
  ${CMAKE_CURRENT_LIST_DIR}/free.c
  ${CMAKE_CURRENT_LIST_DIR}/new.c
  ${CMAKE_CURRENT_LIST_DIR}/option.c
  ${CMAKE_CURRENT_LIST_DIR}/parblock.c
  ${CMAKE_CURRENT_LIST_DIR}/parfile.c
  ${CMAKE_CURRENT_LIST_DIR}/parse.c
  ${CMAKE_CURRENT_LIST_DIR}/parvec.c
  ${CMAKE_CURRENT_LIST_DIR}/print.c
  ${CMAKE_CURRENT_LIST_DIR}/tointern.c
  ${CMAKE_CURRENT_LIST_DIR}/tostr.c
  ${CMAKE_CURRENT_LIST_DIR}/value.c
  ${CMAKE_CURRENT_LIST_DIR}/vecnew.c)
