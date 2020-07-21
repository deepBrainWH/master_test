set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_executable(parentheses_app parentheses.h parentheses.c)
add_executable(arithmetic_expression_app arithmetic_expression.c arithmetic_expression.h)

add_executable(Conversion Conversion.h Conversion.cc SeqStack/stack_data_structure.h SeqStack/stack_data_structure.cc)

add_executable(LineEdit  LineEdit.h LineEdit.cc SeqStack/stack_data_structure.h SeqStack/stack_data_structure.cc)

add_executable(Maze maze_main.c maze_DFS.h maze_DFS.c SeqStack/stack_data_structure.h SeqStack/stack_data_structure.cc)