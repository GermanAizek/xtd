cmake_minimum_required(VERSION 3.3)

project(interlocked)
find_package(xtd REQUIRED)
add_sources(src/interlocked.cpp)
target_type(CONSOLE_APPLICATION)
