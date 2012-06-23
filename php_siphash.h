/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_SIPHASH_H
#define PHP_SIPHASH_H

extern zend_module_entry siphash_module_entry;
#define phpext_siphash_ptr &siphash_module_entry

#ifdef PHP_WIN32
#	define PHP_SIPHASH_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SIPHASH_API __attribute__ ((visibility("default")))
#else
#	define PHP_SIPHASH_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(siphash);
PHP_MSHUTDOWN_FUNCTION(siphash);
PHP_RINIT_FUNCTION(siphash);
PHP_RSHUTDOWN_FUNCTION(siphash);
PHP_MINFO_FUNCTION(siphash);

#ifdef ZTS
#define SIPHASH_G(v) TSRMG(siphash_globals_id, zend_siphash_globals *, v)
#else
#define SIPHASH_G(v) (siphash_globals.v)
#endif

PHP_FUNCTION(sip_hash);
PHP_FUNCTION(sip_hash_hex);

#endif	/* PHP_SIPHASH_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
