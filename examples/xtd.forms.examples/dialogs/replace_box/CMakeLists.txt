cmake_minimum_required(VERSION 3.3)

project(replace_box)
find_package(xtd REQUIRED)
add_sources(src/replace_box.cpp)
target_type(GUI_APPLICATION)
