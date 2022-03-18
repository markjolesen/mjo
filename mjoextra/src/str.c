/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (str.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "mstr.h"

extern int
  mjo_str_to_bool(int *const o_value, unsigned char const *i_str)
{
  int l_value;

  if ((0 == i_str) || (0 == i_str[0]))
    {
      l_value = 0;
    }
  else if (0 == i_str[1])
    {
      switch (i_str[0])
        {
        case mjo_r7_1:
        case mjo_r7_lwr_t:
        case mjo_r7_upr_t:
          l_value = 1;
          break;
        default:
          l_value = 0;
          break;
        }
    }
  else if (mjo_r7_lwr_o == i_str[0] || mjo_r7_upr_o == i_str[0])
    {
      if (mjo_r7_lwr_n == i_str[1] || mjo_r7_upr_n == i_str[1])
        {
          l_value = 1;
        }
      else
        {
          l_value = 0;
        }
    }
  else
    {
      l_value = 0;
    }

  if (o_value)
    {
      *o_value = l_value;
    }

  return MJO_OK;
}

extern int
  mjo_str_to_double(double *const o_value, unsigned char const *i_str)
{
#if !defined(__DOS__)
  long double l_value;
#else
  double l_value;
#endif
  char *l_ptr;
  int l_rc;

  explicit_bzero(&l_value, sizeof(l_value));
  l_rc = MJO_OK;

  do
    {
      if ((0 == i_str) || (0 == *i_str))
        {
          break;
        }

      errno = 0;
#if !defined(__DOS__)
      l_value = strtold((char const *)i_str, &l_ptr);
#else
      l_value = strtod((char const *)i_str, &l_ptr);
#endif

      if ((ERANGE == errno) || (*l_ptr)
          || ((ptrdiff_t)i_str == (ptrdiff_t)l_ptr) || (DBL_MIN > l_value)
          || (DBL_MAX < l_value))
        {
          l_value = DBL_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
  while (0);

  if (o_value)
    {
      *o_value = (double)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_long(long *const o_value, unsigned char const *i_str)
{
  int l_rc;
#if defined(LLONG_MAX)
  long long l_value;
#else
  long l_value
#endif
  char *l_ptr;

  explicit_bzero(&l_value, sizeof(l_value));
  l_rc = MJO_OK;

  do
    {
      if ((0 == i_str) || (0 == *i_str))
        {
          break;
        }

      errno = 0;
#if defined(LLONG_MAX)
      l_value = strtoll((char *)i_str, &l_ptr, 0);
#else
      l_value = strtol((char *)i_str, &l_ptr, 0);
#endif

      if ((ERANGE == errno) || (*l_ptr)
          || ((ptrdiff_t)i_str == (ptrdiff_t)l_ptr) || (LONG_MIN > l_value)
          || (LONG_MAX < l_value))
        {
          l_value = LONG_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
  while (0);

  if (o_value)
    {
      *o_value = (long)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_ulong(unsigned long *const o_value, unsigned char const *i_str)
{
  int l_rc;
#if defined(LLONG_MAX)
  unsigned long long l_value;
#else
  unsigned long l_value;
#endif
  char *l_ptr;

  explicit_bzero(&l_value, sizeof(l_value));
  l_rc = MJO_OK;

  do
    {
      if ((0 == i_str) || (0 == *i_str))
        {
          break;
        }

      errno = 0;
#if defined(LLONG_MAX)
      l_value = strtoull((char *)i_str, &l_ptr, 0);
#else
      l_value = strtoul((char *)i_str, &l_ptr, 0);
#endif

      if ((ERANGE == errno) || (*l_ptr)
          || ((ptrdiff_t)i_str == (ptrdiff_t)l_ptr) || (LONG_MAX < l_value))
        {
          l_value = LONG_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
  while (0);

  if (o_value)
    {
      *o_value = (long)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_size_t(size_t *const o_value, unsigned char const *i_str)
{
  int l_rc;
  unsigned long l_value;

  l_rc = mjo_str_to_ulong(&l_value, i_str);

  do
    {
      if (l_rc)
        {
          break;
        }

#if (LONG_WIDTH != SIZE_WIDTH)
      if (SIZE_MAX < l_value)
        {
          l_value = SIZE_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
#endif
    }
  while (0);

  if (o_value)
    {
      *o_value = l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_ptrdiff_t(ptrdiff_t *const o_value, unsigned char const *i_str)
{
  int l_rc;
#if defined(LLONG_MAX)
  long long l_value;
#else
  long l_value
#endif
  char *l_ptr;

  explicit_bzero(&l_value, sizeof(l_value));
  l_rc = MJO_OK;

  do
    {
      if ((0 == i_str) || (0 == *i_str))
        {
          break;
        }

      errno = 0;
#if defined(LLONG_MAX)
      l_value = strtoll((char *)i_str, &l_ptr, 0);
#else
      l_value = strtol((char *)i_str, &l_ptr, 0);
#endif

      if ((ERANGE == errno) || (*l_ptr)
          || ((ptrdiff_t)i_str == (ptrdiff_t)l_ptr) || (PTRDIFF_MIN > l_value)
          || (PTRDIFF_MAX < l_value))
        {
          l_value = PTRDIFF_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
  while (0);

  if (o_value)
    {
      *o_value = (ptrdiff_t)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_short(short *const o_value, unsigned char const *i_str)
{
  int l_rc;
  long l_value;

  l_rc = mjo_str_to_long(&l_value, i_str);

  if (MJO_OK == l_rc)
    {
      if ((SHRT_MIN > l_value) || (SHRT_MAX < l_value))
        {
          l_value = SHRT_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }

  if (o_value)
    {
      *o_value = (short)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_ushort(unsigned short *const o_value, unsigned char const *i_str)
{
  int l_rc;
  unsigned long l_value;

  l_rc = mjo_str_to_ulong(&l_value, i_str);

  if (MJO_OK == l_rc)
    {
      if (USHRT_MAX < l_value)
        {
          l_value = USHRT_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }

  if (o_value)
    {
      *o_value = (unsigned short)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_int(int *const o_value, unsigned char const *i_str)
{
  int l_rc;
  long l_value;

  l_rc = mjo_str_to_long(&l_value, i_str);

#if (LONG_WIDTH != INT_WIDTH)
  if (MJO_OK == l_rc)
    {
      if ((INT_MIN > l_value) || (INT_MAX < l_value))
        {
          l_value = INT_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
#endif

  if (o_value)
    {
      *o_value = (int)l_value;
    }

  return l_rc;
}

extern int
  mjo_str_to_uint(unsigned int *const o_value, unsigned char const *i_str)
{
  int l_rc;
  unsigned long l_value;

  l_rc = mjo_str_to_ulong(&l_value, i_str);

#if (LONG_WIDTH != INT_WIDTH)
  if (MJO_OK == l_rc)
    {
      if (UINT_MAX < l_value)
        {
          l_value = UINT_MAX;
          l_rc = MJO_FAIL;
          errno = ERANGE;
        }
    }
#endif

  if (o_value)
    {
      *o_value = (unsigned int)l_value;
    }

  return l_rc;
}
