/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (lexfree.c). 
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
  mjo_lexer_mem_free(mjo_lexer_t *const io_lexer,
                     char const *i_fn,
                     size_t const i_ln)
{
  if (io_lexer && *io_lexer)
    {
      explicit_bzero((*io_lexer), sizeof(**io_lexer));
      mjo_mem_free((void **const)io_lexer, i_fn, i_ln);
      (*io_lexer) = 0;
    }

  return;
}
