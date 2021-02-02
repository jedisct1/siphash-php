SipHash for PHP
===============

[SipHash](https://www.aumasson.jp/siphash/siphash.pdf) extension for PHP.

> SipHash is a family of pseudorandom functions optimized for short
> inputs. Target applications include network traffic authentication and
> hash-table lookups protected against hash-flooding denial-of-service
> attacks. SipHash has well-defined security goals and competitive
> performance.

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

PHP 5.6+ and PHP 7.0+ are fully supported.
