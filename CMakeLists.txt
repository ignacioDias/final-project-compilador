cmake_minimum_required(VERSION 3.29)
project(final_project_compilador C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libraries)

add_executable(final_project_compilador
    code/pseudoAssembly.c
    code/symbols_table.c
    code/tree.c
    libraries/pseudoAssembly.h
    libraries/stack.h
    libraries/symbols_table.h
    libraries/tree.h
    calc-sintaxis.tab.c
    calc-sintaxis.tab.h
    lex.yy.c)
