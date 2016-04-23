cmake_minimum_required(VERSION 3.3)
project(discountjit)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O0" )

set(SOURCE_FILES main.c)
add_executable(discountjit ${SOURCE_FILES})