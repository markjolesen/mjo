# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (CMakeLists.txt). 
# This work is published from: United States.
#
# This file is part of the mjo libraray.
#
# Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

cmake_minimum_required (VERSION 3.20.3)

project(libmjo)

option(BUILD_UTIL "build utilites" OFF)
option(BUILD_EXAMPLES "build examples" OFF)

if (NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX /usr)
endif()

add_library(libmjo STATIC)

set_target_properties(libmjo PROPERTIES OUTPUT_NAME mjo)

target_include_directories(libmjo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(include)
add_subdirectory(src)

if (BUILD_UTIL)
add_subdirectory(util)
endif()

if (BUILD_EXAMPLES)
add_subdirectory(examples)
endif()

install(TARGETS libmjo ARCHIVE)

install(FILES
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_add_size_t.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_utf8_compose.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_u8_trim.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_search_binary.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_mul_size_t.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_path_full.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_r7_hash.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_path_join.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_malloc.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_read.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_utf8_is_whitespace.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_utf8_is_punctuation.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_utf8_is_quote.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_u8_calc.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_u8_validate.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_abort.3
	DESTINATION share/man/man3)

install(FILES
	${CMAKE_CURRENT_LIST_DIR}/man7/mr7.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mfcntl.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mstdio.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mutf8.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mxywh.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/munistd.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mstdlib.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mstddef.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mu8.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/msysstat.h.7
	${CMAKE_CURRENT_LIST_DIR}/man7/mdirect.h.7
	DESTINATION share/man/man7)
