/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mdirect.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mdirect_h__)

#  if defined(_MSC_VER) || defined(__MSVCRT__) || defined(__WATCOMC__)
#    include <direct.h>
#  else
#    include <dirent.h>
#  endif

#  if defined(_MSC_VER) || defined(__MSVCRT__)

struct dirent
{
  char *d_name;
  ptrdiff_t m_handle;
  struct _finddata_t m_data;
};

typedef struct dirent DIR;

#    if defined(__cplusplus)
extern "C"
{
#    endif

  extern DIR *
    opendir(char const *);

  extern struct dirent *
    readdir(DIR *const);

  extern int
    closedir(DIR *const);

#    if defined(__cplusplus)
}
#    endif

#  endif

#if defined(_MSC_VER) || defined(__MSVCRT__) || defined(__WATCOMC__)

#    if defined(__cplusplus)
extern "C"
{
#    endif

extern struct dirent *
  mjo_readdir(DIR *const);

#    if defined(__cplusplus)
}
#    endif

#define  readdir(e) mjo_readdir(e)

#endif

#  define __mdirect_h__
#endif
