#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_c_unit_test_application_project : public base_project {
  public:
    explicit xtd_c_unit_test_application_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      create_cmakelists_txt(name);
    }
    
  private:
    void create_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "",
        "# Install",
        "install_package()",
        "",
        "# Projects"
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
  };
}
