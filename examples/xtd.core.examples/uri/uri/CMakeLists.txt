cmake_minimum_required(VERSION 3.3)

project(uri)
find_package(xtd REQUIRED)
add_sources(src/uri.cpp)
target_type(CONSOLE_APPLICATION)
