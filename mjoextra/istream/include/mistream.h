/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mistream.h).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mistream_h__)

#  include <mstdio.h>
#  include <mutf8.h>

enum mjo_istream_option
{
  mjo_istream_option_none = 0
};

typedef struct mjo_istream *mjo_istream_t;

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_istream_file_malloc(mjo_istream_t *const,
                            enum mjo_istream_option const,
                            mjo_read_t const,
                            mjo_handle_t const);

  extern void
    mjo_istream_free(mjo_istream_t *const);

  extern void
    mjo_istream_block_malloc(mjo_istream_t *const,
                             enum mjo_istream_option const,
                             void const *,
                             size_t const);

  extern void
    mjo_istream_push(mjo_istream_t const, struct mjo_utf8 const *const);

  extern int
    mjo_istream_read(enum mjo_status *const,
                     struct mjo_utf8 *const,
                     mjo_istream_t const);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_istream_file_mem_malloc(mjo_istream_t *const,
                                enum mjo_istream_option const,
                                mjo_read_t const,
                                mjo_handle_t const,
                                char const *,
                                size_t const);

  extern void
    mjo_istream_mem_free(mjo_istream_t *const, char const *, size_t const);

  extern void
    mjo_istream_block_mem_malloc(mjo_istream_t *const,
                                 enum mjo_istream_option const,
                                 void const *,
                                 size_t const,
                                 char const *,
                                 size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_istream_free(io_stream)                                         \
    do                                                                        \
      {                                                                       \
        mjo_istream_mem_free((io_stream), __FILE__, __LINE__);                \
      }                                                                       \
    while (0)

#  define mjo_istream_file_malloc(o_stream, i_option, i_read, i_handle)       \
    do                                                                        \
      {                                                                       \
        mjo_istream_file_mem_malloc(                                          \
          (o_stream), (i_option), (i_read), (i_handle), __FILE__, __LINE__);  \
      }                                                                       \
    while (0)

#  define mjo_istream_block_malloc(o_stream, i_option, i_block, i_octets)     \
    do                                                                        \
      {                                                                       \
        mjo_istream_block_mem_malloc(                                         \
          (o_stream), (i_option), (i_block), (i_octets), __FILE__, __LINE__); \
      }                                                                       \
    while (0)

#  define __mistream_h__
#endif
