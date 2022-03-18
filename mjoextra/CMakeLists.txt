# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (CMakeLists.txt). 
# This work is published from: United States.
#
# This file is part of the mjoextra libraray.
#
# Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

cmake_minimum_required (VERSION 3.20.3)

project(libmjoextra)

if (NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX /usr)
endif()

add_library(libmjoextra STATIC)

set_target_properties(libmjoextra PROPERTIES OUTPUT_NAME mjoextra)

target_include_directories(libmjoextra
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../mjo/include
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/arg/include
    ${CMAKE_CURRENT_LIST_DIR}/arg/src/lexer/include
    ${CMAKE_CURRENT_LIST_DIR}/arg/src/ll/include
    ${CMAKE_CURRENT_LIST_DIR}/istream/include
    ${CMAKE_CURRENT_LIST_DIR}/vector/include)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(istream)
add_subdirectory(vector)
add_subdirectory(arg)

install(TARGETS libmjoextra ARCHIVE)

install(FILES
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_count.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_variant_tag.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_istream_read.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_arg_option.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_dequeue.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_clear.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_arg_print.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_pop.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_malloc.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_arg_parse.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_istream_malloc.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_arg_value.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_istream_push.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_type.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_permute_push.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_vector_push.3
	${CMAKE_CURRENT_LIST_DIR}/man3/mjo_arg_malloc.3
	DESTINATION share/man/man3)
