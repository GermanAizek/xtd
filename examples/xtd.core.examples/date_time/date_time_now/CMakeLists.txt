cmake_minimum_required(VERSION 3.3)

project(date_time_now)
find_package(xtd REQUIRED)
add_sources(src/date_time_now.cpp)
target_type(CONSOLE_APPLICATION)
