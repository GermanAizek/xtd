cmake_minimum_required(VERSION 3.3)

project(circular_form)
find_package(xtd REQUIRED)
add_sources(src/circular_form.cpp)
target_type(GUI_APPLICATION)
