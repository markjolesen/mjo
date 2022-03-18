/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mshiftl.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mr7.h"
#include "mstdlib.h"
#include "mstring.h"

extern int
  mjo_r7_shift_left(void *io_vector,
                    size_t const i_slot,
                    size_t const i_count,
                    size_t const i_size,
                    size_t const i_slots,
                    void (*i_discharge)(void **const))
{
  int l_rc;
  size_t l_count;
  ptrdiff_t l_slot_dst;
  ptrdiff_t l_slot_src;
  unsigned char *l_object_dst;
  unsigned char *l_object_src;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_vector)
        {
          errno = EINVAL;
          break;
        }

      if (i_slots < i_slot)
        {
          errno = EINVAL;
          break;
        }

      l_rc = MJO_OK;

      if (0 == i_count)
        {
          break;
        }

      l_count = (i_slots > i_count) ? i_count : i_slots;
      l_slot_src = (ptrdiff_t)i_slot;
      l_slot_dst = (ptrdiff_t)(i_slot - l_count);
      l_object_src = (((unsigned char *)io_vector) + (i_size * l_slot_src));
      l_object_dst = (((unsigned char *)io_vector) + (i_size * l_slot_dst));

      do
        {
          if ((ptrdiff_t)i_slots <= l_slot_src)
            {
              break;
            }

          if (0 <= l_slot_dst)
            {
              if (i_discharge)
                {
                  (*i_discharge)((void **const) & l_object_dst);
                }

              memcpy(l_object_dst, l_object_src, i_size);
              memset(l_object_src, 0, i_size);
            }

          l_slot_dst++;
          l_slot_src++;
          l_object_dst += i_size;
          l_object_src += i_size;
        }
      while (1);
    }
  while (0);

  return l_rc;
}
