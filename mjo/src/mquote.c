/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mquote.c).
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

/* table generated from util/mjo_utf8_quote.cpp */
struct mjo_utf8 g_utf8_quote_table[] = {
  { 1, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+00000022 quotation mark */, 0, 1 },
  { 1, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00 /*u+00000027 apostrophe (') */, 0, 1 },
  { 1,
    0xc2,
    0xab,
    0x00,
    0x00,
    0x00,
    0x00 /*u+000000ab left-pointing double-angle quotation mark */,
    0,
    2 },
  { 1,
    0xc2,
    0xbb,
    0x00,
    0x00,
    0x00,
    0x00 /*u+000000bb right-pointing double-angle quotation mark */,
    0,
    2 },
  { 1,
    0xe2,
    0x80,
    0x98,
    0x00,
    0x00,
    0x00 /*u+00002018 left single quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x99,
    0x00,
    0x00,
    0x00 /*u+00002019 right single quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9a,
    0x00,
    0x00,
    0x00 /*u+0000201a single low-9 quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9b,
    0x00,
    0x00,
    0x00 /*u+0000201b single high-reversed-9 quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9c,
    0x00,
    0x00,
    0x00 /*u+0000201c left double quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9d,
    0x00,
    0x00,
    0x00 /*u+0000201d right double quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9e,
    0x00,
    0x00,
    0x00 /*u+0000201e double low-9 quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0x9f,
    0x00,
    0x00,
    0x00 /*u+0000201f double high-reversed-9 quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0xb9,
    0x00,
    0x00,
    0x00 /*u+00002039 single left-pointing angle quotation mark */,
    0,
    3 },
  { 1,
    0xe2,
    0x80,
    0xba,
    0x00,
    0x00,
    0x00 /*u+0000203a single right-pointing angle quotation mark */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x8c,
    0x00,
    0x00,
    0x00 /*u+0000300c left corner bracket */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x8d,
    0x00,
    0x00,
    0x00 /*u+0000300d right corner bracket */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x8e,
    0x00,
    0x00,
    0x00 /*u+0000300e left white corner bracket */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x8f,
    0x00,
    0x00,
    0x00 /*u+0000300f right white corner bracket */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x9d,
    0x00,
    0x00,
    0x00 /*u+0000301d reversed double prime quotation mark */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x9e,
    0x00,
    0x00,
    0x00 /*u+0000301e double prime quotation mark */,
    0,
    3 },
  { 1,
    0xe3,
    0x80,
    0x9f,
    0x00,
    0x00,
    0x00 /*u+0000301f low double prime quotation mark */,
    0,
    3 },
  { 1,
    0xef,
    0xb9,
    0x81,
    0x00,
    0x00,
    0x00 /*u+0000fe41 presentation form for vertical left corner bracket */,
    0,
    3 },
  { 1,
    0xef,
    0xb9,
    0x82,
    0x00,
    0x00,
    0x00 /*u+0000fe42 presentation form for vertical right corner bracket */,
    0,
    3 },
  { 1,
    0xef,
    0xb9,
    0x83,
    0x00,
    0x00,
    0x00 /*u+0000fe43 presentation form for vertical left corner white bracket */,
    0,
    3 },
  { 1,
    0xef,
    0xb9,
    0x84,
    0x00,
    0x00,
    0x00 /*u+0000fe44 presentation form for vertical right corner white bracket */,
    0,
    3 },
  { 1,
    0xef,
    0xbc,
    0x82,
    0x00,
    0x00,
    0x00 /*u+0000ff02 fullwidth quotation mark */,
    0,
    3 },
  { 1,
    0xef,
    0xbc,
    0x87,
    0x00,
    0x00,
    0x00 /*u+0000ff07 fullwidth apostrophe */,
    0,
    3 },
  { 1,
    0xef,
    0xbd,
    0xa2,
    0x00,
    0x00,
    0x00 /*u+0000ff62 halfwidth left corner bracket */,
    0,
    3 },
  { 1,
    0xef,
    0xbd,
    0xa3,
    0x00,
    0x00,
    0x00 /*u+0000ff63 halfwidth right corner bracket */,
    0,
    3 },
};

static void
  _mjo_utf8_is_quote(int *const o_is_quote,
                     struct mjo_utf8 const *const i_peek)
{
  size_t l_slots;

  l_slots = (sizeof(g_utf8_quote_table) / sizeof(g_utf8_quote_table[0]));

  mjo_search_binary(
    o_is_quote,
    0,
    (void const *)g_utf8_quote_table,
    sizeof(struct mjo_utf8),
    l_slots,
    (void (*)(int *const, void const *, void const *))mjo_utf8_compare,
    (void const *const *)i_peek);

  return;
}

extern int
  mjo_utf8_is_quote(int *const o_is_quote, struct mjo_utf8 const *const i_peek)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == o_is_quote)
        {
          errno = EINVAL;
          break;
        }

      l_rc = MJO_OK;
      *o_is_quote = 0;

      if (0 == i_peek)
        {
          break;
        }

      if (0 == i_peek->m_legal)
        {
          break;
        }

      _mjo_utf8_is_quote(o_is_quote, i_peek);

      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}
