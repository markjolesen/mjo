/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_utf8_space.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <string>

#include <stdio.h>
#include <stdint.h>

#include <iconv.h>
#include <unicode/unistr.h>

#include "mjo_utf8.h"
#include "mjo_stdlib.h"

struct space
{
	UChar32 codepoint;
	char const *comment;
} space_table[]=
{
{0x0009,"horizontal tab"},
{0x000a,"line feed"},
{0x000b,"vertical tab"},
{0x000c,"form feed"},
{0x000d,"carriage return"},
{0x0020,"space"},
{0x0085,"next line"},
{0x00A0,"no-break space"},
{0x1680,"ogham space mark"},
{0x180E,"mongolian vowel separator"},
{0x2000,"en quad"},
{0x2001,"em quad"},
{0x2002,"en space"},
{0x2003,"em space"},
{0x2004,"three-per-em space"},
{0x2005,"four-per-em space"},
{0x2006,"six-per-em space"},
{0x2007,"figure space"},
{0x2008,"spaceuation space"},
{0x2009,"thin space"},
{0x200A,"hair space"},
{0x200B,"zero width space"},
{0x200C,"zero width non-joiner"},
{0x200D,"zero width joiner"},
{0x2028,"line separator"},
{0x2029,"paragraph separator"},
{0x202F,"narrow no-break space"},
{0x205F,"medium mathematical space"},
{0x2060,"word joiner"},
{0x3000,"ideographic space"},
{0xFEFF,"zero width non-breaking space"}
};

struct utf8_space
{
	struct mjo_utf8 utf8;
	struct space* space;
};

int main() {
	icu::UnicodeString uni_str;
	std::string str;
	enum mjo_status status;
	size_t slots;
	size_t slot;
	struct utf8_space *table;

	slots= (sizeof(space_table) / sizeof(*space_table));

	mjo_calloc((void**)&table, slots, sizeof(struct utf8_space));

	for (slot= 0; slots > slot; slot++)
	{
		uni_str.setTo(space_table[slot].codepoint);

		str.clear();

		uni_str.toUTF8String(str);

		memcpy(table[slot].utf8.m_block, str.c_str(), str.length());
		table[slot].utf8.m_nil= 0;
		table[slot].utf8.m_octets= str.length();
		table[slot].utf8.m_legal= 1;
		table[slot].space= &space_table[slot];
	}
	
	printf("struct mjo_utf8 g_utf8_space_table[] = {\n");

	for (slot= 0; slots > slot; slot++)
	{
		int i;

		printf("{1");

		for (i=0; table[slot].utf8.m_octets > i; i++)
		{
			printf(",0x%02x", table[slot].utf8.m_block[i]);
		}

		for (; mjo_utf8_max_octets > i; i++)
		{
			printf(",0x00");
		}

		printf(" /*");
		printf("u+%08x ", table[slot].space->codepoint);
		printf("%s ", table[slot].space->comment);
		printf("*/");
		printf(",0");
		printf(",%zu", table[slot].utf8.m_octets);
		printf("}");
		if (slot != slots)
		{
			printf(",");
		}
		printf("\n");
	}

	printf("};\n");

	mjo_free((void**)&table);

	return 0;
}
