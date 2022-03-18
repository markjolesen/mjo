/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (parblock.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstdlib.h>
/**/
#include "_arg.h"

static int
  _mjo_arg_parse_block(mjo_arg_t const io_arg,
                       void const *i_block,
                       size_t const i_octets)
{
  int l_rc;
  mjo_istream_t l_stream;

  mjo_istream_block_malloc(
    &l_stream, mjo_istream_option_none, i_block, i_octets);

  l_rc = mjo_arg_parse(io_arg, l_stream);

  mjo_istream_free(&l_stream);

  return l_rc;
}

extern int
  mjo_arg_parse_block(mjo_arg_t const io_arg,
                      void const *i_block,
                      size_t const i_octets)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_arg)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_block)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_octets)
        {
          l_rc = MJO_OK;
          break;
        }

      l_rc = _mjo_arg_parse_block(io_arg, i_block, i_octets);
    }
  while (0);

  return l_rc;
}
