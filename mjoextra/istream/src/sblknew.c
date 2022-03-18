/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (sblknew.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_istream.h"

extern void
  mjo_istream_block_mem_malloc(mjo_istream_t *const o_stream,
                               enum mjo_istream_option const i_option,
                               void const *i_block,
                               size_t const i_octets,
                               char const *i_fn,
                               size_t const i_ln)
{
  do
    {
      if (0 == o_stream)
        {
          errno = EINVAL;
          break;
        }

      *o_stream = 0;

      if (0 == i_block)
        {
          errno = EINVAL;
          break;
        }

      mjo_mem_calloc(
        (void **const)o_stream, 1, sizeof((**o_stream)), i_fn, i_ln);

      (*o_stream)->m_option = i_option;
      (*o_stream)->m_variant = mjo_istream_container_variant_mem;
      (*o_stream)->m_container.m_mem.m_block = i_block;
      (*o_stream)->m_container.m_mem.m_octets = i_octets;

      mjo_vector_malloc(&(*o_stream)->m_queue,
                        1,
                        mjo_vector_variant_struct,
                        sizeof(struct mjo_utf8),
                        0);
    }
  while (0);

  return;
}
