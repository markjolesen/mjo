/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_utf8_quote.c). 
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

struct quote
{
	UChar32 codepoint;
	char const *comment;
} quote_table[]=
{
{0x0022, "quotation mark"},
{0x0027, "apostrophe (')"},
{0x00ab, "left-pointing double-angle quotation mark"},
{0x00bb, "right-pointing double-angle quotation mark"},
{0x2018, "left single quotation mark"},
{0x2019, "right single quotation mark"},
{0x201a, "single low-9 quotation mark"},
{0x201b, "single high-reversed-9 quotation mark"},
{0x201c, "left double quotation mark"},
{0x201d, "right double quotation mark"},
{0x201e, "double low-9 quotation mark"},
{0x201f, "double high-reversed-9 quotation mark"},
{0x2039, "single left-pointing angle quotation mark"},
{0x203a, "single right-pointing angle quotation mark"},
{0x300c, "left corner bracket"},
{0x300d, "right corner bracket"},
{0x300e, "left white corner bracket"},
{0x300f, "right white corner bracket"},
{0x301d, "reversed double prime quotation mark"},
{0x301e, "double prime quotation mark"},
{0x301f, "low double prime quotation mark"},
{0xfe41, "presentation form for vertical left corner bracket"},
{0xfe42, "presentation form for vertical right corner bracket"},
{0xfe43, "presentation form for vertical left corner white bracket"},
{0xfe44, "presentation form for vertical right corner white bracket"},
{0xff02, "fullwidth quotation mark"},
{0xff07, "fullwidth apostrophe"},
{0xff62, "halfwidth left corner bracket"},
{0xff63, "halfwidth right corner bracket"},
};

struct utf8_quote
{
	struct mjo_utf8 utf8;
	struct quote* quote;
};

int main() {
	icu::UnicodeString uni_str;
	std::string str;
	enum mjo_status status;
	size_t slots;
	size_t slot;
	struct utf8_quote *table;

	slots= (sizeof(quote_table) / sizeof(*quote_table));

	mjo_calloc((void**)&table, slots, sizeof(struct utf8_quote));

	for (slot= 0; slots > slot; slot++)
	{
		uni_str.setTo(quote_table[slot].codepoint);

		str.clear();

		uni_str.toUTF8String(str);

		memcpy(table[slot].utf8.m_block, str.c_str(), str.length());
		table[slot].utf8.m_nil= 0;
		table[slot].utf8.m_octets= str.length();
		table[slot].utf8.m_legal= 1;
		table[slot].quote= &quote_table[slot];
	}
	
	printf("struct mjo_utf8 g_utf8_quote_table[] = {\n");

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
		printf("u+%08x ", table[slot].quote->codepoint);
		printf("%s ", table[slot].quote->comment);
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
