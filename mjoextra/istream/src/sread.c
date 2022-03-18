/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (sread.c). 
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
#include <mu8.h>
/**/
#include "_istream.h"

static int
  __mjo_istream_read_mem(enum mjo_status *const o_status,
                         unsigned char *const o_peek,
                         struct mjo_istream_mem *const io_mem)
{
  do
    {
      if (io_mem->m_pos >= io_mem->m_octets)
        {
          *o_peek = 0;
          *o_status = mjo_status_eof;
          break;
        }

      *o_peek = *(((unsigned char *)io_mem->m_block) + io_mem->m_pos);
      io_mem->m_pos++;
      *o_status = mjo_status_ok;
    }
  while (0);

  return MJO_OK;
}

static int
  _mjo_istream_read_mem(enum mjo_status *const o_status,
                        unsigned char *const o_peek,
                        struct mjo_istream_mem *const io_mem)
{
  int l_rc;

  errno = EINVAL;

  *o_status = mjo_status_invalid;
  *o_peek = 0;

  l_rc = MJO_FAIL;

  if (io_mem->m_block)
    {
      l_rc = __mjo_istream_read_mem(o_status, o_peek, io_mem);
    }

  return l_rc;
}

static int
  __mjo_istream_read_file(enum mjo_status *const o_status,
                          unsigned char *const o_peek,
                          struct mjo_istream_file *const io_file)
{
  int l_rc;
  size_t l_octets;

  l_rc = mjo_read(
    o_status, &l_octets, o_peek, 1, io_file->m_read, io_file->m_handle);

  return l_rc;
}

static int
  _mjo_istream_read_file(enum mjo_status *const o_status,
                         unsigned char *const o_peek,
                         struct mjo_istream_file *const io_file)
{
  int l_rc;

  errno = EINVAL;

  *o_status = mjo_status_invalid;
  *o_peek = 0;

  l_rc = MJO_FAIL;

  if (io_file->m_read)
    {
      l_rc = __mjo_istream_read_file(o_status, o_peek, io_file);
    }

  return l_rc;
}

extern int
  _mjo_istream_read(enum mjo_status *const o_status,
                    struct mjo_utf8 *const o_peek,
                    mjo_istream_t const io_stream)
{
  size_t l_octets;
  unsigned char l_peek;
  int l_rc;
  size_t l_slot;

  memset(o_peek, 0, sizeof(*o_peek));

  do
    {
      switch (io_stream->m_variant)
        {
        case mjo_istream_container_variant_mem:
          l_rc = _mjo_istream_read_mem(
            o_status, &l_peek, &io_stream->m_container.m_mem);
          break;
        case mjo_istream_container_variant_file:
          l_rc = _mjo_istream_read_file(
            o_status, &l_peek, &io_stream->m_container.m_file);
          break;
        }

      if (l_rc || *o_status)
        {
          break;
        }

      o_peek->m_block[0] = l_peek;
      o_peek->m_octets = ((l_peek) ? 1 : 0);

      mjo_u8_calc(&o_peek->m_legal, &l_octets, l_peek);

      if (0 == o_peek->m_legal)
        {
          *o_status = mjo_status_invalid;
          break;
        }

      *o_status = mjo_status_ok;

      for (l_slot = 1; l_octets > l_slot; l_slot++)
        {
          switch (io_stream->m_variant)
            {
            case mjo_istream_container_variant_mem:
              l_rc = _mjo_istream_read_mem(
                o_status, &l_peek, &io_stream->m_container.m_mem);
              break;
            case mjo_istream_container_variant_file:
              l_rc = _mjo_istream_read_file(
                o_status, &l_peek, &io_stream->m_container.m_file);
              break;
            }

          if (l_rc || *o_status)
            {
              o_peek->m_legal = 0;
              *o_status = mjo_status_truncated;
              break;
            }

          mjo_u8_validate_nth_sequence(&o_peek->m_legal, l_peek);

          if (0 == o_peek->m_legal)
            {
              *o_status = mjo_status_invalid;
              break;
            }

          o_peek->m_block[o_peek->m_octets++] = l_peek;
        }
    }
  while (0);

  return l_rc;
}

extern int
  mjo_istream_read(enum mjo_status *const o_status,
                   struct mjo_utf8 *const o_peek,
                   mjo_istream_t const io_stream)
{
  size_t l_count;
  int l_rc;
  enum mjo_status l_status;

  l_rc = MJO_FAIL;
  l_status = mjo_status_invalid;

  do
    {
      if (0 == o_peek)
        {
          errno = EINVAL;
          break;
        }

      memset(o_peek, 0, sizeof(*o_peek));

      if (0 == io_stream)
        {
          errno = EINVAL;
          break;
        }

      l_count = mjo_vector_count(io_stream->m_queue);

      if (l_count)
        {
          memcpy(o_peek, io_stream->m_queue, sizeof(*o_peek));
          mjo_vector_dequeue(io_stream->m_queue);
          l_status = mjo_status_ok;
          l_rc = MJO_OK;
          break;
        }

      switch (io_stream->m_variant)
        {
        case mjo_istream_container_variant_mem:
        case mjo_istream_container_variant_file:
          l_rc = _mjo_istream_read(&l_status, o_peek, io_stream);
          break;
        }
    }
  while (0);

  if (o_status)
    {
      *o_status = l_status;
    }

  return l_rc;
}
