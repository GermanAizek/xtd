cmake_minimum_required(VERSION 3.3)

project(format_sequence_containers)
find_package(xtd REQUIRED)
add_sources(src/format_sequence_containers.cpp)
target_type(CONSOLE_APPLICATION)
