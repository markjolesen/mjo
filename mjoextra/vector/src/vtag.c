/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vtag.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_vector.h"

extern unsigned char const *
  mjo_vector_variant_tag(enum mjo_vector_variant const i_type)
{
  unsigned char const *l_tag;

  switch (i_type)
    {
    case mjo_vector_variant_struct:
      l_tag = (unsigned char const *)"struct";
      break;
    case mjo_vector_variant_ptrstr:
      l_tag = (unsigned char const *)"char*";
      break;
    case mjo_vector_variant_char:
      l_tag = (unsigned char const *)"char";
      break;
    case mjo_vector_variant_short:
      l_tag = (unsigned char const *)"short";
      break;
    case mjo_vector_variant_ushort:
      l_tag = (unsigned char const *)"unsigned short";
      break;
    case mjo_vector_variant_bool:
      l_tag = (unsigned char const *)"boolean";
      break;
    case mjo_vector_variant_int:
      l_tag = (unsigned char const *)"int";
      break;
    case mjo_vector_variant_uint:
      l_tag = (unsigned char const *)"unsigned int";
      break;
    case mjo_vector_variant_long:
      l_tag = (unsigned char const *)"long";
      break;
    case mjo_vector_variant_ulong:
      l_tag = (unsigned char const *)"unsigned long";
      break;
    case mjo_vector_variant_size_t:
      l_tag = (unsigned char const *)"size_t";
      break;
    case mjo_vector_variant_ptrdiff_t:
      l_tag = (unsigned char const *)"ptrdiff_t";
      break;
    case mjo_vector_variant_double:
      l_tag = (unsigned char const *)"double";
      break;
    default:
      l_tag = (unsigned char const *)"";
      break;
    }

  return l_tag;
}
