/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_arg.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__arg_h__)

#  include <mistream.h>
/**/
#  include "marg.h"
#  include "mlexer.h"

enum mjo_arg_option_internal
{
  mjo_arg_option_internal_invalid = 0,
  mjo_arg_option_internal_operand
};

struct mjo_arg_option
{
  enum mjo_arg_option_mask m_option_mask;
  unsigned char *m_attribute;
  unsigned char *m_description;
  enum mjo_arg_argument_mask m_argument_mask;
  mjo_vector_t m_arg;
  struct mjo_arg_option *m_next;
};

enum
{
  mjo_arg_include_depth_max = 5,
  mjo_arg_buckets_max = 400
};

struct mjo_arg
{
  enum mjo_arg_rule_mask m_rule_mask;
  struct mjo_arg_option *m_bucket[mjo_arg_buckets_max];
  mjo_vector_t m_include;
  size_t m_include_depth;
  mjo_vector_t m_scratch;
  struct
  {
    FILE *m_elog;
    size_t m_errors;
    int m_errno_last;
  } m_diag;
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    _mjo_arg_argument_missing(int *const, mjo_arg_t const);

  extern int
    _mjo_arg_argument_push(struct mjo_arg_option *const,
                           mjo_arg_t const,
                           unsigned char const *);

  extern int
    _mjo_arg_argument_read(struct mjo_arg_option *const io_option,
                           mjo_arg_t const io_arg,
                           mjo_lexer_t const io_lexer,
                           mjo_istream_t const io_stream);

  extern struct mjo_arg_option *const
    _mjo_arg_lookup(const mjo_arg_t, unsigned char const *);

  extern void
    _mjo_arg_option_attribute_validate(int *const o_valid,
                                       unsigned char const *i_attribute);

  extern unsigned char const *
    mjo_arg_option_internal_to_str(enum mjo_arg_option_internal const);

  extern enum mjo_arg_option_internal
    mjo_arg_option_str_to_internal(unsigned char const *);

  extern int
    _mjo_arg_parse_include(mjo_arg_t const io_arg,
                           mjo_lexer_t const io_lexer,
                           mjo_istream_t const io_stream);

  extern int
    _mjo_arg_parse_long(mjo_arg_t const io_arg,
                        mjo_lexer_t const io_lexer,
                        mjo_istream_t const io_stream);

  extern int
    _mjo_arg_parse_operand(mjo_arg_t const io_arg,
                           mjo_lexer_t const io_lexer,
                           mjo_istream_t const io_stream);

  extern int
    _mjo_arg_parse_short(mjo_arg_t const io_arg,
                         mjo_lexer_t const io_lexer,
                         mjo_istream_t const io_stream);

  extern struct mjo_arg_option const *
    mjo_arg_vector_malloc(size_t *const, const mjo_arg_t);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern struct mjo_arg_option *const *const
    mjo_arg_vector_mem_malloc(size_t *const,
                              const mjo_arg_t,
                              char const *,
                              size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_arg_vector_malloc(o_slots, i_obj)                               \
    mjo_arg_vector_mem_malloc((o_slots), (i_obj), __FILE__, __LINE__)

#  define __arg_h__
#endif
