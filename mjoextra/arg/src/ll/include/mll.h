/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mll.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mll_h__)

#  include <mistream.h>
#  include <mlexer.h>
#  include <mvector.h>

enum mjo_ll_action
{
  mjo_ll_action_scan_to_whitespace = 0,
  mjo_ll_action_scan_to_non_whitespace
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_ll_acquiesce(mjo_lexer_t const, mjo_istream_t const);

  extern int
    mjo_ll_read_argument(enum mjo_status *const,
                         mjo_vector_t *const,
                         mjo_lexer_t const,
                         mjo_istream_t const);

  extern int
    mjo_ll_read_include(enum mjo_status *const,
                        mjo_vector_t *const,
                        mjo_lexer_t const,
                        mjo_istream_t const);

  extern int
    mjo_ll_read_operand(enum mjo_status *const,
                        mjo_vector_t *const,
                        mjo_lexer_t const,
                        mjo_istream_t const);

  extern int
    mjo_ll_read_option_long(enum mjo_status *const,
                            mjo_vector_t *const,
                            mjo_lexer_t const,
                            mjo_istream_t const);

  extern int
    mjo_ll_read_option_short(enum mjo_status *const,
                             mjo_vector_t *const,
                             mjo_lexer_t const,
                             mjo_istream_t const);

  extern int
    mjo_ll_scan_separator(int *const,
                          enum mjo_status *const,
                          mjo_lexer_t const,
                          mjo_istream_t const);

  extern int
    mjo_ll_scan_whitespace(enum mjo_status *const,
                           mjo_lexer_t const,
                           mjo_istream_t const,
                           enum mjo_ll_action const);

#  if defined(__cplusplus)
}
#  endif

#  define __mll_h__
#endif
