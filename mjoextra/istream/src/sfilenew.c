/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (sfilenew.c). 
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
  mjo_istream_file_mem_malloc(mjo_istream_t *const o_stream,
                              enum mjo_istream_option const i_option,
                              mjo_read_t const i_read,
                              mjo_handle_t const i_handle,
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

      if (0 == i_read)
        {
          errno = EINVAL;
          break;
        }

      mjo_mem_calloc(
        (void **const)o_stream, 1, sizeof((**o_stream)), i_fn, i_ln);

      (*o_stream)->m_option = i_option;
      (*o_stream)->m_variant = mjo_istream_container_variant_file;
      (*o_stream)->m_container.m_file.m_read = i_read;
      (*o_stream)->m_container.m_file.m_handle = i_handle;

      mjo_vector_malloc(&(*o_stream)->m_queue,
                        1,
                        mjo_vector_variant_struct,
                        sizeof(struct mjo_utf8),
                        0);
    }
  while (0);

  return;
}
