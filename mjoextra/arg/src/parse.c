/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (parse.c). 
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
#include "_arg.h"

static int
  __mjo_arg_parse(mjo_arg_t const io_arg,
                  mjo_lexer_t const io_lexer,
                  mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;
  struct mjo_lexer_token l_token;

  do
    {
      l_rc = mjo_lexer_read(&l_status, &l_token, io_lexer, io_stream);

      if (l_rc || l_status)
        {
          if (mjo_status_eof != l_status)
            {
              if ((mjo_arg_rule_mask_on_error_keep_going
                   & io_arg->m_rule_mask))
                {
                  continue;
                }
            }

          l_rc = MJO_FAIL;
          break;
        }

      switch (l_token.m_class)
        {
        case mjo_lexer_class_include:
          l_rc = _mjo_arg_parse_include(io_arg, io_lexer, io_stream);
          break;
        case mjo_lexer_class_short:
          l_rc = _mjo_arg_parse_short(io_arg, io_lexer, io_stream);
          break;
        case mjo_lexer_class_long:
          l_rc = mjo_lexer_read(&l_status, &l_token, io_lexer, io_stream);

          if (l_rc || l_status)
            {
              break;
            }

          if (mjo_lexer_class_whitespace != l_token.m_class)
            {
              mjo_lexer_push(io_lexer, &l_token);
              l_rc = _mjo_arg_parse_long(io_arg, io_lexer, io_stream);
              break;
            }
        default:
          mjo_lexer_push(io_lexer, &l_token);
          l_rc = _mjo_arg_parse_operand(io_arg, io_lexer, io_stream);
          break;
        }

      if (l_rc || l_status)
        {
          break;
        }
    }
  while (1);

  return l_rc;
}

static int
  _mjo_arg_parse(mjo_arg_t const io_arg, mjo_istream_t const io_stream)
{
  int l_rc;
  int l_valid;
  mjo_lexer_t l_lexer;

  mjo_lexer_malloc(&l_lexer);

  l_rc = __mjo_arg_parse(io_arg, l_lexer, io_stream);

  mjo_lexer_free(&l_lexer);

  return l_rc;
}

extern int
  mjo_arg_parse(mjo_arg_t const io_arg, mjo_istream_t const io_stream)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_arg)
        {
          errno = EINVAL;
          break;
        }

      if (0 == io_stream)
        {
          errno = EINVAL;
          break;
        }

      l_rc = _mjo_arg_parse(io_arg, io_stream);
    }
  while (0);

  return l_rc;
}
