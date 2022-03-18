/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_lexer.h).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__lexer_h__)

#  include "mlexer.h"

struct mjo_lexer
{
  struct mjo_lexer_token m_queue;
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern int
    _mjo_lexer_read_stream(enum mjo_status *const,
                           struct mjo_lexer_token *const,
                           mjo_lexer_t const,
                           mjo_istream_t const);

  extern int
    _mjo_lexer_read_escape(enum mjo_status *const,
                           struct mjo_lexer_token *const,
                           mjo_lexer_t const,
                           mjo_istream_t const);

#  if defined(__cplusplus)
}
#  endif

#  define __lexer_h__
#endif
