#!/bin/sh
#
# CC0 1.0 Universal --- Public Domain
#
# To the extent possible under law, Mark J. Olesen has waived all copyright
# and related or neighboring rights to this file (man2html.sh).
# This work is published from: United States.
#
# Full text of this license can be found by visting
# <https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt> or
# send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
#

if [[ ! -d ./htmlman ]]; then
  mkdir ./htmlman
else
  rm -f ./htmlman/*
fi

for path in `find . -name "*.[37]" -type f -print`
do

  outf=`basename ${path}`
  outf="./htmlman/${outf}.html"
  `mandoc -mdoc -T html -O includes=%I.html -O man=%N.%S.html ${path} > ${outf}`

done

cat << EOF > /tmp/index.html
<!DOCTYPE html>
<html>
<!-- This is an automatically generated file.  Do not edit.
    Copyright (c) 2020 Mark J. Olesen

    CC BY 4.0

    This file is licensed under the Creative Commons Attribution 4.0
    International license.

    You are free to:

      Share --- copy and redistribute the material in any medium or format

      Adapt --- remix, transform, and build upon the material for any purpose
,
                even commercially

    Under the following terms:

     Attribution --- You must give appropriate credit, provide a link
                      to the license, and indicate if changes were made. You
                      may do so in any reasonable manner, but not in any way
                      that suggests the licensor endorses you or your use.

     Full text of this license can be found in
     '${MJO_HOME}/licenses/CC-BY-SA-4.0'or visit
     'http://creativecommons.org/licenses/by/4.0/' or send a letter
     to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

    This file is part of mjo library
   -->
<body>
EOF

echo '<ul style= "list-style-type: none">' >> /tmp/index.html

for path in `find ./htmlman -name "*.html" -type f -print`
do

  outf=`basename ${path}`
  fn=`echo ${outf} | awk -F. '{ print $1 }'`
  echo "<li><a href=\"${outf}\">${fn}</a></li>" >> /tmp/index.html

done

cat << EOF >> /tmp/index.html
</ul>
</body>
</html>

EOF

mv /tmp/index.html ./htmlman/
