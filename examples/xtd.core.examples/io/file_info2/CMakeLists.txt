cmake_minimum_required(VERSION 3.3)

project(file_info2)
find_package(xtd REQUIRED)
add_sources(src/file_info2.cpp)
target_type(CONSOLE_APPLICATION)
