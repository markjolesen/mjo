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

project(util)

find_package(ICU COMPONENTS uc i18n data REQUIRED)

add_executable(punct mjo_utf8_punct.cpp)

target_link_libraries(punct LINK_PRIVATE libmjo ICU::uc ICU::i18n ICU::data)

target_include_directories(punct PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(space mjo_utf8_space.cpp)

target_link_libraries(space LINK_PRIVATE libmjo ICU::uc ICU::i18n ICU::data)

target_include_directories(space PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(quote mjo_utf8_quote.cpp)

target_link_libraries(quote LINK_PRIVATE libmjo ICU::uc ICU::i18n ICU::data)

target_include_directories(quote PRIVATE 
  $<TARGET_PROPERTY:libmjo,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(tabgen mjo_utf8_tabgen.c)

target_link_libraries(tabgen LINK_PRIVATE libmjo)
