/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mr7upr.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mr7.h"

extern void
mjo_r7_to_upper(void *const io_block, size_t const i_octets)
{
	unsigned char *l_ptr;
	size_t l_left;

	l_ptr= (unsigned char*)io_block;
	l_left= (io_block) ? i_octets : 0;

	for (; l_left && *l_ptr; l_left--, l_ptr++)
	{
          if (*l_ptr >= mjo_r7_lwr_a && *l_ptr <= mjo_r7_lwr_z)
		{
            (*l_ptr) -= mjo_r7_space;
		}
        }

	return;
}
