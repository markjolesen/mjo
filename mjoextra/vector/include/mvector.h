/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mvector.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mvector_h__)

#  include <stddef.h>

enum
{
  mjo_vector_size_auto = 0
};

enum mjo_vector_variant
{
  mjo_vector_variant_struct = 0,
  mjo_vector_variant_ptrstr,
  mjo_vector_variant_char,
  mjo_vector_variant_short,
  mjo_vector_variant_ushort,
  mjo_vector_variant_bool,
  mjo_vector_variant_int,
  mjo_vector_variant_uint,
  mjo_vector_variant_long,
  mjo_vector_variant_ulong,
  mjo_vector_variant_size_t,
  mjo_vector_variant_ptrdiff_t,
  mjo_vector_variant_double
};

typedef void *mjo_vector_t;

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void mjo_vector_clear(mjo_vector_t);

  extern size_t
    mjo_vector_count(const mjo_vector_t);

  extern void mjo_vector_dequeue(mjo_vector_t);

  extern void
    mjo_vector_free(mjo_vector_t *const);

  extern void
    mjo_vector_malloc(mjo_vector_t *const,
                      size_t const,
                      enum mjo_vector_variant const,
                      size_t const,
                      void (*)(void **const));

  extern int
    mjo_vector_permute_push(mjo_vector_t *const, unsigned char const *);

  extern void mjo_vector_pop(mjo_vector_t);

  extern void
    mjo_vector_push(mjo_vector_t *const, void const *, size_t const);

  extern enum mjo_vector_variant
    mjo_vector_type(const mjo_vector_t);

  extern void
    mjo_vector_variant_discharge_free(void **const);

  extern unsigned char const *
    mjo_vector_variant_tag(enum mjo_vector_variant const);

#  if defined(__cplusplus)
}
#  endif

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern void
    mjo_vector_mem_free(mjo_vector_t *const, char const *, size_t const);

  extern void
    mjo_vector_mem_malloc(mjo_vector_t *const,
                          size_t const,
                          enum mjo_vector_variant const,
                          size_t const,
                          void (*)(void **const),
                          char const *,
                          size_t const);
  extern int
    mjo_vector_mem_permute_push(mjo_vector_t *const,
                                unsigned char const *,
                                char const *,
                                size_t const);
  extern int
    mjo_vector_mem_push(mjo_vector_t *const,
                        void const *,
                        size_t const,
                        char const *,
                        size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define mjo_vector_free(io_obj)                                             \
    do                                                                        \
      {                                                                       \
        mjo_vector_mem_free((io_obj), __FILE__, __LINE__);                    \
      }                                                                       \
    while (0)

#  define mjo_vector_malloc(                                                  \
    o_obj, i_obj_count, i_variant, i_size_struct, i_discharge)                \
    do                                                                        \
      {                                                                       \
        mjo_vector_mem_malloc((o_obj),                                        \
                              (i_obj_count),                                  \
                              (i_variant),                                    \
                              (i_size_struct),                                \
                              (i_discharge),                                  \
                              __FILE__,                                       \
                              __LINE__);                                      \
      }                                                                       \
    while (0)

#  define mjo_vector_permute_push(io_obj, i_str)                              \
    mjo_vector_mem_permute_push((io_obj), (i_str), __FILE__, __LINE__)

#  define mjo_vector_push(io_obj, i_obj, i_obj_count)                         \
    mjo_vector_mem_push((io_obj), (i_obj), (i_obj_count), __FILE__, __LINE__);

#  define __mvector_h__
#endif
