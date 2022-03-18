/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (u8_validate.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdio.h>
#include <mu8.h>

int
  main()
{
  const unsigned char *utf8strings[]
    = { (unsigned char const *)"γεια σας",
        (unsigned char const *)"\xf0\xa4\xadz",
        0 };
  unsigned char *last;
  unsigned char const *ptr;
  unsigned slot;
  int valid;

  for (slot = 0; utf8strings[slot]; slot++)
    {
      mjo_u8_validate(&valid, &last, utf8strings[slot]);

      printf("valid=%s; terminator=%02x\n", (valid ? "yes" : "no"), *last);

      for (ptr = utf8strings[slot]; ptr != last; ptr++)
        {
          printf("\%x02", *ptr);
        }
      printf("\n");
    }

  return !valid;
}
