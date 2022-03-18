/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (utf8_compose.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdio.h>
#include <mutf8.h>

int
  main()
{
  unsigned char const hello_greek[] = { "γεια σας" };
  unsigned char const *tail = hello_greek;
  enum mjo_status status;
  struct mjo_utf8 peek;
  unsigned offset = 0;
  int exit_code = 0;

  do
    {
      mjo_utf8_compose(&status, &tail, &peek, tail);

      if (mjo_status_eof == status)
        {
          printf("End of stream encountered\n");
          break;
        }

      if (mjo_status_ok != status)
        {
          printf("Invalid utf8 sequence: offset=%u\n", offset);
          exit_code = -1;
          break;
        }

      printf("Offset[%u]=%s\n", offset, peek.m_block);
      offset += peek.m_octets;
    }
  while (1);

  return exit_code;
}
