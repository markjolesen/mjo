/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mutf8.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mutf8_h__)

#  include <mstddef.h>
#  include <mstdio.h>

enum
{
  mjo_utf8_max_octets = 6,
  mjo_utf8_replacement = 0xefbfbd
};

struct mjo_utf8
{
  int m_legal;
  uint8_t m_block[mjo_utf8_max_octets];
  unsigned int m_nil;
  size_t m_octets;
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_utf8_compare(int *const,
                     struct mjo_utf8 const *const,
                     struct mjo_utf8 const *const);

  extern void
    mjo_utf8_compose(enum mjo_status *const o_status,
                     unsigned char const **o_tail,
                     struct mjo_utf8 *const o_peek,
                     unsigned char const *i_head);

  extern int
    mjo_utf8_is_punctuation(int *const, struct mjo_utf8 const *const);

  extern int
    mjo_utf8_is_quote(int *const, struct mjo_utf8 const *const);

  extern int
    mjo_utf8_is_whitespace(int *const, struct mjo_utf8 const *const);

  extern unsigned char *
    mjo_utf8_strchr(unsigned char const *, struct mjo_utf8 const *const);

#  if defined(__cplusplus)
}
#  endif

#  define __mutf8_h__
#endif
