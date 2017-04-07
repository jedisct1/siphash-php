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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_siphash.h"
#include "siphash-impl.h"

#ifndef WORDS_BIGENDIAN
# include <arpa/inet.h>
#endif

#if PHP_MAJOR_VERSION >= 7
typedef size_t strsize_t;
#else
typedef int strsize_t;

# undef  RETURN_STRING
# define RETURN_STRING(s) \
    do { \
        RETVAL_STRING((s), 1); \
        return; \
    } while(0)
#endif

const zend_function_entry siphash_functions[] = {
    PHP_FE(sip_hash, NULL)
    PHP_FE(sip_hash32, NULL)
#ifdef PHP_FE_END
    PHP_FE_END
#else
    { NULL, NULL, NULL }
#endif
};

/* {{{ siphash_module_entry
 */
zend_module_entry siphash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "siphash",
    siphash_functions,
    PHP_MINIT(siphash),
    PHP_MSHUTDOWN(siphash),
    NULL,
    NULL,
    PHP_MINFO(siphash),
#if ZEND_MODULE_API_NO >= 20010901
    "1.0",
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SIPHASH
ZEND_GET_MODULE(siphash)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(siphash)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(siphash)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(siphash)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "siphash support", "enabled");
    php_info_print_table_end();
}
/* }}} */

PHP_FUNCTION(sip_hash)
{
    char     *key = NULL;
    char     *message = NULL;
    struct {
        uint64_t      hash;
        unsigned char eos;
    }         res;
    strsize_t key_size;
    strsize_t message_size;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
                              &key, &key_size,
                              &message, &message_size) == FAILURE) {
        return;
    }
    if (key_size != 16) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Bad key length");
        RETURN_FALSE;
    }
    if (message_size < 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty message");
        RETURN_FALSE;
    }
    memset(&res, 0, sizeof res);
    res.hash = siphash((unsigned char *) key,
                   (const unsigned char *) message, (size_t) message_size);
#ifdef WORDS_BIGENDIAN
    res.hash = (((uint64_t) htonl((uint32_t) res.hash)) << 32) |
        htonl((uint32_t) (res.hash >> 32));
#endif

    RETURN_STRING((void *) &res);
}

PHP_FUNCTION(sip_hash32)
{
    char     *key = NULL;
    char     *message = NULL;
    uint64_t  hash;
    long      hash32;
    strsize_t key_size;
    strsize_t message_size;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
                              &key, &key_size,
                              &message, &message_size) == FAILURE) {
        return;
    }
    if (key_size != 16) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Bad key length");
        RETURN_FALSE;
    }
    if (message_size < 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty message");
        RETURN_FALSE;
    }
    hash = siphash((unsigned char *) key,
                   (const unsigned char *) message, (size_t) message_size);
    hash32 = (long) (hash & 0xFFFFFFFF);

    RETURN_LONG(hash32);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
