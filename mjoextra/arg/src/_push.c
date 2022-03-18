/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_push.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
/**/
#include "_arg.h"

extern int
  _mjo_arg_argument_push(struct mjo_arg_option *const io_option,
                         mjo_arg_t const io_arg,
                         unsigned char const *i_argument)
{
  int l_rc;
  enum mjo_vector_variant l_variant;
  unsigned char const *l_argument;

  l_rc = MJO_FAIL;
  l_argument = i_argument;

  do
    {
      if (0 == (mjo_arg_option_mask_vector & io_option->m_option_mask))
        {
          mjo_vector_clear(io_option->m_arg);
        }

      if ((0 == l_argument) || (0 == *l_argument))
        {
          l_variant = mjo_vector_type(io_option->m_arg);

          if (mjo_vector_variant_bool == l_variant)
            {
              l_argument = (unsigned char const *)"1";
            }
          else
            {
              if (mjo_arg_argument_mask_required & io_option->m_argument_mask)
                {
                  if (0
                      == (mjo_arg_rule_mask_on_error_suppress_message
                          & io_arg->m_rule_mask))
                    {
                      fprintf(io_arg->m_diag.m_elog,
                              "Error: Option requires an argument\n");
                    }
                }
              break;
            }
        }
      else if (0
               == (mjo_arg_argument_mask_required
                   & io_option->m_argument_mask))
        {
          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog,
                      "Error: Option does not take an argument\n");
              break;
            }
        }

      l_rc = mjo_vector_permute_push(&io_option->m_arg, l_argument);
    }
  while (0);

  return l_rc;
}
