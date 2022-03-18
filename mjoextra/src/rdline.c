/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (rdline.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "mread.h"

extern int
  _mjo_read_line(enum mjo_status *const o_status,
                 mjo_vector_t *const io_vector,
                 size_t const i_octets_max,
                 mjo_read_t const i_read,
                 mjo_handle_t io_handle)
{
  size_t l_octets;
  int l_rc;
  unsigned char l_peek;

  mjo_vector_clear(*io_vector);

  do
    {
      l_octets = mjo_vector_count(*io_vector);

      l_rc = mjo_read(o_status, 0, &l_peek, 1, i_read, io_handle);

      if (l_rc || *o_status)
        {
          if ((l_octets) && (mjo_status_eof == *o_status))
            {
              *o_status = mjo_status_ok;
            }
          break;
        }

      if (mjo_r7_lf == l_peek)
        {
          *o_status = (i_octets_max > l_octets) ? mjo_status_ok
                                                : mjo_status_truncated;
          break;
        }

      if (mjo_r7_cr != l_peek)
        {
          if (i_octets_max > l_octets)
            {
              mjo_vector_push(io_vector, &l_peek, 1);
            }
        }
    }
  while (1);

  return l_rc;
}

extern int
  mjo_read_line(enum mjo_status *const o_status,
                mjo_vector_t *const io_vector,
                size_t const i_octets_max,
                mjo_read_t const i_read,
                mjo_handle_t io_handle)
{
  int l_rc;
  enum mjo_status l_status;

  errno = EINVAL;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == io_vector)
        {
          break;
        }

      mjo_vector_clear(*io_vector);

      if (0 == i_read)
        {
          break;
        }

      if (0 == i_octets_max)
        {
          break;
        }

      l_rc = _mjo_read_line(
        &l_status, io_vector, i_octets_max, i_read, io_handle);
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
