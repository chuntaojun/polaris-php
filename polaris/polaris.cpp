// Tencent is pleased to support the open source community by making polaris-go available.
//
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissionsr and limitations under the License.
//

/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
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
#include "php_polaris.h"

#include "polaris_core.hpp"

/* If you declare any globals in php_polaris.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(polaris)
*/

/* True global resources - no need for thread safety here */
static int le_polaris;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
	STD_PHP_INI_ENTRY("polaris.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_polaris_globals, polaris_globals)
	STD_PHP_INI_ENTRY("polaris.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_polaris_globals, polaris_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_polaris_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_polaris_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE)
	{
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "polaris", arg);
	RETURN_STRINGL(strg, len);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* {{{ php_polaris_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_polaris_init_globals(zend_polaris_globals *polaris_globals)
{
	polaris_globals->global_value = 0;
	polaris_globals->global_string = NULL;
}
*/
/* }}} */

zend_class_entry *polaris_core_client;

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(polaris)
{
	// If you have INI entries, uncomment these lines
	// REGISTER_INI_ENTRIES();

	// 初始化 ProviderApi 相关
	zend_class_entry polaris_core_ins;
	INIT_CLASS_ENTRY(polaris_core_ins, "PolarisClient", polaris_core_functions);

	polaris_core_client = zend_register_internal_class(&polaris_core_ins TSRMLS_CC);
	polaris_core_client->create_object = polaris_core_create_handler;
	memcpy(&polaris_core_object_handlers,
		   zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	polaris_core_object_handlers.clone_obj = NULL;
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(polaris)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(polaris)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(polaris)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(polaris)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "polaris support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

// 定义 PolarisCPP 中在 PHP 对应的类

/* {{{ polaris_functions[]
 *
 * Every user visible function must have an entry in polaris_functions[].
 */
const zend_function_entry polaris_functions[] = {
	PHP_FE(confirm_polaris_compiled, NULL) /* For testing, remove later. */
	PHP_FE_END							   /* Must be the last line in polaris_functions[] */
};
/* }}} */

/* {{{ polaris_module_entry
 */
zend_module_entry polaris_module_entry = {
	STANDARD_MODULE_HEADER,
	"polaris",
	NULL,
	PHP_MINIT(polaris),
	NULL,
	NULL, /* Replace with NULL if there's nothing to do at request start */
	NULL, /* Replace with NULL if there's nothing to do at request end */
	NULL,
	PHP_POLARIS_VERSION,
	STANDARD_MODULE_PROPERTIES};
/* }}} */

#ifdef COMPILE_DL_POLARIS
ZEND_GET_MODULE(polaris)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */