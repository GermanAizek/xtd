cmake_minimum_required(VERSION 3.3)

project(binary_reader2)
find_package(xtd REQUIRED)
add_sources(src/binary_reader2.cpp)
target_type(CONSOLE_APPLICATION)
