/// @file
/// @brief Contains xtd::tracestreambuf class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "object.h"
#include "diagnostics/trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an std::stringbuf for xtd::diagnostics::trace.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class tracestreambuf : public object, public std::stringbuf {
  public:
    int sync() override {
#if defined(TRACE)
      if (!str().empty()) {
        if (str() == "\n") xtd::diagnostics::trace::write_line();
        else if (strings::ends_with(str(), '\n')) xtd::diagnostics::trace::write_line(strings::trim_end(str(), '\n'));
        else xtd::diagnostics::trace::write(str());
        str("");
      }
#endif
      return 0;
    }
  };
}
