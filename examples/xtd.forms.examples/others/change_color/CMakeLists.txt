cmake_minimum_required(VERSION 3.3)

project(change_color)
find_package(xtd REQUIRED)
add_sources(src/change_color.cpp)
target_type(GUI_APPLICATION)
