/// @file
/// @brief Contains drive API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <string>
#include <vector>
#include "drive_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains drive native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ drive final {
    protected:
      /// @brief Gets availlable free space for specified root path.
      /// @param root_path_name root path name to get avaible free space.
      /// @param free_bytes Return number of free bytes in bytes.
      /// @param total_number_of_bytes Return totall number of bytes in bytes.
      /// @param total_number_of_free_bytes Return totall number of free bytes in bytes.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool get_available_free_space(const std::string& root_path_name, int64_t& free_bytes, int64_t& total_number_of_bytes, int64_t& total_number_of_free_bytes);
      /// @brief Gets drive type.
      /// @param root_path_name root path name to get ddrive type.
      /// @return The drive type (see drive_type.h file).
      /// @warning Internal use only
      static int32_t get_drive_type(const std::string& root_path_name);
      /// @brief Gets system drive names array.
      /// @return An array of system drive names.
      /// @warning Internal use only
      static std::vector<std::string> get_drives();
      static bool get_volume_information(const std::string& root_path_name, std::string& volume_name, std::string& file_system_name);
      static bool set_Volume_label(const sttd::string& root_path_name, const std::string& volume_name);
    };
  }
}
