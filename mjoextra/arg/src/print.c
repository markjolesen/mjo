/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (print.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mr7.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_arg.h"

static void
  _mjo_arg_print_option(FILE *io_write,
                        struct mjo_arg_option const *const i_option,
                        unsigned char const *i_attribute)
{
  unsigned char const *l_str;
  enum mjo_vector_variant l_type;

  if (0 == i_attribute)
    {
      l_str = ((mjo_arg_option_mask_long & i_option->m_option_mask)
                 ? (unsigned char const *)"--"
                 : (unsigned char const *)"-");

      fprintf(io_write, "  %s%s\n", l_str, i_option->m_attribute);
    }
  else
    {
      fprintf(io_write, "  %s\n", i_attribute);
    }

  fprintf(io_write, "\t%s\n", i_option->m_description);
  fprintf(io_write, "\t\t  option flags:\n");

  l_str = ((mjo_arg_option_mask_required & i_option->m_option_mask)
             ? (unsigned char const *)"yes"
             : (unsigned char const *)"no");

  fprintf(io_write, "\t\t\t    required: %s\n", l_str);

  l_str = ((mjo_arg_option_mask_vector & i_option->m_option_mask)
             ? (unsigned char const *)"yes"
             : (unsigned char const *)"no");

  fprintf(io_write, "\t\t\t      vector: %s\n", l_str);

  fprintf(io_write, "\t\targument flags:\n");

  l_str = ((mjo_arg_argument_mask_required & i_option->m_argument_mask)
             ? (unsigned char const *)"yes"
             : (unsigned char const *)"no");

  fprintf(io_write, "\t\t\t    required: %s\n", l_str);

  l_type = mjo_vector_type(i_option->m_arg);
  l_str = mjo_vector_variant_tag(l_type);

  fprintf(io_write, "\t\t\t   data type: %s\n", l_str);

  return;
}

static void
  _mjo_arg_print_internal(FILE *io_write,
                          struct mjo_arg_option const *const i_option)
{
  int l_rc;

  do
    {
      l_rc = strcmp((char const *)mjo_arg_option_internal_operand_str,
                    (char const *)i_option->m_attribute);

      if (0 == l_rc)
        {
          _mjo_arg_print_option(
            io_write, i_option, (unsigned char const *)"--");
          break;
        }

      fprintf(stderr, "Error: unknown internal attribute");
      fprintf(stderr, "\tAttirubte is '%s'\n", i_option->m_attribute);
    }
  while (0);

  return;
}

extern void
  mjo_arg_print(FILE *const io_write, const mjo_arg_t i_arg)
{
  struct mjo_arg_option *const *l_option;
  size_t l_slot;
  size_t l_slots;
  FILE *l_write;

  l_option = mjo_arg_vector_malloc(&l_slots, i_arg);

  do
    {
      l_write = ((io_write) ? io_write : stdout);

      if (0 == l_slots)
        {
          fprintf(l_write, "\nThis application does not have any options.\n");
          break;
        }

      fprintf(l_write, "\nOptions:\n");

      for (l_slot = 0; l_slots > l_slot; l_slot++)
        {
          if (mjo_r7_period != l_option[l_slot]->m_attribute[0])
            {
              _mjo_arg_print_option(l_write, l_option[l_slot], 0);
            }
        }

      for (l_slot = 0; l_slots > l_slot; l_slot++)
        {
          if (mjo_r7_period == l_option[l_slot]->m_attribute[0])
            {
              _mjo_arg_print_internal(l_write, l_option[l_slot]);
            }
        }

      fprintf(l_write, "\n");
    }
  while (0);

  mjo_free((void **const) & l_option);

  return;
}
