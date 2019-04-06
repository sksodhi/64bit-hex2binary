#!/bin/bash
repo_name=64bit-hex2binary

#
# We will be creating sym links to the repo dir
# The sym link and the repo directory must have
# same ownership for apache to access it
#
chown -R root:root /root/$repo_name

#
# Generate cgi binary
#
cd /root/$repo_name
echo compiling 64bit_h2b.c ...
gcc 64bit_h2b.c -o 64bit_h2b

#
# Create sym links
#
cd /var/www/html
ln -sf /root/$repo_name
ls -l /var/www/html/$repo_name
cd /usr/lib/cgi-bin
ln -sf /root/$repo_name
ls -l /usr/lib/cgi-bin/$repo_name

