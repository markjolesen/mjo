/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (rdcsv.c). 
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
/**/
#include "mread.h"

static int
  _mjo_read_csv(int *const o_eol,
                enum mjo_status *const o_status,
                mjo_vector_t *const io_vector,
                size_t const i_octets_max,
                mjo_read_t const i_read,
                mjo_handle_t i_handle)
{
  size_t l_bytes;
  size_t l_count;
  int l_rc;
  unsigned char l_lookahead;
  size_t l_quote_count;
  int l_in_quote;
  unsigned char l_peek;

  *o_eol = 0;
  *o_status = mjo_status_invalid;

  l_lookahead = 0;
  l_in_quote = 0;
  l_quote_count = 0;
  l_rc = EINVAL;

  do
    {
      if (0 == l_lookahead)
        {
          l_rc = mjo_read(o_status, &l_bytes, &l_peek, 1, i_read, i_handle);

          if (l_rc || *o_status)
            {
              break;
            }
        }
      else
        {
          l_peek = l_lookahead;
          l_lookahead = 0;
        }

      if (mjo_r7_quote != l_peek)
        {
          if (l_quote_count)
            {
              l_in_quote = 0;
              l_quote_count = 0;
            }

          if (mjo_r7_lf == l_peek)
            {
              *o_eol = 1;
              *o_status = mjo_status_ok;
              break;
            }

          if ((0 == l_in_quote) && (mjo_r7_comma == l_peek))
            {
              *o_status = mjo_status_ok;
              break;
            }

          if (mjo_r7_cr != l_peek)
            {
              l_count = mjo_vector_count(*io_vector);

              if (i_octets_max > l_count)
                {
                  mjo_vector_push(io_vector, &l_peek, 1);
                }
            }
        }
      else
        {
          if (0 == l_in_quote)
            {
              l_in_quote = 1;
            }
          else
            {
              l_quote_count++;
              if (2 == l_quote_count)
                {
                  l_count = mjo_vector_count(*io_vector);

                  if (i_octets_max > l_count)
                    {
                      mjo_vector_push(io_vector, &l_peek, 1);
                    }
                  l_quote_count = 0;
                }
            }
        }
    }
  while (1);

  if ((mjo_status_ok == *o_status) && l_in_quote)
    {
      *o_status = mjo_status_invalid;
    }

  return l_rc;
}

extern int
  mjo_read_csv(int *const o_eol,
               enum mjo_status *const o_status,
               mjo_vector_t *const io_vector,
               size_t const i_octets_max,
               mjo_read_t const i_read,
               mjo_handle_t i_handle)
{
  int l_eol;
  int l_rc;
  enum mjo_status l_status;

  errno = EINVAL;

  l_eol = 0;
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

      l_rc = _mjo_read_csv(
        &l_eol, &l_status, io_vector, i_octets_max, i_read, i_handle);
    }
  while (0);

  if (o_eol)
    {
      *o_eol = l_eol;
    }

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
