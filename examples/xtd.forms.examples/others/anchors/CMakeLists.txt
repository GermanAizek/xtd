cmake_minimum_required(VERSION 3.3)

project(anchors)
find_package(xtd REQUIRED)
add_sources(src/anchors.cpp)
target_type(GUI_APPLICATION)
