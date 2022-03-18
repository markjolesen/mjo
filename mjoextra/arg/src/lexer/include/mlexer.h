/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mlexer.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mlexer_h__)

#  include <mistream.h>

enum mjo_lexer_class
{
  mjo_lexer_class_invalid = 0,
  mjo_lexer_class_regular,
  mjo_lexer_class_include,
  mjo_lexer_class_short,
  mjo_lexer_class_long,
  mjo_lexer_class_separator,
  mjo_lexer_class_whitespace,
  mjo_lexer_class_punctuation,
};

struct mjo_lexer_token
{
  enum mjo_lexer_class m_class;
  struct mjo_utf8 m_peek;
};

typedef struct mjo_lexer *mjo_lexer_t;

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_lexer_free(mjo_lexer_t *const);

  extern void
    mjo_lexer_malloc(mjo_lexer_t *const);

  extern void
    mjo_lexer_push(mjo_lexer_t const, struct mjo_lexer_token const *const);

  extern int
    mjo_lexer_read(enum mjo_status *const,
                   struct mjo_lexer_token *const,
                   mjo_lexer_t const,
                   mjo_istream_t const);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_lexer_mem_free(mjo_lexer_t *const, char const *, size_t const);

  extern void
    mjo_lexer_mem_malloc(mjo_lexer_t *const, char const *, size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_lexer_free(io_obj)                                              \
    do                                                                        \
      {                                                                       \
        mjo_lexer_mem_free((io_obj), __FILE__, __LINE__);                     \
      }                                                                       \
    while (0)

#  define mjo_lexer_malloc(o_obj)                                             \
    do                                                                        \
      {                                                                       \
        mjo_lexer_mem_malloc((o_obj), __FILE__, __LINE__);                    \
      }                                                                       \
    while (0)

#  define __mlexer_h__
#endif
