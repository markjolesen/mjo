/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_rd.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mll.h"
/**/
#include "_arg.h"

extern int
  __mjo_arg_argument_read(struct mjo_arg_option *const io_option,
                          mjo_arg_t const io_arg,
                          mjo_lexer_t const io_lexer,
                          mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;

  do
    {
      l_rc = mjo_ll_read_argument(
        &l_status, &io_arg->m_scratch, io_lexer, io_stream);

      if (l_rc)
        {
          break;
        }

      if ((mjo_status_ok != l_status) && (mjo_status_eof != l_status))
        {
          break;
        }

      l_rc = _mjo_arg_argument_push(
        io_option, io_arg, (unsigned char *)io_arg->m_scratch);
    }
  while (0);

  return l_rc;
}

extern int
  _mjo_arg_argument_read_array(struct mjo_arg_option *const io_option,
                               mjo_arg_t const io_arg,
                               mjo_lexer_t const io_lexer,
                               mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;
  struct mjo_lexer_token l_token;

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

      mjo_lexer_push(io_lexer, &l_token);

      if ((mjo_lexer_class_include == l_token.m_class)
          || (mjo_lexer_class_short == l_token.m_class)
          || (mjo_lexer_class_long == l_token.m_class))
        {
          break;
        }

      l_rc = __mjo_arg_argument_read(io_option, io_arg, io_lexer, io_stream);

      if (l_rc)
        {
          break;
        }
    }
  while (1);

  return l_rc;
}

extern int
  _mjo_arg_argument_read(struct mjo_arg_option *const io_option,
                         mjo_arg_t const io_arg,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_found;
  int l_rc;
  enum mjo_status l_status;

  do
    {
      l_rc = mjo_ll_scan_separator(&l_found, &l_status, io_lexer, io_stream);

      if (l_rc)
        {
          break;
        }

      if (l_status || (0 == l_found))
        {
          if (mjo_status_eof == l_status)
            {
              l_rc = _mjo_arg_argument_push(io_option, io_arg, 0);
            }
          break;
        }

      l_rc = __mjo_arg_argument_read(io_option, io_arg, io_lexer, io_stream);

      if (l_rc)
        {
          break;
        }

      if (0 == (mjo_arg_option_mask_vector & io_option->m_option_mask))
        {
          break;
        }

      l_rc
        = _mjo_arg_argument_read_array(io_option, io_arg, io_lexer, io_stream);
    }
  while (0);

  return l_rc;
}
