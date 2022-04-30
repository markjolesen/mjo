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
- struct dirent
- opendir()
- readdir()
- closedir()

## mr7.h
- mjo_r7_hash()
- mjo_r7_shift_left()
- mjo_r7_shift_right()
- mjo_r7_zero()

## mstdio.h
- mjo_handle_t
- mjo_read_t
- mjo_status_ok
- mjo_status_invalid
- mjo_status_eof
- mjo_status_truncated
- mjo_read()

## mu8.h
- mjo_u8_calc()
- mjo_u8_trim()
- mjo_u8_trim_left()
- mjo_u8_trim_right()
- mjo_u8_validate()
- mjo_u8_validate_nth_sequence()

## mutf8.h
- mjo_utf8_max_octets
- mjo_utf8_replacement
- struct mjo_utf8
- mjo_utf8_compare()
- mjo_utf8_compose()
- mjo_utf8_is_punctuation()
- mjo_utf8_is_quote()
- mjo_utf8_is_whitespace()
- mjo_utf8_strchr()

# mjoextra library

Utility routines, which simplify an abstract and cohesive interface to common tasks.

| header | description |
| --------- | --------------------------------------------------------------- |
| mread.h | high level read operations on a input stream |
| marg.h | argument parser |
| mistream | high level abstract input reader |
| mvector | abstract container vector/array of objects  |

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
