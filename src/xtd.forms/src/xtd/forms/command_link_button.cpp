#include "../../../include/xtd/forms/command_link_button.h"
#include "../../../include/xtd/forms/form.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/command_link_button.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>

using namespace xtd;
using namespace xtd::forms;

command_link_button::command_link_button() {
  flat_style(xtd::forms::flat_style::system);
  text_align(content_alignment::middle_left);
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
}

command_link_button& command_link_button::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

forms::create_params command_link_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("commandlinkbutton");
  
  create_params.style(create_params.style() | BS_COMMANDLINK);
  
  return create_params;
}

void command_link_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (image() != drawing::image::empty || (image_list().images().size() && image_index() > -1)) {
    if (flat_style() == flat_style::system) {
      native::command_link_button::image(handle(), image() != drawing::image::empty ? image() : image_list().images()[image_index()]);
      native::command_link_button::image_align(handle(), static_cast<uint32_t>(image_align()));
    }
    if (image_align() != content_alignment::middle_center) native::control::text(handle(), text());
    native::control::location(handle(), location());
    native::control::size(handle(), size());
  }
}

drawing::size command_link_button::measure_control() const {
  drawing::size size = button_base::measure_control();
  if (size.height() < default_size().height()) size.height(default_size().height());
  return size;
}
