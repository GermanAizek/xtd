cmake_minimum_required(VERSION 3.3)

project(images3)
find_package(xtd REQUIRED)
add_sources(src/images3.cpp)
target_type(GUI_APPLICATION)
