cmake_minimum_required(VERSION 3.3)

project(date_time_time_of_day)
find_package(xtd REQUIRED)
add_sources(src/date_time_time_of_day.cpp)
target_type(CONSOLE_APPLICATION)
