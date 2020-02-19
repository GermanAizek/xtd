#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#pragma once

#include <xtd/xtd>

namespace settings_example::properties {
  class settings : public xtd::forms::component {
  public:
    settings() : ::settings_example::properties::settings(true) {}

    static ::settings_example::properties::settings& default_settings() {
      static ::settings_example::properties::settings default_settings;
      return default_settings;
    }

    xtd::drawing::color back_color() const {return back_color_;}
    void back_color(xtd::drawing::color value) {back_color_ = value;}

    xtd::drawing::point location() const {return location_;}
    void location(xtd::drawing::point value) {location_ = value;}

    xtd::drawing::size size() const {return size_;}
    void size(xtd::drawing::size value) {size_ = value;}

    std::string text() {return "Settings example";}

    void reload() {
      back_color_ = settings_.read("back_color", back_color_);
      location_ = settings_.read("location", location_);
      size_ = settings_.read("size", size_);
    }

    void reset() {
      settings_.reset();
      *this = settings(false);
      reload();
    }

    void save() {
      settings_.write("back_color", back_color_);
      settings_.write("location", location_);
      settings_.write("size", size_);
      settings_.save();
    }

  private:
    settings(bool load) {if (load) reload();}
    xtd::forms::settings settings_;
    xtd::drawing::color back_color_ {xtd::drawing::system_colors::control()};
    xtd::drawing::point location_ {{100, 50}};
    xtd::drawing::size size_ {{360, 80}};
  };
}

#pragma endregion
