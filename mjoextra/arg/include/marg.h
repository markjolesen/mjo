/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (marg.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__marg_h__)

#  include <mstdio.h>
/**/
#  include <mistream.h>
#  include <mvector.h>

#  define mjo_arg_option_internal_operand_str ".OPERAND"

enum mjo_arg_option_mask
{
  mjo_arg_option_mask_short = 0x0000,
  mjo_arg_option_mask_long = 0x0001,
  mjo_arg_option_mask_required_no = 0x0000,
  mjo_arg_option_mask_required = 0x0010,
  mjo_arg_option_mask_vector_no = 0x0000,
  mjo_arg_option_mask_vector = 0x0100
};

enum mjo_arg_argument_mask
{
  mjo_arg_argument_mask_required_no = 0x000,
  mjo_arg_argument_mask_required = 0x0001
};

enum mjo_arg_rule_mask
{
  mjo_arg_rule_mask_none = 0x0000,
  mjo_arg_rule_mask_on_error_keep_going = 0x0100,
  mjo_arg_rule_mask_on_error_suppress_message = 0x0200
};

typedef struct mjo_arg *mjo_arg_t;

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_arg_free(mjo_arg_t *const);

  extern void
    mjo_arg_malloc(mjo_arg_t *const, enum mjo_arg_rule_mask const);

  extern int
    mjo_arg_option(mjo_arg_t const,
                   enum mjo_arg_option_mask const,
                   unsigned char const *,
                   unsigned char const *,
                   enum mjo_arg_argument_mask const,
                   enum mjo_vector_variant const);

  extern int
    mjo_arg_parse(mjo_arg_t const, mjo_istream_t const);

  extern int
    mjo_arg_parse_block(mjo_arg_t const, void const *, size_t const);

  extern int
    mjo_arg_parse_file(mjo_arg_t const, unsigned char const *);

  extern int
    mjo_arg_parse_vector(mjo_arg_t const,
                         unsigned char *const *const,
                         size_t const);
  extern void
    mjo_arg_print(FILE *const, const mjo_arg_t i_arg);

  extern mjo_vector_t
    mjo_arg_value(size_t *const, const mjo_arg_t, unsigned char const *);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_arg_mem_free(mjo_arg_t *const, char const *, size_t const);

  extern void
    mjo_arg_mem_malloc(mjo_arg_t *const,
                       enum mjo_arg_rule_mask const,
                       char const *,
                       size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_arg_free(io_obj)                                                \
    do                                                                        \
      {                                                                       \
        mjo_arg_mem_free((io_obj), __FILE__, __LINE__);                       \
      }                                                                       \
    while (0)

#  define mjo_arg_malloc(o_obj, i_rule_mask)                                  \
    do                                                                        \
      {                                                                       \
        mjo_arg_mem_malloc((o_obj), (i_rule_mask), __FILE__, __LINE__);       \
      }                                                                       \
    while (0)

#  define __marg_h__
#endif
