/* CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_mjo_lexer_read_escape.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <limits.h>
/**/
#include "mr7.h"
#include "mstdlib.h"
#include "mstring.h"
#include "mu8.h"
#include "mutf8.h"
/**/
#include "_lexer.h"

enum mjo_lexer_base
{
  mjo_lexer_base_invalid = 0,
  mjo_lexer_base_octal = 8,
  mjo_lexer_base_hexidecimal = 16
};

static int
  _convert(enum mjo_status *const o_status,
           struct mjo_utf8 *const o_peek,
           unsigned char const *i_buf,
           enum mjo_lexer_base const i_base)
{
  size_t l_count;
  int l_rc;
  int l_valid;
  unsigned long l_value;
  size_t l_slot;
  unsigned char *l_tail;

  *o_status = mjo_status_invalid;
  memset(o_peek, 0, sizeof(*o_peek));

  do
    {
      l_value = strtoul((char const *)i_buf, (char **)&l_tail, i_base);

      if (*l_tail)
        {
          l_rc = MJO_FAIL;
          break;
        }

      l_rc = snprintf(
        (char *)o_peek->m_block, (1 + mjo_utf8_max_octets), "%lu", l_value);

      if (-1 == l_rc)
        {
          l_rc = MJO_FAIL;
          break;
        }

      o_peek->m_octets = (size_t)l_rc;

      mjo_u8_validate(&l_rc, &l_tail, o_peek->m_block);

      if (0 == l_rc)
        {
          l_rc = MJO_FAIL;
          break;
        }

      o_peek->m_legal = 1;
      *o_status = mjo_status_ok;
      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}

static int
  _mjo_lexer_base_read(enum mjo_status *const o_status,
                       struct mjo_utf8 *const o_peek,
                       mjo_lexer_t const io_lexer,
                       mjo_istream_t const io_stream,
                       enum mjo_lexer_base const i_base)
{
  int l_bool;
  int l_rc;
  unsigned char l_chr;
  struct mjo_utf8 l_peek;
  unsigned char l_buf[8 + 1];
  unsigned char *l_ptr;
  size_t l_slot;

  memset(o_peek, 0, sizeof(*o_peek));

  l_ptr = l_buf;
  l_slot = 0;

  do
    {
      l_rc = mjo_istream_read(o_status, &l_peek, io_stream);

      if (l_rc || *o_status)
        {
          break;
        }

      l_bool = 0;

      if (1 == l_peek.m_octets)
        {
          l_chr = l_peek.m_block[0];

          switch (i_base)
            {
            case mjo_lexer_base_octal:
              l_bool = ((mjo_r7_0 >= l_chr) && (mjo_r7_7 <= l_chr));
              break;
            case mjo_lexer_base_hexidecimal:
              l_bool
                = (((mjo_r7_0 >= l_chr) && (mjo_r7_9 <= l_chr))
                   || ((mjo_r7_lwr_a >= l_chr) && (mjo_r7_lwr_f <= l_chr))
                   || ((mjo_r7_upr_a >= l_chr) && (mjo_r7_upr_f <= l_chr)));
              break;
            case mjo_lexer_base_invalid:
              break;
            }
        }

      if (0 == l_bool)
        {
          mjo_istream_push(io_stream, &l_peek);
          break;
        }

      if (sizeof(l_buf) > l_slot)
        {
          *l_ptr++ = l_peek.m_block[0];
        }

      l_slot++;
    }
  while (1);

  *l_ptr = 0;

  if ((MJO_OK == l_rc)
      && ((mjo_status_ok == *o_status) || (mjo_status_eof == *o_status)))
    {
      if (sizeof(l_buf) > l_slot)
        {
          l_rc = _convert(o_status, o_peek, l_buf, i_base);
        }
      else
        {
          *o_status = mjo_status_truncated;
          errno = E2BIG;
          l_rc = MJO_FAIL;
        }
    }

  return l_rc;
}

extern int
  _mjo_lexer_read_escape(enum mjo_status *const o_status,
                         struct mjo_lexer_token *const o_token,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream)
{
  int l_rc;
  enum mjo_lexer_base l_base;

  do
    {
      l_rc = _mjo_lexer_read_stream(o_status, o_token, io_lexer, io_stream);

      if (l_rc || o_status)
        {
          break;
        }

      if (1 != o_token->m_peek.m_octets)
        {
          break;
        }

      l_base = mjo_lexer_base_invalid;

      switch (o_token->m_peek.m_block[0])
        {
        case mjo_r7_lwr_a:
          o_token->m_peek.m_block[0] = mjo_r7_bel;
          break;
        case mjo_r7_lwr_b:
          o_token->m_peek.m_block[0] = mjo_r7_bs;
          break;
        case mjo_r7_lwr_e:
          o_token->m_peek.m_block[0] = mjo_r7_esc;
          break;
        case mjo_r7_lwr_f:
          o_token->m_peek.m_block[0] = mjo_r7_ff;
          break;
        case mjo_r7_lwr_n:
          o_token->m_peek.m_block[0] = mjo_r7_lf;
          break;
        case mjo_r7_lwr_r:
          o_token->m_peek.m_block[0] = mjo_r7_cr;
          break;
        case mjo_r7_lwr_t:
          o_token->m_peek.m_block[0] = mjo_r7_ht;
          break;
        case mjo_r7_lwr_v:
          o_token->m_peek.m_block[0] = mjo_r7_vt;
          break;
        case mjo_r7_0:
        case mjo_r7_1:
        case mjo_r7_2:
        case mjo_r7_3:
        case mjo_r7_4:
        case mjo_r7_5:
        case mjo_r7_6:
        case mjo_r7_7:
        case mjo_r7_8:
        case mjo_r7_9:
          l_base = mjo_lexer_base_octal;
          break;
        case mjo_r7_lwr_x:
        case mjo_r7_lwr_u:
        case mjo_r7_upr_u:
          l_base = mjo_lexer_base_hexidecimal;
          break;
        }

      if (mjo_lexer_base_invalid == l_base)
        {
          break;
        }

      l_rc = _mjo_lexer_base_read(
        o_status, &o_token->m_peek, io_lexer, io_stream, l_base);
    }
  while (0);

  if ((MJO_OK == l_rc) && (mjo_status_ok == *o_status))
    {
      o_token->m_class = mjo_lexer_class_regular;
    }

  return l_rc;
}
