#include "php_in_memory.h"
#include "data.h"
using namespace PhpInMemory;
 
zend_object_handlers data_object_handlers;
 
struct data_object {
    zend_object std;
    Data *data;
};

zend_class_entry *data_ce;

void data_free_storage(void *object TSRMLS_DC)
{
    data_object *obj = (data_object *) object;
    delete obj->data; 
 
    zend_hash_destroy(obj->std.properties);
    FREE_HASHTABLE(obj->std.properties);
 
    efree(obj);
}
 
zend_object_value data_create_handler(zend_class_entry *type TSRMLS_DC)
{
    zval *tmp;
    zend_object_value retval;
 
    data_object *obj = (data_object *) emalloc(sizeof(data_object));
    memset(obj, 0, sizeof(data_object));
    obj->std.ce = type;
 
    ALLOC_HASHTABLE(obj->std.properties);
    zend_hash_init(obj->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
    object_properties_init(&obj->std, type);
 
    retval.handle = zend_objects_store_put(obj, NULL, data_free_storage, NULL TSRMLS_CC);
		
    retval.handlers = &data_object_handlers;
 
    return retval;
}
 
PHP_METHOD(Data, __construct)
{
    Data *data = NULL;
    zval *object = getThis();
 
    data = new Data();
    data_object *obj = (data_object *) zend_object_store_get_object(object TSRMLS_CC);
    obj->data = data;
}

PHP_METHOD(Data, get)
{
    Data *data;
    data_object *obj = (data_object *) zend_object_store_get_object(getThis() TSRMLS_CC);
		
    data = obj->data;
	
    if (data != NULL) {
        RETURN_STRING(data->get(), 1);
    }
	
    RETURN_NULL();
}

PHP_METHOD(Data, set)
{
    //string value;
    char* value;
    int length;
    Data *data;
    zval *object = getThis();
 
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &value, &length) == FAILURE) {
        RETURN_NULL();
    }

    data_object *obj = (data_object *) zend_object_store_get_object(getThis() TSRMLS_CC);
		
    data = obj->data;
	
    if (data != NULL) {
        data->set(value);
    }
}

 
zend_function_entry data_methods[] = {
    PHP_ME(Data,  __construct,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(Data,  get,           NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Data,  set,           NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};
 
PHP_MINIT_FUNCTION(in_memory)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Data", data_methods);
	
    data_ce = zend_register_internal_class(&ce TSRMLS_CC);
    data_ce->create_object = data_create_handler;
	
    memcpy(&data_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	
    data_object_handlers.clone_obj = NULL;
	
    return SUCCESS;
}
 
zend_module_entry in_memory_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_IN_MEMORY_EXTNAME,
    NULL,        /* Functions */
    PHP_MINIT(in_memory),        /* MINIT */
    NULL,        /* MSHUTDOWN */
    NULL,        /* RINIT */
    NULL,        /* RSHUTDOWN */
    NULL,        /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_IN_MEMORY_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};
 
#ifdef COMPILE_DL_IN_MEMORY
extern "C" {
ZEND_GET_MODULE(in_memory)
}
#endif
