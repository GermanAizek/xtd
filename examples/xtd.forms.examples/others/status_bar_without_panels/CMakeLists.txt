cmake_minimum_required(VERSION 3.3)

project(status_bar_without_panels)
find_package(xtd REQUIRED)
add_sources(src/status_bar_without_panels.cpp)
target_type(GUI_APPLICATION)
