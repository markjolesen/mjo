/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_rdstm.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mr7.h>
#include <mstring.h>
/**/
#include "_lexer.h"

extern int
  __mjo_lexer_read_stream(enum mjo_status *const o_status,
                          struct mjo_lexer_token *const o_token,
                          mjo_lexer_t const io_lexer,
                          mjo_istream_t const io_stream)
{
  int l_rc;

  do
    {
      memset(o_token, 0, sizeof(*o_token));

      l_rc = mjo_istream_read(o_status, &o_token->m_peek, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      if (0 == o_token->m_peek.m_legal)
        {
          o_token->m_class = mjo_lexer_class_invalid;
          *o_status = mjo_status_invalid;
          break;
        }

      if (1 != o_token->m_peek.m_octets)
        {
          break;
        }

      if (mjo_r7_cr != o_token->m_peek.m_block[0])
        {
          if (mjo_r7_lf == o_token->m_peek.m_block[0])
            {
              o_token->m_peek.m_block[0] = mjo_r7_space;
            }
          break;
        }
    }
  while (1);

  return l_rc;
}

extern int
  _mjo_lexer_read_stream(enum mjo_status *const o_status,
                         struct mjo_lexer_token *const o_token,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_bool;
  int l_rc;

  do
    {
      l_rc = __mjo_lexer_read_stream(o_status, o_token, io_lexer, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      mjo_utf8_is_whitespace(&l_bool, &o_token->m_peek);

      if (l_bool)
        {
          o_token->m_class = mjo_lexer_class_whitespace;
          break;
        }

      mjo_utf8_is_punctuation(&l_bool, &o_token->m_peek);

      o_token->m_class
        = ((l_bool) ? mjo_lexer_class_punctuation : mjo_lexer_class_regular);

      if (1 != o_token->m_peek.m_octets)
        {
          break;
        }

      switch (o_token->m_peek.m_block[0])
        {
        case mjo_r7_at:
          o_token->m_class = mjo_lexer_class_include;
          break;
        case mjo_r7_minus:
          o_token->m_class = mjo_lexer_class_short;
          break;
        case mjo_r7_equal:
          o_token->m_class = mjo_lexer_class_separator;
          break;
        }
    }
  while (0);

  return l_rc;
}
