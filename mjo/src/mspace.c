/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mspace.c).
 This work is published from: United States.

 This file is part of the mjo library.

 Ful text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mstddef.h"
#include "mstdlib.h"
#include "mutf8.h"

/* table generated from util/mjo_utf8_space.cpp */
struct mjo_utf8 g_utf8_space_table[] = {
  { 1, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+00000009 horizontal tab */, 0, 1 },
  { 1, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+0000000a line feed */, 0, 1 },
  { 1, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+0000000b vertical tab */, 0, 1 },
  { 1, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+0000000c form feed */, 0, 1 },
  { 1, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+0000000d carriage return */, 0, 1 },
  { 1, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+00000020 space */, 0, 1 },
  { 1, 0xc2, 0x85, 0x00, 0x00, 0x00, 0x00 /*u+00000085 next line */, 0, 2 },
  { 1, 0xc2, 0xa0, 0x00, 0x00, 0x00, 0x00 /*u+000000a0 no-break space */, 0, 2 },
  { 1,
    0xe1,
    0x9a,
    0x80,
    0x00,
    0x00,
    0x00 /*u+00001680 ogham space mark */,
    0,
    3 },
  { 1,
    0xe1,
    0xa0,
    0x8e,
    0x00,
    0x00,
    0x00 /*u+0000180e mongolian vowel separator */,
    0,
    3 },
  { 1, 0xe2, 0x80, 0x80, 0x00, 0x00, 0x00 /*u+00002000 en quad */, 0, 3 },
  { 1, 0xe2, 0x80, 0x81, 0x00, 0x00, 0x00 /*u+00002001 em quad */, 0, 3 },
  { 1, 0xe2, 0x80, 0x82, 0x00, 0x00, 0x00 /*u+00002002 en space */, 0, 3 },
  { 1, 0xe2, 0x80, 0x83, 0x00, 0x00, 0x00 /*u+00002003 em space */, 0, 3 },
  { 1,
    0xe2,
    0x80,
    0x84,
    0x00,
    0x00,
    0x00 /*u+00002004 three-per-em space */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x85,
    0x00,
    0x00,
    0x00 /*u+00002005 four-per-em space */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x86,
    0x00,
    0x00,
    0x00 /*u+00002006 six-per-em space */,
    0,
    3 },
  { 1, 0xe2, 0x80, 0x87, 0x00, 0x00, 0x00 /*u+00002007 figure space */, 0, 3 },
  { 1,
    0xe2,
    0x80,
    0x88,
    0x00,
    0x00,
    0x00 /*u+00002008 spaceuation space */,
    0,
    3 },
  { 1, 0xe2, 0x80, 0x89, 0x00, 0x00, 0x00 /*u+00002009 thin space */, 0, 3 },
  { 1, 0xe2, 0x80, 0x8a, 0x00, 0x00, 0x00 /*u+0000200a hair space */, 0, 3 },
  { 1,
    0xe2,
    0x80,
    0x8b,
    0x00,
    0x00,
    0x00 /*u+0000200b zero width space */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x8c,
    0x00,
    0x00,
    0x00 /*u+0000200c zero width non-joiner */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x8d,
    0x00,
    0x00,
    0x00 /*u+0000200d zero width joiner */,
    0,
    3 },
  { 1, 0xe2, 0x80, 0xa8, 0x00, 0x00, 0x00 /*u+00002028 line separator */, 0, 3 },
  { 1,
    0xe2,
    0x80,
    0xa9,
    0x00,
    0x00,
    0x00 /*u+00002029 paragraph separator */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0xaf,
    0x00,
    0x00,
    0x00 /*u+0000202f narrow no-break space */,
    0,
    3 },
  { 1,
    0xe2,
    0x81,
    0x9f,
    0x00,
    0x00,
    0x00 /*u+0000205f medium mathematical space */,
    0,
    3 },
  { 1, 0xe2, 0x81, 0xa0, 0x00, 0x00, 0x00 /*u+00002060 word joiner */, 0, 3 },
  { 1,
    0xe3,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00 /*u+00003000 ideographic space */,
    0,
    3 },
  { 1,
    0xef,
    0xbb,
    0xbf,
    0x00,
    0x00,
    0x00 /*u+0000feff zero width non-breaking space */,
    0,
    3 }
};

static void
  _mjo_utf8_is_whitespace(int *const o_is_space,
                          struct mjo_utf8 const *const i_peek)
{
  size_t l_slots;

  l_slots = (sizeof(g_utf8_space_table) / sizeof(g_utf8_space_table[0]));

  mjo_search_binary(
    o_is_space,
    0,
    (void const *)g_utf8_space_table,
    sizeof(struct mjo_utf8),
    l_slots,
    (void (*)(int *const, void const *, void const *))mjo_utf8_compare,
    (void const *const *)i_peek);

  return;
}

extern int
  mjo_utf8_is_whitespace(int *const o_is_space,
                         struct mjo_utf8 const *const i_peek)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == o_is_space)
        {
          errno = EINVAL;
          break;
        }

      l_rc = MJO_OK;

      *o_is_space = 0;

      if (0 == i_peek)
        {
          break;
        }

      if (0 == i_peek->m_legal)
        {
          break;
        }

      _mjo_utf8_is_whitespace(o_is_space, i_peek);

      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}
