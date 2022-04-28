This document is a synopsis of the mjo library. For specific
information about a function please consult the man pages.

# mjo Library

Portability headers and functions for various compilers targeted at
specific Operating Systems.

| header | description |
| --------- | --------------------------------------------------------------- |
| mdirect.h | open and read directories |
| mfcntl.h | O_BINARY |
| mr7.h | ASCII character set (0x00-0x7F) constants, hash and trim routines |
| mstddef.h | ssize_t |
| mstdio.h | io constants and abstract input routines |
| mstdlib.h | extended standard library routines |
| mstring.h | explicit_bzero() |
| msysstat.h | file status flags along with stat() and fstat() routines |
| mu8.h | UTF-8 calculation and validation routines, trim routines |
| munistd.h | if available include unistd.h |
| mutf8.h | UTF-8 data structure and routines |
| mxywh.h | rectangle data structure |

This is not meant to be a replacement for cygwin. It is minimalist
and does the job for applications written with ANSI-C in mind. Note,
not all platforms are POSIX compatible.

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

# mjoextra

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
