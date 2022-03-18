/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mcompare.c).
 This work is published from: United States.

 This file is part of the mjo library.

 Ful text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <string.h>
/**/
#include "mutf8.h"

extern void
  mjo_utf8_compare(int *const o_result,
                   struct mjo_utf8 const *const i_find,
                   struct mjo_utf8 const *const i_compare)
{
  (*o_result)
    = strcmp((char const *)i_find->m_block, (char const *)i_compare->m_block);

  return;
}
