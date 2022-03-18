/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (lexpush.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_lexer.h"

extern void
  mjo_lexer_push(mjo_lexer_t const io_lexer,
                 struct mjo_lexer_token const *const i_token)
{
  memcpy(&io_lexer->m_queue, i_token, sizeof(*i_token));

  return;
}
