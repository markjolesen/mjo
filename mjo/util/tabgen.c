/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_utf8_tabgen.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
  calc(int *const o_legal, size_t *const o_octets, unsigned char const i_octet)
{
  unsigned char l_bits;

  *o_legal = 1;
  *o_octets = 0;

  do
    {
      l_bits = (i_octet >> 7);

      if (0 == /* 0b */ l_bits)
        {
          *o_octets = 1;
          break;
        }

      l_bits = (i_octet >> 5);

      if (0x6 /* 110b */ == l_bits)
        {
          *o_octets = 2;
          break;
        }

      l_bits = (i_octet >> 4);

      if (0xe /* 1110b */ == l_bits)
        {
          *o_octets = 3;
          break;
        }

      l_bits = (i_octet >> 3);

      if (0x1e /* 11110b */ == l_bits)
        {
          *o_octets = 4;
          break;
        }

      l_bits = (i_octet >> 2);

      if (0x3e /* 111110b */ == l_bits)
        {
          *o_octets = 5;
          break;
        }

      l_bits = (i_octet >> 1);

      if (0x7e /* 1111110b  */ == l_bits)
        {
          *o_octets = 6;
          break;
        }

      *o_legal = 0;
      *o_octets = 1;
    }
  while (0);

  return;
}

static void
  str_to_bin(unsigned char *io_buf, unsigned char const i_octet)
{
  size_t l_slot;
  unsigned char l_bit;
  unsigned char *l_ptr;

  l_ptr = io_buf;
  l_slot = 8;
  do
    {
      l_slot--;

      l_bit = (i_octet >> l_slot);
      l_bit &= 1;
      l_bit += '0';
      *l_ptr++ = l_bit;

      if (0 == l_slot)
        {
          break;
        }
    }
  while (1);

  *l_ptr = 0;

  return;
}

extern int
  main()
{
  unsigned char l_buf[10];
  size_t l_octets;
  int l_legal;
  unsigned char l_octet;

  l_octet = 0;

  printf("static struct abc_utf8c_table\n");
  printf("{\n");
  printf("  size_t                                m_size;\n");
  printf("  int                                   m_legal;\n");
  printf("}                                       l_table[256]=\n");
  printf("{\n");

  do
    {
      calc(&l_legal, &l_octets, l_octet);

      printf("  {%zu,%d}%s",
             l_octets,
             (l_legal ? 1 : 0),
             ((255 > l_octet) ? "," : " "));

      str_to_bin(l_buf, l_octet);

      printf(" /*%03d:0x%02X:%s:size=%zu:valid=%s*/\n",
             l_octet,
             l_octet,
             l_buf,
             l_octets,
             (l_legal) ? "y" : "n");

      if (255 == l_octet)
        {
          break;
        }

      l_octet++;
    }
  while (1);

  printf("};\n");

  return EXIT_SUCCESS;
}
