/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (scansep.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <string.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
/**/
#include "mll.h"

static void
  __mjo_ll_scan_separator(mjo_lexer_t const io_lexer,
                          mjo_istream_t const io_stream)
{
  int l_rc;
  struct mjo_lexer_token l_token;
  enum mjo_status l_status;

  do
    {
      l_rc = mjo_ll_scan_whitespace(
        &l_status, io_lexer, io_stream, mjo_ll_action_scan_to_non_whitespace);

      if (l_rc || l_status)
        {
          break;
        }

      l_rc = mjo_lexer_read(&l_status, &l_token, io_lexer, io_stream);

      if (l_rc || l_status)
        {
          break;
        }

      if (mjo_lexer_class_separator != l_token.m_class)
        {
          mjo_lexer_push(io_lexer, &l_token);
        }
    }
  while (0);

  return;
}

static int
  _mjo_ll_scan_separator(int *const o_found,
                         enum mjo_status *const o_status,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_rc;
  struct mjo_lexer_token l_token;

  *o_found = 0;

  do
    {
      l_rc = mjo_lexer_read(o_status, &l_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if (mjo_lexer_class_whitespace != l_token.m_class)
        {
          if (mjo_lexer_class_separator == l_token.m_class)
            {
              *o_found = 1;
            }
          else
            {
              mjo_lexer_push(io_lexer, &l_token);
            }
          break;
        }

      __mjo_ll_scan_separator(io_lexer, io_stream);

      *o_found = 1;
    }
  while (0);

  return l_rc;
}

extern int
  mjo_ll_scan_separator(int *const o_found,
                        enum mjo_status *const o_status,
                        mjo_lexer_t const io_lexer,
                        struct mjo_istream *const io_stream)
{
  int l_found;
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

      l_rc = _mjo_ll_scan_separator(&l_found, &l_status, io_lexer, io_stream);
    }
  while (0);

  if (o_found)
    {
      *o_found = l_found;
    }

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
