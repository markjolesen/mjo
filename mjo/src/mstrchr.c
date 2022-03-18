/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstrchr.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mu8.h"
#include "mutf8.h"

extern unsigned char *
  mjo_utf8_strchr(unsigned char const *i_str,
                  struct mjo_utf8 const *const i_peek)
{
  int l_bool;
  unsigned char const *l_head;
  unsigned char *l_rc;
  enum mjo_status l_status;
  unsigned char const *l_tail;
  struct mjo_utf8 l_peek;

  l_rc = 0;

  do
    {
      if (0 == i_str)
        {
          break;
        }

      if (0 == i_peek)
        {
          break;
        }

      if (0 == i_peek->m_legal)
        {
          break;
        }

      if (0 == i_peek->m_octets)
        {
          break;
        }

      l_tail = i_str;

      do
        {
          l_head = l_tail;

          mjo_utf8_compose(&l_status, &l_tail, &l_peek, l_head);

          if (mjo_status_eof == l_status)
            {
              break;
            }

          if (mjo_status_ok == l_status)
            {
              mjo_utf8_compare(&l_bool, i_peek, &l_peek);

              if (l_bool)
                {
                  l_rc = (unsigned char *)l_head;
                  break;
                }
            }
          else
            {
              l_tail++;
            }
        }
      while (1);
    }
  while (0);

  return l_rc;
}
