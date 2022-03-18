/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (rcincl.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mll.h"

extern int
  mjo_ll_read_include(enum mjo_status *const o_status,
                      mjo_vector_t *const io_vector,
                      mjo_lexer_t const io_lexer,
                      mjo_istream_t const io_stream)
{
  int l_rc;

  l_rc = mjo_ll_read_operand(o_status, io_vector, io_lexer, io_stream);

  return l_rc;
}
