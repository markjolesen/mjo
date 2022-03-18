/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstddef.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mstddef_h__)

#  include <sys/types.h>

#  include <stddef.h>
#  include <stdint.h>

#  if defined(_MSC_VER)
typedef signed ssize_t;
#  endif

#  define __mstddef_h__
#endif
