/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstdlib.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mstdlib_h__)

#  include <stddef.h>
#  include <stdlib.h>

enum
{
  MJO_FAIL = (-1),
  MJO_OK = (0)
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_abort(int const);

  extern int
    mjo_add_size_t(size_t *const, size_t const, size_t const);

  extern void
    mjo_calloc(void **const, size_t const, size_t const);

  extern void
    mjo_free(void **const);

  extern void
    mjo_malloc(void **const, size_t const, size_t const);

  extern void
    mjo_realloc(void **const, size_t const, size_t const);

  extern int
    mjo_mul_size_t(size_t *const, size_t const, size_t const);

  extern int
    mjo_path_full(unsigned char **const, unsigned char const *);

  extern void
    mjo_path_join(unsigned char **const,
                  unsigned char const *,
                  unsigned char const *,
                  unsigned char const *);

  extern int
    mjo_search_binary(int *const,
                      size_t *const,
                      void const *,
                      size_t const,
                      size_t const,
                      void (*)(int *const, void const *, void const *),
                      void const *const);

  extern int
    mjo_search_binary_user(
      int *const,
      size_t *const,
      void const *,
      size_t const,
      size_t const,
      void (*)(int *const, void *, void const *, void const *),
      void const *const,
      void *);

  extern void
    mjo_strdup(unsigned char const **const, unsigned char const *);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_mem_abort(int const, char const *, size_t const);

  extern void
    mjo_mem_calloc(
      void **const, size_t const, size_t const, char const *, size_t const);

  extern void
    mjo_mem_free(void **const, char const *, size_t const);

  extern void
    mjo_mem_malloc(
      void **const, size_t const, size_t const, char const *, size_t const);

  extern void
    mjo_mem_path_join(unsigned char **const,
                      unsigned char const *,
                      unsigned char const *,
                      unsigned char const *,
                      char const *,
                      size_t const);

  extern void
    mjo_mem_realloc(
      void **const, size_t const, size_t const, char const *, size_t const);

  extern void
    mjo_mem_strdup(unsigned char **const,
                   unsigned char const *,
                   char const *,
                   size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_abort(i_code)                                                   \
    do                                                                        \
      {                                                                       \
        mjo_mem_abort((i_code), __FILE__, __LINE__);                          \
      }                                                                       \
    while (0)

#  define mjo_calloc(o_obj, i_obj_count, i_obj_size)                          \
    do                                                                        \
      {                                                                       \
        mjo_mem_calloc(                                                       \
          (o_obj), (i_obj_count), (i_obj_size), __FILE__, __LINE__);          \
      }                                                                       \
    while (0)

#  define mjo_free(io_obj)                                                    \
    do                                                                        \
      {                                                                       \
        mjo_mem_free((io_obj), __FILE__, __LINE__);                           \
      }                                                                       \
    while (0)

#  define mjo_malloc(o_obj, i_obj_count, i_obj_size)                          \
    do                                                                        \
      {                                                                       \
        mjo_mem_malloc(                                                       \
          (o_obj), (i_obj_count), (i_obj_size), __FILE__, __LINE__);          \
      }                                                                       \
    while (0)

#  define mjo_path_join(o_obj, i_prefix, i_name, i_suffix)                    \
    do                                                                        \
      {                                                                       \
        mjo_mem_path_join(                                                    \
          (o_obj), (i_prefix), (i_name), (i_suffix), __FILE__, __LINE__);     \
      }                                                                       \
    while (0)

#  define mjo_realloc(io_obj, i_obj_count, i_obj_size)                        \
    do                                                                        \
      {                                                                       \
        mjo_mem_realloc(                                                      \
          (io_obj), (i_obj_count), (i_obj_size), __FILE__, __LINE__);         \
      }                                                                       \
    while (0)

#  define mjo_strdup(o_dup, i_str)                                            \
    do                                                                        \
      {                                                                       \
        mjo_mem_strdup((o_dup), (i_str), __FILE__, __LINE__);                 \
      }                                                                       \
    while (0)

#  define __mstdlib_h__
#endif
