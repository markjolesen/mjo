/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (sfree.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_istream.h"

extern void
  mjo_istream_mem_free(mjo_istream_t *const io_stream,
                       char const *i_fn,
                       size_t const i_ln)
{
  if (io_stream && *io_stream)
    {
      mjo_vector_free(&(*io_stream)->m_queue);
      explicit_bzero(*io_stream, sizeof(**io_stream));
      mjo_mem_free((void **const)io_stream, i_fn, i_ln);
    }

  return;
}
