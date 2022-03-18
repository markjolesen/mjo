/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mbsearcu.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mstdlib.h"

static void
  _mjo_search_binary_user(
    int *const o_found,
    size_t *const o_slot,
    void const *i_array,
    size_t const i_object_size,
    size_t const i_slots,
    void (*i_compare)(int *const, void *, void const *, void const *),
    void const *const i_object_to_find,
    void *i_user_data)
{
  size_t l_high;
  size_t l_low;
  char const *l_object;
  int l_result;

  (*o_found) = 0;
  (*o_slot) = 0;

  l_low = 0;
  l_high = i_slots;
  l_result = 0;

  do
    {
      if (l_low >= l_high)
        {
          break;
        }

      *o_slot = ((l_low + l_high) >> 1);
      l_object = &((char const *)i_array)[i_object_size * (*o_slot)];

      (*i_compare)(&l_result, i_user_data, i_object_to_find, l_object);

      if (0 == l_result)
        {
          if (o_found)
            {
              (*o_found) = 1;
            }
          break;
        }

      if (0 > l_result)
        {
          l_high = *o_slot;
        }
      else
        {
          l_low = (1 + *o_slot);
        }
    }
  while (1);

  return;
}

extern int
  mjo_search_binary_user(
    int *const o_found,
    size_t *const o_slot,
    void const *i_array,
    size_t const i_object_size,
    size_t const i_slots,
    void (*i_compare)(int *const, void *, void const *, void const *),
    void const *const i_object_to_find,
    void *i_user_data)
{
  size_t l_slot;
  int l_found;
  int l_rc;

  l_found = 0;
  l_rc = MJO_FAIL;
  l_slot = 0;

  do
    {
      if (0 == i_array)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_compare)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_object_size)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_slots)
        {
          errno = EINVAL;
          break;
        }

      _mjo_search_binary_user(&l_found,
                              &l_slot,
                              i_array,
                              i_object_size,
                              i_slots,
                              i_compare,
                              i_object_to_find,
                              i_user_data);

      l_rc = MJO_OK;
    }
  while (0);

  if (o_found)
    {
      (*o_found) = l_found;
    }

  if (o_slot)
    {
      (*o_slot) = l_slot;
    }

  return l_rc;
}
