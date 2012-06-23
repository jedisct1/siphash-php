dnl $Id$
dnl config.m4 for extension siphash

PHP_ARG_ENABLE(siphash, whether to enable siphash support,
[  --enable-siphash           Enable siphash support])

if test "$PHP_SIPHASH" != "no"; then
  PHP_NEW_EXTENSION(siphash, siphash-impl.c siphash.c, $ext_shared)
fi
