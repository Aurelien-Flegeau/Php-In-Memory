PHP_ARG_ENABLE(in_memory,
    [Whether to enable the "in_memory" extension],
    [  --enable-in_memory     Enable "in_memory" extension support])
 
if test $PHP_IN_MEMORY != "no"; then
    PHP_REQUIRE_CXX()
    PHP_SUBST(IN_MEMORY_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, IN_MEMORY_SHARED_LIBADD)
    PHP_NEW_EXTENSION(in_memory, in_memory.cpp data.cpp, $ext_shared)
fi

