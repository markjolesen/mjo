/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mcompose.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstring.h>

#include "mu8.h"
#include "mutf8.h"

static void
  _mjo_utf8_compose(enum mjo_status *const o_status,
                    unsigned char const **o_tail,
                    struct mjo_utf8 *const o_peek,
                    unsigned char const *i_head)
{
  unsigned char const *l_tail;
  size_t l_octets;

  l_tail = i_head;

  do
    {
      if (0 == *l_tail)
        {
          *o_status = mjo_status_eof;
          break;
        }

      mjo_u8_calc(&o_peek->m_legal, &l_octets, *l_tail);

      o_peek->m_block[0] = *l_tail;
      o_peek->m_octets = 1;

      if (0 == o_peek->m_legal)
        {
          *o_status = mjo_status_invalid;
          break;
        }

      do
        {
          l_tail++;

          if (l_octets == o_peek->m_octets)
            {
              *o_status = mjo_status_ok;
              break;
            }

          if (0 == *l_tail)
            {
              o_peek->m_legal = 0;
              *o_status = mjo_status_truncated;
              break;
            }

          mjo_u8_validate_nth_sequence(&o_peek->m_legal, *l_tail);

          if (0 == o_peek->m_legal)
            {
              *o_status = mjo_status_invalid;
              break;
            }

          o_peek->m_block[o_peek->m_octets++] = *l_tail;
        }
      while (1);
    }
  while (0);

  *o_tail = l_tail;

  return;
}

extern void
  mjo_utf8_compose(enum mjo_status *const o_status,
                   unsigned char const **o_tail,
                   struct mjo_utf8 *const o_peek,
                   unsigned char const *i_head)
{
  unsigned char const *l_tail;
  enum mjo_status l_status;

  l_tail = (unsigned char *)i_head;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == o_peek)
        {
          break;
        }

      explicit_bzero(o_peek, sizeof(*o_peek));

      if (0 == i_head)
        {
          break;
        }

      _mjo_utf8_compose(&l_status, &l_tail, o_peek, i_head);
    }
  while (0);

  if (o_status)
    {
      (*o_status) = l_status;
    }

  if (o_tail)
    {
      (*o_tail) = l_tail;
    }

  return;
}
