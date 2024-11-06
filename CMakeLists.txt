cmake_minimum_required(VERSION 3.10)

project(BinarySearchTree)

include_directories(src/app src/binary_search_tree)

set(SOURCES src/main.cpp src/app/app.cpp src/binary_search_tree/binary_search_tree.cpp)

add_executable(BinarySearchTree ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
