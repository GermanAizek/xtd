cmake_minimum_required(VERSION 3.3)

project(drive_info)
find_package(xtd REQUIRED)
add_sources(src/drive_info.cpp)
target_type(CONSOLE_APPLICATION)
