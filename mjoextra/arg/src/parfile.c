/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (parfile.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <msysstat.h>
/**/
#include <mfcntl.h>
#include <mstdio.h>
#include <mstdlib.h>
#include <mstring.h>
#include <munistd.h>
/**/
#include "_arg.h"

static int
  _mjo_arg_parse_file(mjo_arg_t const io_arg, unsigned char const *i_path)
{
  int l_rc;
  int l_fd;
  mjo_istream_t l_stream;

  do
    {
      l_fd = open((char const *)i_path, (O_RDONLY | O_BINARY));

      if (-1 == l_fd)
        {
          if (0
              == (mjo_arg_rule_mask_on_error_suppress_message
                  & io_arg->m_rule_mask))
            {
              fprintf(io_arg->m_diag.m_elog, "Error: Open File\n");
              fprintf(io_arg->m_diag.m_elog, "\tfile=%s\n", i_path);
              fprintf(io_arg->m_diag.m_elog,
                      "\terrno(%d)=%s\n",
                      errno,
                      strerror(errno));
            }
          l_rc = MJO_FAIL;
          break;
        }

      mjo_istream_file_malloc(&l_stream,
                              mjo_istream_option_none,
                              (mjo_read_t)&read,
                              (mjo_handle_t)l_fd);

      l_rc = mjo_arg_parse(io_arg, l_stream);

      mjo_istream_free(&l_stream);
      close(l_fd);
    }
  while (0);

  return l_rc;
}

extern int
  mjo_arg_parse_file(mjo_arg_t const io_arg, unsigned char const *i_path)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_arg)
        {
          errno = EINVAL;
          break;
        }

      if ((0 == i_path) || (0 == *i_path))
        {
          errno = EINVAL;
          break;
        }

      l_rc = _mjo_arg_parse_file(io_arg, i_path);
    }
  while (0);

  return l_rc;
}
