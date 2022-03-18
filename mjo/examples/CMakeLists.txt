# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (CMakeLists.txt). 
# This work is published from: United States.
#
# Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
# or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

cmake_minimum_required (VERSION 3.7)

project(examples)

add_executable(utf8_compose utf8_compose.c)

target_link_libraries(utf8_compose LINK_PRIVATE libmjo)

target_include_directories(utf8_compose PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(u8_validate u8_validate.c)

target_link_libraries(u8_validate LINK_PRIVATE libmjo)

target_include_directories(u8_validate PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(u8_trim u8_trim.c)

target_link_libraries(u8_trim LINK_PRIVATE libmjo)

target_include_directories(u8_trim PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(abort abort.c)

target_link_libraries(abort LINK_PRIVATE libmjo)

target_include_directories(abort PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(add add.c)

target_link_libraries(add LINK_PRIVATE libmjo)

target_include_directories(add PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(mul mul.c)

target_link_libraries(mul LINK_PRIVATE libmjo)

target_include_directories(mul PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(path_join path_join.c)

target_link_libraries(path_join LINK_PRIVATE libmjo)

target_include_directories(path_join PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(path_full path_full.c)

target_link_libraries(path_full LINK_PRIVATE libmjo)

target_include_directories(path_full PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)


