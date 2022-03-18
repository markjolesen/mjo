/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_parseop.c). 
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
/**/
#include "_arg.h"

static void
  _eat(mjo_lexer_t const io_lexer, mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;
  struct mjo_lexer_token l_token;

  do
    {
      l_rc = mjo_lexer_read(&l_status, &l_token, io_lexer, io_stream);

      if (l_rc || l_status)
        {
          break;
        }
    }
  while (1);

  return;
}

static int
  __mjo_arg_parse_operand(struct mjo_arg_option *const io_option,
                          mjo_arg_t const io_arg,
                          mjo_lexer_t const io_lexer,
                          mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;

  do
    {
      if (*(unsigned char const *)io_arg->m_scratch)
        {
          l_rc = mjo_vector_permute_push(
            &io_option->m_arg, (unsigned char const *)io_arg->m_scratch);

          if (l_rc)
            {
              io_arg->m_diag.m_errors++;
              io_arg->m_diag.m_errno_last = errno;

              if (0
                  == (mjo_arg_rule_mask_on_error_suppress_message
                      & io_arg->m_rule_mask))
                {
                  fprintf(io_arg->m_diag.m_elog,
                          "Error: unable to convert value to data type\n");
                }
              break;
            }
        }

      l_rc = mjo_ll_read_operand(
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
    }
  while (1);

  return l_rc;
}

extern int
  _mjo_arg_parse_operand(mjo_arg_t const io_arg,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;
  struct mjo_arg_option *l_option;

  l_rc = MJO_OK;

  do
    {
      l_option = _mjo_arg_lookup(
        io_arg, (unsigned char const *)mjo_arg_option_internal_operand_str);

      if (0 == l_option)
        {
          io_arg->m_diag.m_errors++;
          io_arg->m_diag.m_errno_last = ENOENT;

          _eat(io_lexer, io_stream);

          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog, "ERROR: Invalid Operand\n");
              fprintf(io_arg->m_diag.m_elog,
                      "\t(Application does not accept operands)\n");
            }

          l_rc = MJO_FAIL;
          errno = ENOENT;
          break;
        }

      l_rc = __mjo_arg_parse_operand(l_option, io_arg, io_lexer, io_stream);
    }
  while (0);

  return l_rc;
}
