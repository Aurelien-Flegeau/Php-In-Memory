#ifndef PHP_IN_MEMORY_H
#define PHP_IN_MEMORY_H
 
#define PHP_IN_MEMORY_EXTNAME  "in_memory"
#define PHP_IN_MEMORY_EXTVER   "0.1"
 
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 
 
extern "C" {
#include "php.h"
}
 
extern zend_module_entry in_memory_module_entry;
#define phpext_in_memory_ptr &in_memory_module_entry;
 
#endif /* PHP_IN_MEMORY_H */
