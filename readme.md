# License

CC0 1.0 Universal --- Public Domain

To the extent possible under law, Mark J. Olesen has waived all copyright
and related or neighboring rights to this file (readme.md). 
This work is published from: United States.

This file is part of the mjo library.

Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

This document is a synopsis of the mjo library. For specific information about a function please consult the [man](https://markjolesen.github.io/mjo//index.html) pages.
___

# mjo Library

Portability headers and functions for various compilers targeted at
specific Operating Systems.

| header | description |
| --------- | --------------------------------------------------------------- |
| [mdirect.h](https://markjolesen.github.io/mjo//mdirect.h.7.html) | open and read directories |
| [mfcntl.h](https://markjolesen.github.io/mjo//mfnctl.h.7.html) | O_BINARY |
| [mr7.h](https://markjolesen.github.io/mjo//mr7.h.7.html) | ASCII character set (0x00-0x7F) constants, hash and trim routines |
| [mstddef.h](https://markjolesen.github.io/mjo//mstddef.h.7.html) | ssize_t |
| [mstdio.h](https://markjolesen.github.io/mjo//mstdio.h.7.html) | io constants and abstract input routines |
| [mstdlib.h](https://markjolesen.github.io/mjo//mstdlib.h.7.html) | extended standard library routines |
| mstring.h | explicit_bzero() |
| [msysstat.h](https://markjolesen.github.io/mjo//msysstat.h.7.html) | file status flags along with stat() and fstat() routines |
| [mu8.h](https://markjolesen.github.io/mjo//mu8.h.7.html) | UTF-8 calculation and validation routines, trim routines |
| [munistd.h](https://markjolesen.github.io/mjo//munistd.h.7.html) | if available include unistd.h |
| [mutf8.h](https://markjolesen.github.io/mjo//mutf8.h.7.html) | UTF-8 data structure and routines |
| [mxywh.h](https://markjolesen.github.io/mjo//mxywh.h.7.html) | rectangle data structure |

This is not meant to be a replacement for cygwin. It is minimalist
and does the job for applications written with ANSI-C in mind. Note,
not all platforms are POSIX compatible. Thus, this library attempts
to fill in the gaps without bloat.

## mdirect.h
- [struct dirent](https://markjolesen.github.io/mjo/mdirect.h.7.html)
- [opendir()](https://markjolesen.github.io/mjo/mdirect.h.7.html)
- [readdir()](https://markjolesen.github.io/mjo/mdirect.h.7.html)
- [closedir()](https://markjolesen.github.io/mjo/mdirect.h.7.html)

## mr7.h
- [mjo_r7_hash()](https://markjolesen.github.io/mjo/mjo_r7_hash.3.html)
- [mjo_r7_shift_left()](https://markjolesen.github.io/mjo/mr7.h.7.html)
- [mjo_r7_shift_right()](https://markjolesen.github.io/mjo/mr7.h.7.html)
- [mjo_r7_zero()](https://markjolesen.github.io/mjo/mr7.h.7.html)

## mstdio.h
- [mjo_handle_t](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_read_t](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_status_ok](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_status_invalid](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_status_eof](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_status_truncated](https://markjolesen.github.io/mjo/mstdio.h.7.html)
- [mjo_read()](https://markjolesen.github.io/mjo/mjo_read.3.html)

## mu8.h
- [mjo_u8_calc()](https://markjolesen.github.io/mjo/mjo_u8_calc.3.html)
- [mjo_u8_trim()](https://markjolesen.github.io/mjo/mjo_u8_trim.3.html)
- [mjo_u8_trim_left()](https://markjolesen.github.io/mjo/mjo_u8_trim.3.html)
- [mjo_u8_trim_right()](https://markjolesen.github.io/mjo/mjo_u8_trim.3.html)
- [mjo_u8_validate()](https://markjolesen.github.io/mjo/mjo_u8_validate.3.html)
- [mjo_u8_validate_nth_sequence()](https://markjolesen.github.io/mjo/mu8.h.7.html))

## mutf8.h
- [mjo_utf8_max_octets](https://markjolesen.github.io/mjo/mutf8.h.7.html)
- [mjo_utf8_replacement](https://markjolesen.github.io/mjo/mutf8.h.7.html)
- [struct mjo_utf8](https://markjolesen.github.io/mjo/mutf8.h.7.html)
- [mjo_utf8_compare()](https://markjolesen.github.io/mjo/mutf8.h.7.html)
- [mjo_utf8_compose()](https://markjolesen.github.io/mjo/mjo_utf8_compose.3.html)
- [mjo_utf8_is_punctuation()](https://markjolesen.github.io/mjo/mjo_utf8_is_punctuation.3.html)
- [mjo_utf8_is_quote()](https://markjolesen.github.io/mjo/mjo_utf8_is_quote.3.html)
- [mjo_utf8_is_whitespace()](https://markjolesen.github.io/mjo/mjo_utf8_is_whitespace.3.html)
- [mjo_utf8_strchr()](https://markjolesen.github.io/mjo/mutf8.h.7.html))

# mjoextra library

Utility routines, which simplify an abstract and cohesive interface to common tasks.

| header | description |
| --------- | --------------------------------------------------------------- |
| mread.h | high level read operations on a input stream |
| marg.h | argument parser |
| mistream.h | high level abstract input reader |
| mvector.h | abstract container vector/array of objects  |

## mread.h
- mjo_read_line
- mjo_read_csv
   
## marg.h
- mjo_arg_option_mask
- mjo_arg_argument_mask
- mjo_arg_rule_mask
- mjo_arg_t
- mjo_arg_free()
- mjo_arg_malloc()
- mjo_arg_option()
- mjo_arg_parse()
- mjo_arg_parse_block()
- mjo_arg_parse_file()
- mjo_arg_parse_vector()
- mjo_arg_print()
- mjo_arg_value()

## mistream.h
- mjo_istream_option_none
- mjo_istream_t
- mjo_istream_file_malloc()
- mjo_istream_free()
- mjo_istream_block_malloc()
- mjo_istream_push()
- mjo_istream_read()

## mvector.h
- mjo_vector_size_auto
- mjo_vector_variant_struct
- mjo_vector_variant_ptrstr
- mjo_vector_variant_char
- mjo_vector_variant_short
- mjo_vector_variant_ushort
- mjo_vector_variant_bool
- mjo_vector_variant_int
- mjo_vector_variant_uint
- mjo_vector_variant_long
- mjo_vector_variant_ulong
- mjo_vector_variant_size_t
- mjo_vector_variant_ptrdiff_t
- mjo_vector_variant_double
- mjo_vector_t
- mjo_vector_clear()
- mjo_vector_count()
- mjo_vector_dequeue()
- mjo_vector_free()
- mjo_vector_malloc()
- mjo_vector_permute_push()
- mjo_vector_pop()
- mjo_vector_push()
- mjo_vector_type()
- mjo_vector_variant_discharge_free()
- mjo_vector_variant_tag()
