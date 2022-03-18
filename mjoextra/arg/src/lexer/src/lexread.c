/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (lexread.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_lexer.h"

static int
  __mjo_lexer_read(enum mjo_status *const o_status,
                   struct mjo_lexer_token *const o_token,
                   mjo_lexer_t const io_lexer,
                   mjo_istream_t const io_stream)
{
  int l_rc;

  do
    {
      l_rc = _mjo_lexer_read_stream(o_status, o_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if (mjo_lexer_class_short != o_token->m_class)
        {
          break;
        }

      l_rc = _mjo_lexer_read_stream(
        o_status, &io_lexer->m_queue, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          *o_status = mjo_status_ok;
          break;
        }

      if (mjo_lexer_class_short == io_lexer->m_queue.m_class)
        {
          memset(&io_lexer->m_queue, 0, sizeof(io_lexer->m_queue));
          o_token->m_class = mjo_lexer_class_long;
        }
    }
  while (0);

  return l_rc;
}

static int
  _mjo_lexer_read(enum mjo_status *const o_status,
                  struct mjo_lexer_token *const o_token,
                  mjo_lexer_t const io_lexer,
                  mjo_istream_t const io_stream)
{
  int l_rc;

  do
    {
      if (mjo_lexer_class_invalid != io_lexer->m_queue.m_class)
        {
          memcpy(o_token, &io_lexer->m_queue, sizeof(*o_token));
          memset(&io_lexer->m_queue, 0, sizeof(io_lexer->m_queue));
          *o_status = mjo_status_ok;
          l_rc = MJO_OK;
          break;
        }

      l_rc = __mjo_lexer_read(o_status, o_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if ((mjo_lexer_class_regular == o_token->m_class)
          && (1 == o_token->m_peek.m_octets)
          && (mjo_r7_backslash == o_token->m_peek.m_block[0]))
        {
          l_rc
            = _mjo_lexer_read_escape(o_status, o_token, io_lexer, io_stream);
        }
    }
  while (0);

  return l_rc;
}

extern int
  mjo_lexer_read(enum mjo_status *const o_status,
                 struct mjo_lexer_token *const o_token,
                 mjo_lexer_t const io_lexer,
                 mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == o_token)
        {
          errno = EINVAL;
          break;
        }

      memset(o_token, 0, sizeof(*o_token));

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

      l_rc = _mjo_lexer_read(&l_status, o_token, io_lexer, io_stream);
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
