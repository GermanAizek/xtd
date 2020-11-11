/// @file
/// @brief Contains keys enum.
#pragma once
#include <xtd/xtd.strings>
#include "keys.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies shortcut keys that can be used by menu items.
    /// @par Library
    /// Switch.System.Windows.Forms
    /// @ingroup SwitchSystemWindowsForms
    enum class shortcut {
      alt_0 = 0x00040030,
      alt_1,
      alt_2,
      alt_3,
      alt_4,
      alt_5,
      alt_6,
      alt_7,
      alt_8,
      alt_9,
      alt_bksp = 0x00040008,
      alt_down_arrow = 0x00040028,
      alt_f1 = 0x00040070,
      alt_f10 = 0x00040079,
      alt_f11,
      alt_f12,
      alt_f2 = 0x00040071,
      alt_f3,
      alt_f4,
      alt_f5,
      alt_f6,
      alt_f7,
      alt_f8,
      alt_f9,
      alt_left_arrow = 0x00040025,
      alt_right_arrow = 0x00040027,
      alt_up_arrow = 0x00040026,
      cmd_0 = 0x00080030,
      cmd_1,
      cmd_2,
      cmd_3,
      cmd_4,
      cmd_5,
      cmd_6,
      cmd_7,
      cmd_8,
      cmd_9,
      cmd_a = 0x00080041,
      cmd_b,
      cmd_c,
      cmd_d,
      cmd_del = 0x0008002E,
      cmd_e = 0x00080045,
      cmd_f,
      cmd_f1 = 0x00080070,
      cmd_f10 = 0x00080079,
      cmd_f11,
      cmd_f12,
      cmd_f2 = 0x00080071,
      cmd_f3,
      cmd_f4,
      cmd_f5,
      cmd_f6,
      cmd_f7,
      cmd_f8,
      cmd_f9,
      cmd_g = 0x00080047,
      cmd_h,
      cmd_i,
      cmd_ins = 0x0008002D,
      cmd_j = 0x0008004A,
      cmd_k,
      cmd_l,
      cmd_m,
      cmd_n,
      cmd_o,
      cmd_p,
      cmd_q,
      cmd_r,
      cmd_s,
      cmd_shift_0 = 0x00090030,
      cmd_shift_1,
      cmd_shift_2,
      cmd_shift_3,
      cmd_shift_4,
      cmd_shift_5,
      cmd_shift_6,
      cmd_shift_7,
      cmd_shift_8,
      cmd_shift_9,
      cmd_shift_a = 0x00090041,
      cmd_shift_b,
      cmd_shift_c,
      cmd_shift_d,
      cmd_shift_e,
      cmd_shift_f,
      cmd_shift_f1 = 0x00090070,
      cmd_shift_f10 = 0x00090079,
      cmd_shift_f11,
      cmd_shift_f12,
      cmd_shift_f2 = 0x00090071,
      cmd_shift_f3,
      cmd_shift_f4,
      cmd_shift_f5,
      cmd_shift_f6,
      cmd_shift_f7,
      cmd_shift_f8,
      cmd_shift_f9,
      cmd_shift_g = 0x00090047,
      cmd_shift_h,
      cmd_shift_i,
      cmd_shift_j,
      cmd_shift_k,
      cmd_shift_l,
      cmd_shift_m,
      cmd_shift_n,
      cmd_shift_o,
      cmd_shift_p,
      cmd_shift_q,
      cmd_shift_r,
      cmd_shift_s,
      cmd_shift_t,
      cmd_shift_u,
      cmd_shift_v,
      cmd_shift_w,
      cmd_shift_x,
      cmd_shift_y,
      cmd_shift_z,
      cmd_t = 0x00080054,
      cmd_u,
      cmd_v,
      cmd_w,
      cmd_x,
      cmd_y,
      cmd_z,
      del = 0x0000002D,
      f1 = 0x00000070,
      f10 = 0x00000079,
      f11,
      f12,
      f2 = 0x00000071,
      f3,
      f4,
      f5,
      f6,
      f7,
      f8,
      f9,
      ins = 0x0000002D,
      none = 0,
      shift_del = 0x0001002E,
      shift_f1 = 0x00010070,
      shift_f10 = 0x00010079,
      shift_f11,
      shift_f12,
      shift_f2 = 0x00010071,
      shift_f3,
      shift_f4,
      shift_f5,
      shift_f6,
      shift_f7,
      shift_f8,
      shift_f9,
      shift_ins = 0x0001002D
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, shortcut value) {return os << to_string(value, {{shortcut::alt_0, "alt_0"}, {shortcut::none, "alt_1"}, {shortcut::alt_2, "alt_2"}, {shortcut::alt_3, "alt_3"}, {shortcut::alt_4, "alt_4"}, {shortcut::alt_5, "alt_5"}, {shortcut::alt_6, "alt_6"}, {shortcut::alt_7, "alt_7"}, {shortcut::alt_8, "alt_8"}, {shortcut::alt_9, "alt_9"}, {shortcut::alt_bksp, "alt_bksp"}, {shortcut::alt_down_arrow, "alt_down_arrow"}, {shortcut::alt_f1, "alt_f1"}, {shortcut::alt_f2, "alt_f2"}, {shortcut::alt_f3, "alt_f3"}, {shortcut::alt_f4, "alt_f4"}, {shortcut::alt_f5, "alt_f5"}, {shortcut::alt_f6, "alt_f6"}, {shortcut::alt_f7, "alt_f7"}, {shortcut::alt_f8, "alt_f8"}, {shortcut::alt_f9, "alt_f9"}, {shortcut::alt_left_arrow, "alt_left_arrow"}, {shortcut::alt_right_arrow, "alt_right_arrow"}, {shortcut::alt_up_arrow, "alt_up_arrow"}, {shortcut::cmd_0, "cmd_0"}, {shortcut::cmd_1, "cmd_1"}, {shortcut::cmd_2, "cmd_2"}, {shortcut::cmd_3, "cmd_3"}, {shortcut::cmd_4, "cmd_4"}, {shortcut::cmd_5, "cmd_5"}, {shortcut::cmd_6, "cmd_6"}, {shortcut::cmd_7, "cmd_7"}, {shortcut::cmd_8, "cmd_8"}, {shortcut::cmd_9, "cmd_9"}, {shortcut::cmd_a, "cmd_a"}, {shortcut::cmd_b, "cmd_b"}, {shortcut::cmd_c, "cmd_c"}, {shortcut::cmd_d, "cmd_d"}, {shortcut::cmd_del, "cmd_del"}, {shortcut::cmd_e, "cmd_e"}, {shortcut::cmd_f, "cmd_f"}, {shortcut::cmd_f1, "cmd_f1"}, {shortcut::cmd_f10, "cmd_f10"}, {shortcut::cmd_f11, "cmd_f11"}, {shortcut::cmd_f12, "cmd_f12"}, {shortcut::cmd_f2, "cmd_f2"}, {shortcut::cmd_f3, "cmd_f3"}, {shortcut::cmd_f4, "cmd_f4"}, {shortcut::cmd_f5, "cmd_f5"}, {shortcut::cmd_f6, "cmd_f6"}, {shortcut::cmd_f7, "cmd_f7"}, {shortcut::cmd_f8, "cmd_f8"}, {shortcut::cmd_f9, "cmd_f9"}, {shortcut::cmd_g, "cmd_g"}, {shortcut::cmd_h, "cmd_h"}, {shortcut::cmd_i, "cmd_i"}, {shortcut::cmd_ins, "cmd_ins"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}, {shortcut::none, "none"}});}
    inline std::wostream& operator<<(std::wostream& os, shortcut value) {return os << to_string(value, {{shortcut::alt_0, L"alt_0"}, {shortcut::none, L"alt_1"}, {shortcut::alt_2, L"alt_2"}, {shortcut::alt_3, L"alt_3"}, {shortcut::alt_4, L"alt_4"}, {shortcut::alt_5, L"alt_5"}, {shortcut::alt_6, L"alt_6"}, {shortcut::alt_7, L"alt_7"}, {shortcut::alt_8, L"alt_8"}, {shortcut::alt_9, L"alt_9"}, {shortcut::alt_bksp, L"alt_bksp"}, {shortcut::alt_down_arrow, L"alt_down_arrow"}, {shortcut::alt_f1, L"alt_f1"}, {shortcut::alt_f2, L"alt_2"}, {shortcut::alt_f3, L"alt_f3"}, {shortcut::alt_f4, L"alt_f4"}, {shortcut::alt_f5, L"alt_f5"}, {shortcut::alt_f6, L"alt_f6"}, {shortcut::alt_f7, L"alt_f7"}, {shortcut::alt_f8, L"alt_f8"}, {shortcut::alt_f9, L"alt_f9"}, {shortcut::alt_left_arrow, L"alt_left_arrow"}, {shortcut::alt_right_arrow, L"alt_right_arrow"}, {shortcut::alt_up_arrow, L"alt_up_arrow"}, {shortcut::cmd_0, L"cmd_0"}, {shortcut::cmd_1, L"cmd_1"}, {shortcut::cmd_2, L"cmd_2"}, {shortcut::cmd_3, L"cmd_3"}, {shortcut::cmd_4, L"cmd_4"}, {shortcut::cmd_5, L"cmd_5"}, {shortcut::cmd_6, L"cmd_6"}, {shortcut::cmd_7, L"cmd_7"}, {shortcut::cmd_8, L"cmd_8"}, {shortcut::cmd_9, L"cmd_9"}, {shortcut::cmd_a, L"cmd_a"}, {shortcut::cmd_b, L"cmd_b"}, {shortcut::cmd_c, L"cmd_c"}, {shortcut::cmd_d, L"cmd_d"}, {shortcut::cmd_del, L"cmd_del"}, {shortcut::cmd_e, L"cmd_e"}, {shortcut::cmd_f, L"cmd_f"}, {shortcut::cmd_f1, L"cmd_f1"}, {shortcut::cmd_f10, L"cmd_f10"}, {shortcut::cmd_f11, L"cmd_f11"}, {shortcut::cmd_f12, L"cmd_f12"}, {shortcut::cmd_f2, L"cmd_f2"}, {shortcut::cmd_f3, L"cmd_f3"}, {shortcut::cmd_f4, L"cmd_f4"}, {shortcut::cmd_f5, L"cmd_f5"}, {shortcut::cmd_f6, L"cmd_f6"}, {shortcut::cmd_f7, L"cmd_f7"}, {shortcut::cmd_f8, L"cmd_f8"}, {shortcut::cmd_f9, L"cmd_f9"}, {shortcut::cmd_g, L"cmd_g"}, {shortcut::cmd_h, L"cmd_h"}, {shortcut::cmd_i, L"cmd_i"}, {shortcut::cmd_ins, L"cmd_ins"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}, {shortcut::none, L"none"}});}
    /// @endcond
  }
}
