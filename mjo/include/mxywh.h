/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mxywh.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mxywh_h__)

#  include <mstddef.h>

struct mjo_xywh
{
  ssize_t m_pos_x;
  ssize_t m_pos_y;
  size_t m_len_x;
  size_t m_len_y;
};

#  define __mxywh_h__
#endif
