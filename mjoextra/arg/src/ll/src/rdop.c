/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (rdop.c). 
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

static int
  __mjo_ll_read_operand(enum mjo_status *const o_status,
                        mjo_vector_t *const io_vector,
                        mjo_lexer_t const io_lexer,
                        mjo_istream_t const io_stream)
{
  int l_rc;
  struct mjo_lexer_token l_token;

  do
    {
      l_rc = mjo_lexer_read(o_status, &l_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if (mjo_lexer_class_whitespace == l_token.m_class)
        {
          mjo_lexer_push(io_lexer, &l_token);
          break;
        }

      mjo_vector_push(
        io_vector, l_token.m_peek.m_block, l_token.m_peek.m_octets);
    }
  while (1);

  return l_rc;
}

static int
  _mjo_ll_read_operand(enum mjo_status *const o_status,
                       mjo_vector_t *const io_vector,
                       mjo_lexer_t const io_lexer,
                       struct mjo_istream *const io_stream)
{
  size_t l_count;
  int l_rc;

  do
    {
      l_rc = mjo_ll_scan_whitespace(
        o_status, io_lexer, io_stream, mjo_ll_action_scan_to_non_whitespace);

      if (l_rc || *o_status)
        {
          break;
        }

      l_rc = __mjo_ll_read_operand(o_status, io_vector, io_lexer, io_stream);

      if (mjo_status_eof == *o_status)
        {
          l_count = mjo_vector_count(*io_vector);

          if (l_count)
            {
              *o_status = mjo_status_ok;
            }
        }
    }
  while (0);

  return l_rc;
}

extern int
  mjo_ll_read_operand(enum mjo_status *const o_status,
                      mjo_vector_t *const io_vector,
                      mjo_lexer_t const io_lexer,
                      struct mjo_istream *const io_stream)
{
  int l_rc;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == io_vector)
        {
          errno = EINVAL;
          break;
        }

      mjo_vector_clear(*io_vector);

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

      l_rc = _mjo_ll_read_operand(&l_status, io_vector, io_lexer, io_stream);
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
