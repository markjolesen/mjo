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

install(FILES
  ${CMAKE_CURRENT_LIST_DIR}/mdirect.h
  ${CMAKE_CURRENT_LIST_DIR}/mfcntl.h
  ${CMAKE_CURRENT_LIST_DIR}/mr7.h
  ${CMAKE_CURRENT_LIST_DIR}/mstddef.h
  ${CMAKE_CURRENT_LIST_DIR}/mstdio.h
  ${CMAKE_CURRENT_LIST_DIR}/mstdlib.h
  ${CMAKE_CURRENT_LIST_DIR}/mstring.h
  ${CMAKE_CURRENT_LIST_DIR}/msysstat.h
  ${CMAKE_CURRENT_LIST_DIR}/mu8.h
  ${CMAKE_CURRENT_LIST_DIR}/munistd.h
  ${CMAKE_CURRENT_LIST_DIR}/mutf8.h
  ${CMAKE_CURRENT_LIST_DIR}/mxywh.h
  DESTINATION include/mjo)
