set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")
aux_source_directory(. ARRAY_LIST_LIB_SRC)
add_library(array_list ${ARRAY_LIST_LIB_SRC})