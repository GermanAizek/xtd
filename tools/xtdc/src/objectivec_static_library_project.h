#pragma once
#include "base_project.h"

namespace xtdc_command {
  class objectivec_static_library_project : public base_project {
  public:
    explicit objectivec_static_library_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_header(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(HEADERS",
        "  include/Class1.h",
        ")",
        "set(SOURCES",
        "  src/Class1.m",
        ")",
        "source_group(include FILES ${HEADERS})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_header(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#import <Foundation/Foundation.h>",
        "",
        "@interface Class1 : NSObject",
        "",
        "@end",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "Class1.h"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"../include/Class1.h\"",
        "",
        "@implementation Class1",
        "",
        "@end"
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Class1.m"), lines);
    }
  };
}
