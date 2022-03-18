/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstring.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mstring_h__)

#  include <string.h>
/**/
#  include <mr7.h>

extern void
  explicit_bzero(void *, size_t);

extern void
  mjo_r7_zero(void *const, size_t const);

#  define explicit_bzero(i_str, i_size) mjo_r7_zero((i_str), (i_size))

#  define __mstring_h__
#endif
