/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (tostr.c)
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_arg.h"

extern unsigned char const *
  mjo_arg_option_internal_to_str(enum mjo_arg_option_internal const i_option)
{
  unsigned char const *l_rc;

  switch (i_option)
    {
    case mjo_arg_option_internal_operand:
      l_rc = (unsigned char const *)mjo_arg_option_internal_operand_str;
      break;
    default:
      l_rc = (unsigned char const *)0;
      break;
    }

  return l_rc;
}
