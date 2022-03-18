/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_parincl.c). 
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

static void
  _mjo_arg_parse_include_lookup(int *const o_found,
                                mjo_arg_t const io_arg,
                                unsigned char const *i_path)
{
  size_t l_count;
  int l_rc;
  size_t l_slot;

  *o_found = 0;

  l_count = mjo_vector_count(io_arg->m_include);

  for (l_slot = 0; l_count > l_slot; l_slot++)
    {
      l_rc = strcmp((char const *)i_path,
                    ((char const **)io_arg->m_include)[l_slot]);
      if (0 == l_rc)
        {
          *o_found = 1;
          break;
        }
    }

  return;
}

extern int
  _mjo_arg_parse_include(mjo_arg_t const io_arg,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_bool;
  int l_rc;
  unsigned char *l_path;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_path = 0;

  do
    {
      l_rc = mjo_ll_read_include(
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
                          "Error: unable to compose option\n");
                }
            }
          break;
        }

      if (0 == *(unsigned char *)io_arg->m_scratch)
        {
          break;
        }

      l_rc = mjo_path_full(&l_path, (unsigned char *)io_arg->m_scratch);

      if (l_rc)
        {
          io_arg->m_diag.m_errors++;
          io_arg->m_diag.m_errno_last = errno;

          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog, "Error: Invalid path\n");
              fprintf(io_arg->m_diag.m_elog,
                      "\tinclude=%s\n",
                      (unsigned char *)io_arg->m_scratch);
              fprintf(io_arg->m_diag.m_elog,
                      "\terrno(%d)=%s\n",
                      errno,
                      strerror(errno));
            }
          break;
        }

      _mjo_arg_parse_include_lookup(&l_bool, io_arg, l_path);

      if (l_bool)
        {
          break;
        }

      if (mjo_arg_include_depth_max <= io_arg->m_include_depth)
        {
          io_arg->m_diag.m_errors++;
          io_arg->m_diag.m_errno_last = errno;

          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog, "Error: Invalid include file\n");
              fprintf(io_arg->m_diag.m_elog, "\t(Too many open files)\n");
              fprintf(io_arg->m_diag.m_elog,
                      "\tinclude=%s\n",
                      (unsigned char *)io_arg->m_scratch);
              fprintf(io_arg->m_diag.m_elog,
                      "\tnesting max=%ud\n",
                      mjo_arg_include_depth_max);
            }

          l_rc = MJO_FAIL;
          errno = E2BIG;
          break;
        }

      mjo_vector_push(&io_arg->m_include, (void *const) & l_path, 1);

      io_arg->m_include_depth++;

      l_rc = mjo_arg_parse_file(io_arg, l_path);

      io_arg->m_include_depth--;
      l_path = 0;
    }
  while (0);

  mjo_free((void **const) & l_path);

  return l_rc;
}
