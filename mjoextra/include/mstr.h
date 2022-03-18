/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstr.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mstr_h__)

#  include <stddef.h>

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern int
    mjo_str_to_bool(int *const o_bool, unsigned char const *i_str);

  extern int
    mjo_str_to_double(double *const o_double, unsigned char const *i_str);

  extern int
    mjo_str_to_ptrdiff_t(ptrdiff_t *const o_ptrdiff,
                         unsigned char const *i_str);

  extern int
    mjo_str_to_short(short *const o_short, unsigned char const *i_str);

  extern int
    mjo_str_to_ushort(unsigned short *const o_short,
                      unsigned char const *i_str);

  extern int
    mjo_str_to_int(int *const o_int, unsigned char const *i_str);

  extern int
    mjo_str_to_uint(unsigned int *const o_int, unsigned char const *i_str);

  extern int
    mjo_str_to_long(long *const o_long, unsigned char const *i_str);

  extern int
    mjo_str_to_ulong(unsigned long *const o_long, unsigned char const *i_str);

  extern int
    mjo_str_to_size_t(size_t *const o_size, unsigned char const *i_str);

#  if defined(__cplusplus)
}
#  endif

#  define __mstr_h__
#endif
