#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_pens.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/status_bar.h>
#include <xtd/forms/native/status_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/status_bar.h"
#include "../../../include/xtd/forms/status_bar_renderer.h"
#include "../../../include/xtd/forms/status_bar_panel_renderer.h"
#include "sizing_grip_control.h"
#include "status_bar_panel_control.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  struct parent_client_size_guard {
    explicit parent_client_size_guard(control& control) : control_(&control) {
      client_size_ = control_->parent().value().get().client_size();
    }
    
    ~parent_client_size_guard() {
      control_->parent().value().get().client_size(client_size_);
    }
    
  private:
    control* control_;
    drawing::size client_size_;
  };
}

status_bar::status_bar() {
  data_->main_panel.parent(*this);
  data_->main_panel.dock(dock_style::fill);
  data_->main_panel.paint += {*this, &status_bar::on_main_panel_paint};
  
  data_->sizing_grip_control = std::make_shared<sizing_grip_control>();
  data_->sizing_grip_control->cursor(cursors::from_name(native::status_bar::sizing_grip_cursor_name()));
  data_->sizing_grip_control->dock(dock_style::right);
  data_->sizing_grip_control->parent(*this);
  data_->sizing_grip_control->visible(data_->sizing_grip && native::status_bar::sizing_grip());
  data_->sizing_grip_control->size({16, 16});

  data_->panels.item_added += {*this, &status_bar::on_item_added};
  data_->panels.item_updated += {*this, &status_bar::on_item_updated};
  data_->panels.item_removed += {*this, &status_bar::on_item_removed};
  
  dock(dock_style::bottom);
  padding(forms::padding {0, 1, 0, 0});
  set_can_focus(false);
  set_style(control_styles::user_paint | control_styles::selectable, false);
}

dock_style status_bar::dock() const {
  //if (is_system_status_bar()) return data_->non_system_dock;
  return control::dock();
}

control& status_bar::dock(dock_style dock) {
  if (is_system_status_bar()) {
    data_->non_system_dock = dock;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  } else {
    int32_t current_size = is_horizontal() ? height() : width();
    control::dock(dock);
    if (is_horizontal()) height(current_size);
    else width(current_size);
  }
  return *this;
}

const status_bar::status_bar_panel_collection& status_bar::panels() const {
  return data_->panels;
}

status_bar::status_bar_panel_collection& status_bar::panels() {
  return data_->panels;
}

bool status_bar::show_panels() const {
  return data_->show_panels;
}

status_bar& status_bar::show_panels(bool value) {
  if (data_->show_panels != value) {
    data_->show_panels = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  }
  return *this;
}

bool status_bar::show_tool_tips() const {
  return data_->show_tool_tips;
}

status_bar& status_bar::show_tool_tips(bool value) {
  if (data_->show_tool_tips != value) {
    data_->show_tool_tips = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  }
  return *this;
}

bool status_bar::sizing_grip() const {
  return data_->sizing_grip;
}

status_bar& status_bar::sizing_grip(bool value) {
  if (data_->sizing_grip != value) {
    data_->sizing_grip = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else data_->sizing_grip_control->visible(value && native::status_bar::sizing_grip());
  }
  return *this;
}

forms::create_params status_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  if (is_system_status_bar())
    create_params.class_name("statusbar");
    
  if (data_->non_system_dock == dock_style::left) create_params.style(create_params.style() | SBARS_LEFT);
  else if (data_->non_system_dock == dock_style::right) create_params.style(create_params.style() | SBARS_RIGHT);
  else if (data_->non_system_dock == dock_style::bottom) create_params.style(create_params.style() | SBARS_BOTTOM);
  if (!data_->show_tool_tips) create_params.style(create_params.style() | SBARS_TOOLTIPS);
  if (data_->sizing_grip) create_params.style(create_params.style() | SBARS_SIZEGRIP);
  
  return create_params;
}

xtd::drawing::font status_bar::default_font() const {
  return xtd::drawing::system_fonts::status_font();
}

drawing::size status_bar::default_size() const {
  return native::control::default_size("toolbar");
}

void status_bar::on_control_appearance_changed(const xtd::event_args&) {
  if (control_appearance() == forms::control_appearance::system) {
    data_->non_system_dock = control::dock();
    control::dock(dock_style::none);
    data_->main_panel.visible(false);
    data_->sizing_grip_control->visible(false);
  } else {
    control::dock(data_->non_system_dock);
    data_->main_panel.visible(true);
    data_->sizing_grip_control->visible(data_->sizing_grip && native::status_bar::sizing_grip());
  }
}

void status_bar::on_draw_item(xtd::forms::status_bar_draw_item_event_args& e) {

}

void status_bar::on_panel_click(const xtd::forms::status_bar_panel_click_event_args& e) {

}

