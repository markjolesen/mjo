/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mu8.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mu8_h__)

#  include <stddef.h>

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_u8_calc(int *const, size_t *const, unsigned char const);

  extern void
    mjo_u8_trim(unsigned char *const);

  extern void
    mjo_u8_trim_left(unsigned char *const);

  extern void
    mjo_u8_trim_right(unsigned char *const);

  extern void
    mjo_u8_validate(int *const, unsigned char **const, unsigned char const *);

  extern void
    mjo_u8_validate_nth_sequence(int *const, unsigned char const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_u8_validate_nth_sequence(o_legal, i_octet)                      \
    do                                                                        \
      {                                                                       \
        *(o_legal) = ((0x2 == ((0xff & (i_octet)) >> 6)));                    \
      }                                                                       \
    while (0)

#  define __mu8_h__
#endif
