/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mread.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstring.h>

#include "mstdio.h"
#include "mstdlib.h"

static int
  ERROR_READ_TRY_AGAIN(int const);

#if !defined(__DOS__)
#  define ERROR_READ_TRY_AGAIN(eno)                                           \
    ((EINTR == (eno)) || (EAGAIN == (eno)) || (EWOULDBLOCK == (eno)))
#else
#  define ERROR_READ_TRY_AGAIN(eno) ((EINTR == (eno)) || (EAGAIN == (eno)))
#endif

static void
  __mjo_read(enum mjo_status *const o_status,
             size_t *const o_octets,
             void *o_block,
             size_t const i_count,
             mjo_read_t const i_read,
             mjo_handle_t io_handle)
{
  ssize_t l_bytes;

  do
    {
      l_bytes = (*i_read)(io_handle, o_block, i_count);

      if (-1 == l_bytes)
        {
          *o_status = mjo_status_invalid;
          *o_octets = 0;
          break;
        }

      *o_octets = (size_t)l_bytes;

      if (i_count == (size_t)l_bytes)
        {
          *o_status = mjo_status_ok;
          break;
        }

      if (0 == l_bytes)
        {
          *o_status = mjo_status_eof;
          break;
        }

      *o_status = mjo_status_truncated;
    }
  while (0);

  return;
}

static int
  _mjo_read(enum mjo_status *const o_status,
            size_t *const o_octets,
            void *o_block,
            size_t const i_count,
            mjo_read_t const i_read,
            mjo_handle_t io_handle)
{
  size_t l_count;
  int l_rc;
  unsigned char *l_tail;

  *o_octets = 0;
  l_tail = o_block;

  l_rc = MJO_OK;

  do
    {
      if (i_count <= *o_octets)
        {
          *o_status = ((*o_octets) ? mjo_status_ok : mjo_status_eof);
          break;
        }

      __mjo_read(
        o_status, &l_count, l_tail, (i_count - *o_octets), i_read, io_handle);

      if ((mjo_status_ok == *o_status) || (mjo_status_eof == *o_status))
        {
          break;
        }

      if (mjo_status_invalid == *o_status)
        {
          if (!ERROR_READ_TRY_AGAIN(errno))
            {
              l_rc = MJO_FAIL;
              break;
            }
        }

      l_tail += l_count;
      *o_octets += l_count;
    }
  while (1);

  return l_rc;
}

extern int
  mjo_read(enum mjo_status *const o_status,
           size_t *const o_octets,
           void *o_block,
           size_t const i_count,
           mjo_read_t const i_read,
           mjo_handle_t io_handle)
{
  size_t l_octets;
  int l_rc;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == o_block)
        {
          errno = EINVAL;
          break;
        }

      explicit_bzero(o_block, i_count);

      if (0 == i_read)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_count)
        {
          l_rc = MJO_OK;
          l_status = mjo_status_eof;
          break;
        }

      l_rc
        = _mjo_read(&l_status, &l_octets, o_block, i_count, i_read, io_handle);
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  if (o_octets)
    {
      *o_octets = (size_t)l_octets;
    }

  return l_rc;
}
