cmake_minimum_required(VERSION 3.3)

project(binary_reader)
find_package(xtd REQUIRED)
add_sources(src/binary_reader.cpp)
target_type(CONSOLE_APPLICATION)
