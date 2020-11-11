#include <xtd/drawing/bitmap.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/busy_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <wx/iconbndl.h>

// Workaround : with wxWidgets version <= 3.1.4 wxBusyInfo does not shows hourglass cursor on macOS ==> set public m_InfoFrame...
#if !defined(__APPLE__)
#include <wx/busyinfo.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-macro"
#define private public
#include <wx/busyinfo.h>
#undef private
#pragma clang diagnostic pop
#endif

using namespace xtd;
using namespace xtd::forms::native;

intptr_t busy_dialog::create(intptr_t hwnd, const xtd::drawing::icon& icon, const std::string& text, const std::string& description, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, double transparency) {
  auto dialog = new wxBusyInfo(wxBusyInfoFlags().Parent(hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr).Icon(icon.handle() ? reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon() : wxNullIcon).Title(text).Label(description).Background(wxColour(back_color.r(), back_color.g(), back_color.b(), back_color.a())).Foreground(wxColour(fore_color.r(), fore_color.g(), fore_color.b(), fore_color.a())).Transparency(255.0 * transparency));
#if defined(__APPLE__)
  std::function<void(wxWindow*, const wxCursor*)> set_cursor = [&](wxWindow* window, const wxCursor* cursor) {
    if (!window) return;
    for (auto child : window->GetChildren())
      set_cursor(child, cursor);
    window->SetCursor(*cursor);
  };
  set_cursor(dialog->m_InfoFrame, wxHOURGLASS_CURSOR);
#endif
  return reinterpret_cast<intptr_t>(dialog);
}

void busy_dialog::destroy(intptr_t dialog) {
  delete reinterpret_cast<wxBusyInfo*>(dialog);
}
