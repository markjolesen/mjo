/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (utf8_compose.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <string.h>
/**/
#include <mstdio.h>
#include <mu8.h>

int
  main()
{
  unsigned char utf8string[] = { "        Non White\r\n" };

  printf("before trim: %s\n", (char *)utf8string);
  printf("        len: %lu\n", strlen((char *)utf8string));
  mjo_u8_trim(utf8string);
  printf(" after trim: %s\n", (char *)utf8string);
  printf("        len: %lu\n", strlen((char *)utf8string));

  return 0;
}
