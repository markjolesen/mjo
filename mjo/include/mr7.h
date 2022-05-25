/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mr7.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mr7_h__)

#  include <stddef.h>

enum mjo_r7
{
  mjo_r7_nul = 0x00,         /* '\0' null char */
  mjo_r7_soh = 0x01,         /* start of header */
  mjo_r7_stx = 0x02,         /* start of text */
  mjo_r7_etx = 0x03,         /* end of text */
  mjo_r7_eot = 0x04,         /* end of transmission */
  mjo_r7_enq = 0x05,         /* enquiry */
  mjo_r7_ack = 0x06,         /* acknowledgment */
  mjo_r7_bel = 0x07,         /* bell */
  mjo_r7_bs = 0x08,          /* backspace */
  mjo_r7_ht = 0x09,          /* horizontal tab */
  mjo_r7_lf = 0x0a,          /* line feed */
  mjo_r7_vt = 0x0b,          /* vertical tab */
  mjo_r7_ff = 0x0c,          /* form feed */
  mjo_r7_cr = 0x0d,          /* carriage return */
  mjo_r7_so = 0x0e,          /* shift out */
  mjo_r7_si = 0x0f,          /* shift in */
  mjo_r7_dle = 0x10,         /* data link escape */
  mjo_r7_dc1 = 0x11,         /* xon     (device control 1) */
  mjo_r7_dc2 = 0x12,         /* device control 2 */
  mjo_r7_dc3 = 0x13,         /* xoff     (device control 3) */
  mjo_r7_dc4 = 0x14,         /* device control 4 */
  mjo_r7_nak = 0x15,         /* negative acknowledgement */
  mjo_r7_syn = 0x16,         /* synchronous idle */
  mjo_r7_etb = 0x17,         /* end of trans. block */
  mjo_r7_can = 0x18,         /* cancel */
  mjo_r7_em = 0x19,          /* end of medium */
  mjo_r7_sub = 0x1a,         /* substitute */
  mjo_r7_esc = 0x1b,         /* escape */
  mjo_r7_fs = 0x1c,          /* file separator */
  mjo_r7_gs = 0x1d,          /* group separator */
  mjo_r7_rs = 0x1e,          /* request to send/record separator */
  mjo_r7_us = 0x1f,          /* unit separator */
  mjo_r7_space = 0x20,       /* ' ' space */
  mjo_r7_exclamation = 0x21, /* '!' exclamation mark */
  mjo_r7_quote = 0x22,       /* '"' double quote */
  mjo_r7_pound = 0x23,       /* '#' number sign */
  mjo_r7_dollar = 0x24,      /* '$' dollar sign */
  mjo_r7_pct = 0x25,         /* '%' percent */
  mjo_r7_ampersand = 0x26,   /* '&' ampersand */
  mjo_r7_squote = 0x27,      /* '\'' single quote */
  mjo_r7_lparen = 0x28,      /* '(' left/opening parenthesis */
  mjo_r7_rparen = 0x29,      /* ')' right/closing parenthesis) */
  mjo_r7_asterisk = 0x2a,    /* '*' asterisk */
  mjo_r7_plus = 0x2b,        /* '+' plus */
  mjo_r7_comma = 0x2c,       /* ',' comma */
  mjo_r7_minus = 0x2d,       /* '-' minus or dash */
  mjo_r7_period = 0x2e,      /* '.' dot */
  mjo_r7_slash = 0x2f,       /* '/' forward slash */
  mjo_r7_0 = 0x30,           /* '0' number zero */
  mjo_r7_1 = 0x31,
  mjo_r7_2 = 0x32,
  mjo_r7_3 = 0x33,
  mjo_r7_4 = 0x34,
  mjo_r7_5 = 0x35,
  mjo_r7_6 = 0x36,
  mjo_r7_7 = 0x37,
  mjo_r7_8 = 0x38,
  mjo_r7_9 = 0x39,
  mjo_r7_colon = 0x3a,       /* colon */
  mjo_r7_semicolon = 0x3b,   /* semi-colon */
  mjo_r7_lessthan = 0x3c,    /* less than */
  mjo_r7_equal = 0x3d,       /* equal sign */
  mjo_r7_greaterthan = 0x3e, /* greater than */
  mjo_r7_question = 0x3f,    /* question mark */
  mjo_r7_at = 0x40,          /* at symbol */
  mjo_r7_upr_a = 0x41,
  mjo_r7_upr_b = 0x42,
  mjo_r7_upr_c = 0x43,
  mjo_r7_upr_d = 0x44,
  mjo_r7_upr_e = 0x45,
  mjo_r7_upr_f = 0x46,
  mjo_r7_upr_g = 0x47,
  mjo_r7_upr_h = 0x48,
  mjo_r7_upr_i = 0x49,
  mjo_r7_upr_j = 0x4a,
  mjo_r7_upr_k = 0x4b,
  mjo_r7_upr_l = 0x4c,
  mjo_r7_upr_m = 0x4d,
  mjo_r7_upr_n = 0x4e,
  mjo_r7_upr_o = 0x4f,
  mjo_r7_upr_p = 0x50,
  mjo_r7_upr_q = 0x51,
  mjo_r7_upr_r = 0x52,
  mjo_r7_upr_s = 0x53,
  mjo_r7_upr_t = 0x54,
  mjo_r7_upr_u = 0x55,
  mjo_r7_upr_v = 0x56,
  mjo_r7_upr_w = 0x57,
  mjo_r7_upr_x = 0x58,
  mjo_r7_upr_y = 0x59,
  mjo_r7_upr_z = 0x5a,
  mjo_r7_lbracket = 0x5b,   /* left/opening bracket */
  mjo_r7_backslash = 0x5c,  /* back slash */
  mjo_r7_rbracket = 0x5d,   /* right/closing bracket */
  mjo_r7_caret = 0x5e,      /* caret/circumflex */
  mjo_r7_underscore = 0x5f, /* underscore */
  mjo_r7_tick = 0x60,       /* '`' */
  mjo_r7_lwr_a = 0x61,
  mjo_r7_lwr_b = 0x62,
  mjo_r7_lwr_c = 0x63,
  mjo_r7_lwr_d = 0x64,
  mjo_r7_lwr_e = 0x65,
  mjo_r7_lwr_f = 0x66,
  mjo_r7_lwr_g = 0x67,
  mjo_r7_lwr_h = 0x68,
  mjo_r7_lwr_i = 0x69,
  mjo_r7_lwr_j = 0x6a,
  mjo_r7_lwr_k = 0x6b,
  mjo_r7_lwr_l = 0x6c,
  mjo_r7_lwr_m = 0x6d,
  mjo_r7_lwr_n = 0x6e,
  mjo_r7_lwr_o = 0x6f,
  mjo_r7_lwr_p = 0x70,
  mjo_r7_lwr_q = 0x71,
  mjo_r7_lwr_r = 0x72,
  mjo_r7_lwr_s = 0x73,
  mjo_r7_lwr_t = 0x74,
  mjo_r7_lwr_u = 0x75,
  mjo_r7_lwr_v = 0x76,
  mjo_r7_lwr_w = 0x77,
  mjo_r7_lwr_x = 0x78,
  mjo_r7_lwr_y = 0x79,
  mjo_r7_lwr_z = 0x7a,
  mjo_r7_lbrace = 0x7b, /* left/opening brace */
  mjo_r7_pipe = 0x7c,   /* pipe/vertical bar */
  mjo_r7_rbrace = 0x7d, /* right/closing brace */
  mjo_r7_tilde = 0x7e,
  mjo_r7_del = 0x7f /* delete */
};

#  if !defined(__CYGWIN__)                                                    \
    && (defined(_WIN32) || defined(__NT__) || defined(__DOS__))
#    define mjo_r7_dirsep mjo_r7_backslash
#    define mjo_r7_dirsep_str "\\"
#  else
#    define mjo_r7_dirsep mjo_r7_slash
#    define mjo_r7_dirsep_str "/"
#  endif

#  define mjo_r7_nil_str ""
#  define mjo_r7_space_str " "

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern int
    mjo_r7_hash(size_t *const, void const *, size_t const);

  extern int
    mjo_r7_shift_left(void *,
                      size_t const,
                      size_t const,
                      size_t const,
                      size_t const,
                      void (*)(void **const));

  extern int
    mjo_r7_shift_right(void *,
                       size_t const,
                       size_t const,
                       size_t const,
                       size_t const,
                       void (*)(void **const));

  extern void
    mjo_r7_to_upper(void *const, size_t const);

  extern void
    mjo_r7_to_lower(void *const, size_t const);

  extern void
    mjo_r7_zero(void *const, size_t const);

#  if defined(__cplusplus)
}
#  endif

#  define __mr7_h__
#endif
