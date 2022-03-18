/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_parlong.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <string.h>
/**/
#include <mstdlib.h>
/**/
#include "mll.h"
/**/
#include "_arg.h"

static int
  __mjo_arg_parse_long(mjo_arg_t const io_arg,
                       mjo_lexer_t const io_lexer,
                       mjo_istream_t const io_stream)
{
  struct mjo_arg_option *l_option;
  int l_rc;

  l_option = _mjo_arg_lookup(io_arg, (unsigned char const *)io_arg->m_scratch);

  if (l_option)
    {
      l_rc = _mjo_arg_argument_read(l_option, io_arg, io_lexer, io_stream);

      if (l_rc)
        {
          io_arg->m_diag.m_errors++;
          io_arg->m_diag.m_errno_last = errno;

          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog,
                      "Error: unable to read argument\n");
            }
        }
    }
  else
    {
      io_arg->m_diag.m_errors++;
      io_arg->m_diag.m_errno_last = ENOENT;

      if (0
          == (mjo_arg_rule_mask_on_error_suppress_message
              & io_arg->m_rule_mask))
        {
          fprintf(io_arg->m_diag.m_elog, "Error: Invalid option\n");
          fprintf(io_arg->m_diag.m_elog,
                  "\t('%s')\n",
                  (unsigned char const *)io_arg->m_scratch);
        }

      l_rc = MJO_FAIL;
      errno = ENOENT;
    }

  return l_rc;
}

extern int
  _mjo_arg_parse_long(mjo_arg_t const io_arg,
                      mjo_lexer_t const io_lexer,
                      mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;

  do
    {
      l_rc = mjo_ll_read_option_long(
        &l_status, &io_arg->m_scratch, io_lexer, io_stream);

      if (l_rc)
        {
          io_arg->m_diag.m_errors++;
          io_arg->m_diag.m_errno_last = errno;

          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog,
                      "Error: unable to read command list input\n");
            }
          break;
        }

      if (l_status)
        {
          if (mjo_status_eof != l_status)
            {
              io_arg->m_diag.m_errors++;
              io_arg->m_diag.m_errno_last = EINVAL;

              if (0
                  == (mjo_arg_rule_mask_on_error_suppress_message
                      & io_arg->m_rule_mask))
                {
                  fprintf(io_arg->m_diag.m_elog,
                          "Error: unable to compose argument\n");
                }
            }
          break;
        }

      l_rc = __mjo_arg_parse_long(io_arg, io_lexer, io_stream);
    }
  while (0);

  return l_rc;
}
