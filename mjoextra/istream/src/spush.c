/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (spush.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_istream.h"

extern void
  mjo_istream_push(mjo_istream_t const io_stream,
                   struct mjo_utf8 const *const i_peek)
{
  if (io_stream && i_peek)
    {
      mjo_vector_push(&io_stream->m_queue, (void *const)i_peek, 1);
    }

  return;
}
