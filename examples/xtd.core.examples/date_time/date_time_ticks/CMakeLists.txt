cmake_minimum_required(VERSION 3.3)

project(date_time_ticks)
find_package(xtd REQUIRED)
add_sources(src/date_time_ticks.cpp)
target_type(CONSOLE_APPLICATION)
