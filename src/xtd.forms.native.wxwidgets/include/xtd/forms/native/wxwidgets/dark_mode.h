#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

bool allow_dark_mode_for_window(intptr_t hWnd);
void init_dark_mode(int enableDarkMode);
void refresh_title_bar_theme_color(intptr_t hWnd);
