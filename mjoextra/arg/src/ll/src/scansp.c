/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (scanspace.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstdlib.h>
/**/
#include "mll.h"

extern int
  _mjo_ll_scan_whitespace(enum mjo_status *const o_status,
                          mjo_lexer_t const io_lexer,
                          mjo_istream_t const io_stream,
                          enum mjo_ll_action const i_action)
{
  int l_bool;
  int l_rc;
  int l_found;
  struct mjo_lexer_token l_token;

  *o_status = mjo_status_ok;

  l_rc = MJO_OK;
  l_found = 0;

  do
    {
      l_rc = mjo_lexer_read(o_status, &l_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      l_bool = (mjo_lexer_class_whitespace == l_token.m_class);

      if (l_bool && (mjo_ll_action_scan_to_whitespace == i_action))
        {
          l_found = 1;
        }
      else if ((0 == l_bool)
               && (mjo_ll_action_scan_to_non_whitespace == i_action))
        {
          l_found = 1;
        }

      if (l_found)
        {
          mjo_lexer_push(io_lexer, &l_token);
          break;
        }
    }
  while (1);

  return l_rc;
}

extern int
  mjo_ll_scan_whitespace(enum mjo_status *const o_status,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream,
                         enum mjo_ll_action const i_action)
{
  unsigned char l_found;
  int l_rc;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == io_lexer)
        {
          errno = EINVAL;
          break;
        }

      if (0 == io_stream)
        {
          errno = EINVAL;
          break;
        }

      l_rc = _mjo_ll_scan_whitespace(&l_status, io_lexer, io_stream, i_action);
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
