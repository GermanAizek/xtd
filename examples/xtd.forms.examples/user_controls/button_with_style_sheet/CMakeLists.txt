cmake_minimum_required(VERSION 3.3)

project(button_with_style_sheet)
find_package(xtd REQUIRED)
add_sources(src/button_with_style_sheet.cpp)
target_type(GUI_APPLICATION)
