cmake_minimum_required(VERSION 3.3)

project(bit_converter_endianness)
find_package(xtd REQUIRED)
add_sources(src/bit_converter_endianness.cpp)
target_type(CONSOLE_APPLICATION)
