/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (option.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_arg.h"

static int
  _mjo_arg_option(mjo_arg_t const io_arg,
                  enum mjo_arg_option_mask const i_option_mask,
                  unsigned char const *i_attribute,
                  unsigned char const *i_description,
                  enum mjo_arg_argument_mask const i_argument_mask,
                  enum mjo_vector_variant const i_variant)
{
  int l_rc;
  struct mjo_arg_option *l_option;
  size_t l_hash;
  struct mjo_arg_option *l_last;
  struct mjo_arg_option *l_node;
  size_t l_slot;

  l_rc = MJO_FAIL;

  do
    {
      mjo_r7_hash(&l_hash, i_attribute, strlen((char const *)i_attribute));
      l_slot = (l_hash % mjo_arg_buckets_max);
      l_node = io_arg->m_bucket[l_slot];

      l_last = l_node;
      l_option = 0;

      do
        {
          if (0 == l_node)
            {
              break;
            }

          l_rc = strcmp((char const *)l_node->m_attribute,
                        (char const *)i_attribute);

          if (0 == l_rc)
            {
              l_option = l_node;
              break;
            }

          l_last = l_node;
          l_node = l_node->m_next;
        }
      while (1);

      if (l_option)
        {
          errno = EEXIST;
          break;
        }

      mjo_malloc((void **const) & l_option, 1, sizeof(*l_option));
      explicit_bzero(l_option, sizeof(*l_option));

      l_option->m_option_mask = i_option_mask;
      mjo_strdup(&l_option->m_attribute, i_attribute);
      mjo_strdup(&l_option->m_description, i_description);
      l_option->m_argument_mask = i_argument_mask;

      mjo_vector_malloc(
        &l_option->m_arg, 1, i_variant, mjo_vector_size_auto, 0);

      if (0 == l_node)
        {
          io_arg->m_bucket[l_slot] = l_option;
        }
      else
        {
          l_node->m_next = l_option;
        }

      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}

extern int
  mjo_arg_option(mjo_arg_t const io_arg,
                 enum mjo_arg_option_mask const i_option_mask,
                 unsigned char const *i_attribute,
                 unsigned char const *i_description,
                 enum mjo_arg_argument_mask const i_argument_mask,
                 enum mjo_vector_variant const i_variant)
{
  int l_rc;
  int l_valid;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_arg)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_attribute || 0 == *i_attribute)
        {
          errno = EINVAL;
          break;
        }

      _mjo_arg_option_attribute_validate(&l_valid, i_attribute);

      if (0 == l_valid)
        {
          errno = EINVAL;
          break;
        }

      switch (i_variant)
        {
        case mjo_vector_variant_char:
        case mjo_vector_variant_short:
        case mjo_vector_variant_ushort:
        case mjo_vector_variant_bool:
        case mjo_vector_variant_int:
        case mjo_vector_variant_uint:
        case mjo_vector_variant_long:
        case mjo_vector_variant_ulong:
        case mjo_vector_variant_size_t:
        case mjo_vector_variant_ptrdiff_t:
        case mjo_vector_variant_double:
          l_rc = _mjo_arg_option(io_arg,
                                 i_option_mask,
                                 i_attribute,
                                 i_description,
                                 i_argument_mask,
                                 i_variant);
          break;
        default:
          errno = EINVAL;
          break;
        }
    }
  while (0);

  return l_rc;
}
