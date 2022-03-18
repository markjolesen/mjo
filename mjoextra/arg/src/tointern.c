/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (tointern.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstring.h>
/**/
#include "_arg.h"

extern enum mjo_arg_option_internal
  mjo_arg_option_str_to_internal(unsigned char const *i_str)
{
  enum mjo_arg_option_internal l_rc;
  int l_rc2;

  l_rc = mjo_arg_option_internal_invalid;

  if (i_str && *i_str)
    {
      l_rc2 = strcmp(mjo_arg_option_internal_operand_str, (char const *)i_str);

      if (0 == l_rc2)
        {
          l_rc = mjo_arg_option_internal_operand;
        }
    }

  return l_rc;
}
