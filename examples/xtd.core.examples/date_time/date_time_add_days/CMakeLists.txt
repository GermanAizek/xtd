cmake_minimum_required(VERSION 3.3)

project(date_time_add_days)
find_package(xtd REQUIRED)
add_sources(src/date_time_add_days.cpp)
target_type(CONSOLE_APPLICATION)
