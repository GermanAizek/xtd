cmake_minimum_required(VERSION 3.3)

project(interlocked_decrement)
find_package(xtd REQUIRED)
add_sources(src/interlocked_decrement.cpp)
target_type(CONSOLE_APPLICATION)
