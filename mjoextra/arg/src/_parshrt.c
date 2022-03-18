/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_parshort.c).
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
  _mjo_arg_parse_short_option_next(enum mjo_status *o_status,
                                   struct mjo_utf8 *const o_peek,
                                   unsigned char const **o_last,
                                   mjo_arg_t const io_arg,
                                   unsigned char const *i_head)
{
  int l_rc;
  unsigned char const *l_head;

  memset(o_peek, 0, sizeof(*o_peek));
  *o_last = i_head;

  l_rc = MJO_OK;
  l_head = i_head;

  do
    {
      mjo_utf8_compose(o_status, o_last, o_peek, l_head);

      if ((mjo_status_eof == *o_status) || (mjo_status_ok == *o_status))
        {
          break;
        }

      io_arg->m_diag.m_errors++;
      io_arg->m_diag.m_errno_last = EINVAL;

      if (0
          == (mjo_arg_rule_mask_on_error_suppress_message
              & io_arg->m_rule_mask))
        {
          fprintf(io_arg->m_diag.m_elog, "Error: Invalid option\n");
          fprintf(io_arg->m_diag.m_elog, "\t(Unable to encode)\n");
          fprintf(io_arg->m_diag.m_elog, "\t('%c')\n", *l_head);
        }

      if (0 == (mjo_arg_rule_mask_on_error_keep_going & io_arg->m_rule_mask))
        {
          l_rc = MJO_FAIL;
          errno = EINVAL;
          break;
        }

      l_head = *o_last;
    }
  while (1);

  return l_rc;
}

static int
  __mjo_arg_parse_short(mjo_arg_t const io_arg,
                        mjo_lexer_t const io_lexer,
                        mjo_istream_t const io_stream,
                        unsigned char *l_options)
{
  int l_bool;
  struct mjo_arg_option *l_option;
  struct mjo_arg_option *l_option_prev;
  int l_rc;
  unsigned char const *l_head;
  unsigned char const *l_last;
  enum mjo_status l_status;
  struct mjo_utf8 l_peek;

  l_option_prev = 0;
  l_head = l_options;

  do
    {
      if (0 == *l_head)
        {
          if (l_option_prev)
            {
              l_rc = _mjo_arg_argument_read(
                l_option_prev, io_arg, io_lexer, io_stream);

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

          break;
        }

      l_rc = _mjo_arg_parse_short_option_next(
        &l_status, &l_peek, &l_last, io_arg, l_head);

      if (l_rc || l_status)
        {
          break;
        }

      l_option = _mjo_arg_lookup(io_arg, l_peek.m_block);

      if (0 == l_option)
        {
          if (l_option_prev)
            {
              l_rc = _mjo_arg_argument_push(l_option_prev, io_arg, l_head);

              if (l_rc)
                {
                  io_arg->m_diag.m_errors++;
                  io_arg->m_diag.m_errno_last = errno;

                  if (0
                      == (mjo_arg_rule_mask_on_error_suppress_message
                          & io_arg->m_rule_mask))
                    {
                      fprintf(io_arg->m_diag.m_elog,
                              "Error: unable to push argument\n");
                    }
                }
              break;
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
                  fprintf(io_arg->m_diag.m_elog, "\t('%c')\n", *l_head);
                }

              if (0
                  == (mjo_arg_rule_mask_on_error_keep_going
                      & io_arg->m_rule_mask))
                {
                  l_rc = MJO_FAIL;
                  errno = ENOENT;
                  break;
                }

              l_rc = MJO_OK;
            }
        }

      l_option_prev = l_option;
      l_head++;
    }
  while (1);

  return l_rc;
}

extern int
  _mjo_arg_parse_short(mjo_arg_t const io_arg,
                       mjo_lexer_t const io_lexer,
                       mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_status l_status;
  unsigned char *l_options;

  l_options = 0;

  do
    {
      l_rc = mjo_ll_read_option_short(
        &l_status, &io_arg->m_scratch, io_lexer, io_stream);

      if (l_rc || l_status)
        {
          break;
        }

      if (*(unsigned char *)io_arg->m_scratch)
        {
          mjo_strdup(&l_options, (unsigned char const *)io_arg->m_scratch);
        }
      else
        {
          mjo_strdup(&l_options, (unsigned char const *)"-");
        }

      l_rc = __mjo_arg_parse_short(io_arg, io_lexer, io_stream, l_options);
    }
  while (0);

  mjo_free((void **const) & l_options);

  return l_rc;
}
