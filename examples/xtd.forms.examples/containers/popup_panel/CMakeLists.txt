cmake_minimum_required(VERSION 3.3)

project(popup_panel)
find_package(xtd REQUIRED)
add_sources(src/popup_panel.cpp)
target_type(GUI_APPLICATION)
