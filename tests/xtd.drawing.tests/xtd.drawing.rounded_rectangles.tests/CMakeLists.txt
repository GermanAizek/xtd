cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.rounded_rectangles.tests)
add_references(xtd.forms)
include(../../../scripts/cmake/xtd_commands.cmake)
include(../../../scripts/cmake/xtd_version.cmake)
add_sources(src/rounded_rectangles.cpp)
target_type(GUI_APPLICATION)
