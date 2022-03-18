/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_vector.h).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_UTF8C_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__vector_h__)

#  include "mvector.h"

struct mjo_vector_arena
{
  enum mjo_vector_variant m_variant;
  size_t m_allocated;
  size_t m_size;
  size_t m_count;
  void (*m_discharge)(void **const);
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern struct mjo_vector_arena *const _mjo_vector_ptr_to_arena(mjo_vector_t);

  extern mjo_vector_t const
    _mjo_vector_arena_to_ptr(struct mjo_vector_arena *);

  extern int
    _mjo_vector_mem_grow(mjo_vector_t *const,
                         size_t,
                         char const *,
                         size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define _mjo_vector_ptr_to_arena(obj)                                       \
    (((struct mjo_vector_arena *)(obj)) - 1)

#  define _mjo_vector_arena_to_ptr(obj)                                       \
    (mjo_vector_t)(((struct mjo_vector_arena *)(obj)) + 1)

#  define __vector_h__
#endif
