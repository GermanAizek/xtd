cmake_minimum_required(VERSION 3.3)

project(draw_image)
find_package(xtd REQUIRED)
add_sources(src/draw_image.cpp)
target_type(GUI_APPLICATION)
