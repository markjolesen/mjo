/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (parvec.c). 
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
#include <mvector.h>
/**/
#include "_arg.h"

static void
  _flatten(mjo_vector_t *const io_var,
           unsigned char *const *const i_vector,
           size_t const i_slots)
{
  int l_rc;
  size_t l_octets;
  size_t l_slot;
  unsigned char *l_src;

  l_rc = 0;

  for (l_slot = 0; i_slots > l_slot; l_slot++)
    {
      l_src = i_vector[l_slot];

      if (0 == l_src)
        {
          break;
        }

      l_octets = strlen((char const *)l_src);

      if (0 == l_octets)
        {
          continue;
        }

      if (l_slot)
        {
          mjo_vector_push(io_var, (void *)mjo_r7_space_str, 1);
        }

      mjo_vector_push(io_var, (void *)l_src, l_octets);
    }

  return;
}

static int
  _mjo_arg_parse_vector(mjo_arg_t const io_arg,
                        unsigned char *const *const i_vector,
                        size_t const i_slots)
{
  int l_rc;
  static mjo_vector_t l_chunk;
  size_t l_octets;
  size_t l_slot;
  size_t l_tally;

  l_chunk = 0;
  l_rc = 0;
  l_tally = 0;

  do
    {
      for (l_slot = 0; i_slots > l_slot; l_slot++)
        {
          l_octets = strlen((char const *)i_vector[l_slot]);
          l_rc = mjo_add_size_t(&l_tally, l_tally, l_octets);

          if (l_rc)
            {
              mjo_abort(ERANGE);
            }
        }

      l_rc = mjo_add_size_t(&l_tally, l_tally, i_slots);

      if (l_rc)
        {
          mjo_abort(ERANGE);
        }

      mjo_vector_malloc(
        &l_chunk, l_tally, mjo_vector_variant_char, mjo_vector_size_auto, 0);

      _flatten(&l_chunk, i_vector, i_slots);

      l_octets = mjo_vector_count(l_chunk);

      l_rc = mjo_arg_parse_block(io_arg, (unsigned char *)l_chunk, l_octets);
    }
  while (0);

  mjo_vector_free(&l_chunk);

  return l_rc;
}

extern int
  mjo_arg_parse_vector(mjo_arg_t const io_arg,
                       unsigned char *const *const i_vector,
                       size_t const i_slots)
{
  int l_rc;
  size_t l_octets;
  unsigned char const *l_str;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_arg)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_vector)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_slots)
        {
          l_rc = MJO_OK;
          break;
        }

      l_rc = _mjo_arg_parse_vector(io_arg, i_vector, i_slots);
    }
  while (0);

  return l_rc;
}
