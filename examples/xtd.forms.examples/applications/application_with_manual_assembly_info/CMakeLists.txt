cmake_minimum_required(VERSION 3.3)

project(application_with_manual_assembly_info)
find_package(xtd REQUIRED)
add_sources(src/application_with_manual_assembly_info.cpp properties/assembly_info.cpp)
target_type(GUI_APPLICATION)
