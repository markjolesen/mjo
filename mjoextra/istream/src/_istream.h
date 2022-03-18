/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_istream.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__istream_h__)

#  include <mvector.h>
/**/
#  include "mistream.h"

struct mjo_istream_mem
{
  void const *m_block;
  size_t m_octets;
  size_t m_pos;
};

struct mjo_istream_file
{
  unsigned char m_lookahead;
  mjo_read_t m_read;
  mjo_handle_t m_handle;
};

enum mjo_istream_container_variant
{
  mjo_istream_container_variant_mem = 1,
  mjo_istream_container_variant_file
};

union mjo_istream_container
{
  struct mjo_istream_mem m_mem;
  struct mjo_istream_file m_file;
};

struct mjo_istream
{
  enum mjo_istream_option m_option;
  enum mjo_istream_container_variant m_variant;
  union mjo_istream_container m_container;
  mjo_vector_t m_queue;
};

#  define __istream_h__
#endif