void status_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  fill();
}

void status_bar::on_handle_destroyed(const event_args& e) {
  if (is_system_status_bar()) {
    native::status_bar::set_system_status_bar(parent().value().get().handle(), 0);
    data_->system_status_bar_panel_handles.clear();
  }
  control::on_handle_destroyed(e);
}

void status_bar::on_paint(xtd::forms::paint_event_args& e) {
  control::on_paint(e);
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard)
    status_bar_renderer::draw_status_bar(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, std::nullopt, xtd::forms::border_sides::all);
}

void status_bar::on_main_panel_paint(object& sender, xtd::forms::paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard && !data_->show_panels)
    status_bar_renderer::draw_text_status_bar(style, e.graphics(), e.clip_rectangle(), text(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font());
}

void status_bar::on_resize(const event_args& e) {
  control::on_resize(e);
  resize_spring_panels();
}

bool status_bar::is_horizontal() const {
  return dock() != dock_style::left && dock() != dock_style::right;
}

bool status_bar::is_system_status_bar() const {
  auto result = data_->is_system_status_bar || control_appearance() == xtd::forms::control_appearance::system;
  return result;
}

status_bar& status_bar::is_system_status_bar(bool value) {
  if (data_->is_system_status_bar != value) {
    control_appearance(value ? forms::control_appearance::system : forms::control_appearance::standard);
    data_->is_system_status_bar = value;
    post_recreate_handle();
  }
  return *this;
}

void status_bar::fill() {
  /*
  if (data_->panels.size() == 0) return;
  suspend_layout();
  controls().clear();
  data_->spring_panels.clear();
  data_->status_bar_panels.clear();
  auto reversed_panels = data_->panels;
  if (!is_system_status_bar()) std::reverse(reversed_panels.begin(), reversed_panels.end());
  if (!is_system_status_bar() && auto_size())
    size({padding().left() + padding().right(), padding().top() + padding().bottom()});
  for (size_t index = 0; index < reversed_panels.size(); ++index) {
    auto& button_item = reversed_panels[index].get();
    intptr_t control_handle = 0;
    if (is_system_status_bar()) {
      if (reversed_panels[index].get().style() == status_bar_panel_style::push_button || (!data_->drop_down_arrows && button_item.style() == status_bar_panel_style::drop_down_button))
        control_handle = native::status_bar::add_status_bar_panel(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible());
      else if (reversed_panels[index].get().style() == status_bar_panel_style::toggle_button)
        control_handle = native::status_bar::add_status_bar_toggle_button(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, reversed_panels[index].get().pushed(), button_item.enabled(), button_item.visible());
      else if (reversed_panels[index].get().style() == status_bar_panel_style::separator)
        control_handle = native::status_bar::add_status_bar_separator(handle());
      else if (reversed_panels[index].get().style() == status_bar_panel_style::drop_down_button)
        control_handle = native::status_bar::add_status_bar_drop_down_button(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible(), button_item.drop_down_menu().has_value() ? button_item.drop_down_menu().value().get().handle() : 0);
      else if (reversed_panels[index].get().style() == status_bar_panel_style::stretchable_separator)
        control_handle = native::status_bar::add_status_bar_stretchable_separator(handle());
      else if (reversed_panels[index].get().style() == status_bar_panel_style::control) {
        if (button_item.control().has_value()) button_item.control().value().get().parent(*this);
        control_handle = native::status_bar::add_status_bar_control(handle(), button_item.control().has_value() ? button_item.control().value().get().handle() : 0, button_item.text(), button_item.tool_tip_text());
      }
      reversed_panels[index].get().data_->handle = control_handle;
      data_->system_status_bar_panel_handles.push_back(control_handle);
      button_item.data_->rectangle = drawing::rectangle(native::status_bar::status_bar_item_rectangle(handle(), control_handle));
    } else {
      auto button_control = std::make_shared<status_bar_panel_control>();
      button_item.data_->handle = reinterpret_cast<intptr_t>(button_control.get());
      button_control->parent(*this);
      button_control->status_bar_panel(button_item);
      if (is_horizontal()) button_control->dock(dock_style::left);
      else button_control->dock(dock_style::top);
      button_control->enabled(button_item.enabled());
      button_control->flat(appearance() == status_bar_appearance::flat);
      button_control->image_size(image_size());
      button_control->show_icon(data_->show_icon);
      button_control->show_text(data_->show_text);
      button_control->size(button_size());
      if (!data_->drop_down_arrows && button_item.style() == status_bar_panel_style::drop_down_button)
        button_control->style(status_bar_panel_style::push_button);
      else
        button_control->style(button_item.style());
      button_control->status_bar_text_align(data_->text_align);
      button_control->pushed(button_item.pushed());
      button_control->visible(button_item.visible());
      if (button_item.style() == status_bar_panel_style::separator || button_item.style() == status_bar_panel_style::stretchable_separator) {
        button_control->height(image_size().height() / 2);
        button_control->width(image_size().width() / 2);
      }
      if (button_item.style() == status_bar_panel_style::stretchable_separator)
        data_->spring_panels.push_back(button_control);
      if (button_item.style() == status_bar_panel_style::control && button_item.control().has_value()) {
        button_control->control(&button_item.control().value().get());
        button_item.control().value().get().parent(*button_control);
      }
      if (button_item.style() == status_bar_panel_style::drop_down_button && button_item.drop_down_menu().has_value())
        button_control->drop_down_menu(const_cast<forms::context_menu*>(&button_item.drop_down_menu().value().get()));
  
      /// @todo Add xtd::forms::tool_tip when implemented.
  
      if ((data_->show_icon || !data_->show_text) && button_item.image_index() < data_->image_list.images().size()) button_control->image(data_->image_list.images()[button_item.image_index()]);
      if (data_->show_text) button_control->text(button_item.text());
  
      if (auto_size()) {
        if (is_horizontal() && height() < button_control->height()) height(button_control->height() + padding().top() + padding().bottom());
        if (!is_horizontal() && width() < button_control->width()) width(button_control->width() + padding().left() + padding().right());
        if (is_horizontal()) width(width() + button_control->width());
        else height(height() + button_control->height());
      }
  
      button_item.data_->rectangle = drawing::rectangle(button_control->location(), button_control->size());
  
      data_->status_bar_panels.push_back(button_control);
    }
  }
  
  if (is_system_status_bar()) {
    parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
    native::status_bar::set_system_status_bar(parent().value().get().handle(), handle());
  }
  
  resume_layout();
   */
}

