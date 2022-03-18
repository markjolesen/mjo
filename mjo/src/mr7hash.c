/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mr7hash.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mstdlib.h"
/**/
#include "mr7.h"
#include "sdbm_mix.h"

static void
  _mjo_mr7_hash(size_t *const o_hash,
                void const *i_block,
                size_t const i_octets)
{
  size_t l_slot;
  unsigned char const *l_tail;

  l_tail = (unsigned char const *)i_block;

  for (l_slot = 0; i_octets > l_slot; l_slot++, l_tail++)
    {
      *o_hash = sdbm_mix(*l_tail, *o_hash);
    }

  return;
}

extern int
  mjo_r7_hash(size_t *const o_hash, void const *i_block, size_t const i_octets)
{
  int l_rc;
  size_t l_slot;
  unsigned char const *l_tail;

  do
    {
      if (0 == o_hash)
        {
          l_rc = MJO_FAIL;
          errno = EINVAL;
          break;
        }

      l_rc = MJO_OK;
      *o_hash = 0;

      if (0 == i_block)
        {
          break;
        }

      _mjo_mr7_hash(o_hash, i_block, i_octets);
    }
  while (0);

  return l_rc;
}
