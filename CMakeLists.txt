cmake_minimum_required (VERSION 2.6)
project (Sorting)
add_library(SortFuncs sort.c)

add_executable(sort main.c)
target_link_libraries (sort SortFuncs)

