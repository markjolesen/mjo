/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_optval.c).

 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mr7.h>
#include <mu8.h>
/**/
#include "_arg.h"

static void
  _mjo_arg_option_attribute_validate_internal(int *const o_valid,
                                              unsigned char const *i_attribute)
{
  enum mjo_arg_option_internal l_internal;

  l_internal = mjo_arg_option_str_to_internal(i_attribute);

  *o_valid = (mjo_arg_option_internal_invalid != l_internal);

  return;
}

static void
  __mjo_arg_option_attribute_validate(int *const o_valid,
                                      unsigned char const *i_attribute)
{
  int l_bool;
  int l_exit;
  unsigned char const *l_head;
  unsigned char *l_last;
  struct mjo_utf8 l_peek;
  enum mjo_status l_status;
  unsigned long l_unicode;

  *o_valid = 0;

  l_head = (unsigned char *)i_attribute;

  do
    {
      mjo_utf8_compose(
        &l_status, (unsigned char const **)&l_last, &l_peek, l_head);

      if (l_status)
        {
          if (mjo_status_eof == l_status)
            {
              *o_valid = 1;
            }
          break;
        }

      mjo_utf8_is_whitespace(&l_bool, &l_peek);

      if (l_bool)
        {
          break;
        }

      mjo_utf8_is_punctuation(&l_bool, &l_peek);

      if (l_bool)
        {
          if (!(1 == l_peek.m_octets) && (mjo_r7_minus == l_peek.m_block[0]))
            {
              break;
            }
        }

      mjo_utf8_is_quote(&l_bool, &l_peek);

      if (l_bool)
        {
          break;
        }

      if (1 == l_peek.m_octets)
        {
          *o_valid = (((mjo_r7_lwr_a <= l_peek.m_block[0])
                       && (mjo_r7_lwr_z >= l_peek.m_block[0]))
                      || ((mjo_r7_upr_a <= l_peek.m_block[0])
                          && (mjo_r7_upr_z >= l_peek.m_block[0]))
                      || ((mjo_r7_0 <= l_peek.m_block[0])
                          && (mjo_r7_9 >= l_peek.m_block[0])));
        }

      if (0 == *o_valid)
        {
          break;
        }

      l_head = l_last;
    }
  while (1);

  return;
}

extern void
  _mjo_arg_option_attribute_validate(int *const o_valid,
                                     unsigned char const *i_attribute)
{
  *o_valid = 0;

  if (i_attribute)
    {
      switch (i_attribute[0])
        {
        case mjo_r7_nul:
          break;
        case mjo_r7_period:
          _mjo_arg_option_attribute_validate_internal(o_valid, i_attribute);
          break;
        default:
          __mjo_arg_option_attribute_validate(o_valid, i_attribute);
          break;
        }
    }

  return;
}
