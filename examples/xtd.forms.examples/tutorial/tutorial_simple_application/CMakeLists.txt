cmake_minimum_required(VERSION 3.3)

project(tutorial_simple_application)
find_package(xtd REQUIRED)
add_sources(src/tutorial_simple_application.cpp)
target_type(GUI_APPLICATION)
