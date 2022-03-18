/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (acquiesce.c)
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
/**/
#include <mlexer.h>

#include "mll.h"

static int
  _mjo_ll_acquiesce(enum mjo_status *const o_status,
                    mjo_lexer_t const io_lexer,
                    mjo_istream_t const io_stream)
{
  int l_action;
  int l_rc;
  struct mjo_lexer_token l_token;

  do
    {
      l_rc = mjo_lexer_read(o_status, &l_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if (mjo_lexer_class_whitespace != l_token.m_class)
        {
          l_rc = mjo_ll_scan_whitespace(
            o_status, io_lexer, io_stream, mjo_ll_action_scan_to_whitespace);
        }
      else
        {
          mjo_lexer_push(io_lexer, &l_token);
        }
    }
  while (0);

  return l_rc;
}

extern void
  mjo_ll_acquiesce(mjo_lexer_t const io_lexer, mjo_istream_t const io_stream)
{
  enum mjo_status l_status;

  if (io_lexer && io_stream)
    {
      _mjo_ll_acquiesce(&l_status, io_lexer, io_stream);
    }

  return;
}
