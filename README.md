SipHash for PHP
===============

[SipHash](http://131002.net/siphash/) extension for PHP.

Usage:

    sip_hash(key, message)

outputs `siphash-2-4(key, message)` as a 8-byte string.

    sip_hash32(key, message)

truncates the value and outputs a 32-bit integer.

The `key` should be a 16 bytes string.

Installation
============

    $ phpize
    $ ./configure --enable-siphash
    $ make install

And add `extension=siphash.so` to your php.ini configuration file.

This PHP extension uses FloodyBerry's
[basic implementation](https://github.com/floodyberry/siphash)
