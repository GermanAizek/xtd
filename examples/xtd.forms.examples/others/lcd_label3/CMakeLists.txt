cmake_minimum_required(VERSION 3.3)

project(lcd_label3)
find_package(xtd REQUIRED)
add_sources(src/lcd_label3.cpp)
target_type(GUI_APPLICATION)
