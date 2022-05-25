/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mreaddir.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mdirect.h"
#include "mr7.h"
#include "mstdlib.h"

#if defined(_MSC_VER) || defined(__MSVCRT__) || defined(__WATCOMC__)

#if defined(readdir)
#undef readdir
#endif

extern struct dirent *
  mjo_readdir(struct dirent *const io_dir)
{
	struct dirent* ent;

	ent= readdir(io_dir);

	if (ent)
	{
		mjo_r7_to_lower(ent->d_name, (size_t)-1);
	}

	return ent;
}
#endif
