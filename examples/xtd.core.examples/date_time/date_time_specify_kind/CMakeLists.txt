cmake_minimum_required(VERSION 3.3)

project(date_time_specify_kind)
find_package(xtd REQUIRED)
add_sources(src/date_time_specify_kind.cpp)
target_type(CONSOLE_APPLICATION)
