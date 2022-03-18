/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (msysstat.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__msysstat_h__)

#  include <sys/stat.h>

#  if defined(_MSC_VER)

#    define S_IRUSR S_IREAD
#    define S_IWUSR S_IWRITE
#    define S_IXUSR 0x0

#    define S_IRGRP S_IRUSR
#    define S_IWGRP S_IWUSR
#    define S_IXGRP S_IXUSR

#    define S_IROTH S_IRUSR
#    define S_IWOTH S_IRUSR
#    define S_IXOTH S_IRUSR

#    define S_IRWXU (S_IRUSR | S_IWUSR | S_IXUSR)
#    define S_IRWXG (S_IRGRP | S_IWGRP | S_IXGRP)
#    define S_IRWXO (S_IROTH | S_IWOTH | S_IXOTH)

#    define stat _stat
#    define fstat _fstat

#  endif

#  define __msysstat_h__
#endif