void status_bar::on_item_added(size_t pos, status_bar_panel_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().data_->parent = this;
  post_recreate_handle();
}

void status_bar::on_item_updated(size_t pos, status_bar_panel_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  post_recreate_handle();
}

void status_bar::on_item_removed(size_t pos, status_bar_panel_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().data_->parent = nullptr;
  post_recreate_handle();
}

void status_bar::wnd_proc(message& message) {
  control::wnd_proc(message);
}

void status_bar::resize_spring_panels() {
  /*
  if (data_->spring_panels.size()) {
    auto remaining_size = is_horizontal() ? size().width() - padding().left() - padding().right() : size().height() - padding().top() - padding().bottom();
    for (auto status_bar_panel : data_->status_bar_panels) {
      if (status_bar_panel->style() != status_bar_panel_style::stretchable_separator && status_bar_panel->visible())
        remaining_size -= is_horizontal() ? status_bar_panel->size().width() : status_bar_panel->size().height();
    }
  
    auto stretchable_size = remaining_size / as<int32_t>(data_->spring_panels.size());
    for (auto stretchable_separator : data_->spring_panels) {
      auto default_stretchable_size = (is_horizontal() ? image_size().width() : image_size().height()) / 2;
      if (stretchable_size > default_stretchable_size) {
        if (is_horizontal()) stretchable_separator->width(stretchable_size);
        else stretchable_separator->height(stretchable_size);
      } else {
        if (is_horizontal()) stretchable_separator->width(default_stretchable_size);
        else stretchable_separator->height(default_stretchable_size);
      }
    }
    perform_layout();
  }
   */
}

void status_bar::update_status_bar_panel_control(intptr_t handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, xtd::forms::horizontal_alignment alignment, xtd::forms::status_bar_panel_auto_size auto_size, xtd::forms::status_bar_panel_border_style border_style, xtd::forms::status_bar_panel_style panel_style, int32_t min_width, int32_t width) {
  if (!handle) return;
  if (is_system_status_bar()) {
    //native::status_bar::update_status_bar_item(this->handle(), handle, text, tool_tip_text, image, visible(), 100, false);
  } else {
    reinterpret_cast<status_bar_panel_control*>(handle)->text(text);
    reinterpret_cast<status_bar_panel_control*>(handle)->tool_tip_text(tool_tip_text);
    reinterpret_cast<status_bar_panel_control*>(handle)->image(image);
    reinterpret_cast<status_bar_panel_control*>(handle)->alignment(alignment);
    reinterpret_cast<status_bar_panel_control*>(handle)->status_bar_panel_auto_size(auto_size);
    reinterpret_cast<status_bar_panel_control*>(handle)->status_bar_panel_border_style(border_style);
    reinterpret_cast<status_bar_panel_control*>(handle)->style(panel_style);
    reinterpret_cast<status_bar_panel_control*>(handle)->min_width(min_width);
    reinterpret_cast<status_bar_panel_control*>(handle)->width(width);
    resize_spring_panels();
  }
}
