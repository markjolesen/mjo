/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (sdbm_mix.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/

/*
The algorithim used in the macro sdbm_mix() is from the Public Domain.

Notice of Intellectual Property 

    The entire sdbm library package, as authored by me, Ozan S. Yigit,
    is hereby placed in the public domain.

    As such, the author is not responsible for the consequences of
    use of this software, no matter how awful, even if they arise from
    defects in it. There is no expressed or implied warranty for the sdbm
    library. Since the sdbm library package is in the public domain,
    this original release or any additional public-domain releases of
    the modified original cannot possibly (by definition) be withheld
    from you. Also by definition, You (singular) have all the rights
    to this code (including the right to sell without permission, the
    right to hoard You cannot really hoard something that is available
    to the public at large, but try if it makes you feel any better. and
    the right to do other icky things as you see fit) but those rights
    are also granted to everyone else. Please note that all previous
    distributions of this software contained a copyright (which is now
    dropped) to protect its origins and its current public domain status
    against any possible claims and/or challenges.

Acknowledgments 

  Many people have been very helpful and supportive. A
  partial list would necessarily include Rayan Zacherissen (who
  contributed the man page, and also hacked a MMAP version of sdbm),
  Arnold Robbins, Chris Lewis, Bill Davidsen, Henry Spencer, Geoff
  Collyer, Rich Salz (who got me start<hy> ed in the first place),
  Johannes Ruschein (who did the minix port) and David Tilbrook. I thank
  you all. 

References:

  http://www.cse.yorku.ca/~oz/hash.html
  https://github.com/davidar/sdbm

*/
#if !defined(__sdbm_mix_h__)

#  include <limits.h>
#  include <stddef.h>
#  include <stdint.h>

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern size_t
    sdbm_mix(unsigned char const, size_t const);

#  if defined(__cplusplus)
}
#  endif

#  if 2 == SIZE_WIDTH
#    define sdbm_mix(c, h) (size_t)((c) + ((h) << 3) + ((h) << 8) - (h))
#  else
#    define sdbm_mix(c, h) (size_t)((c) + ((h) << 6) + ((h) << 16) - (h))
#  endif

#  define __sdbm_mix_h__
#endif
