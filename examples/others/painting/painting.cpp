#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Painting example");
      client_size({640, 480});
      
      panel_colors_container.parent(*this);
      panel_colors_container.border_style(forms::border_style::fixed_single);
      panel_colors_container.location({10, 10});
      panel_colors_container.client_size({512, 32});
      
      for (color color : {color::dark_magenta, color::dark_cyan, color::brown, color::dark_blue, color::dark_green, color::dark_red, color::gray, color::dark_gray, color::magenta, color::cyan, color::yellow, color::blue, color::green, color::red, color::white, color::black}) {
        shared_ptr<panel> panel_color = control::create<panel>(panel_colors_container, {0, 0}, {32, 32}, color);
        panel_color->dock(dock_style::left);
        panel_color->click += {*this, &form1::choose_current_color};
        panel_colors.push_back(panel_color);
      }
      current_color = panel_colors[panel_colors.size() - 1]->back_color();
      panel_colors[panel_colors.size() - 1]->border_style(forms::border_style::fixed_single);
      
      button_clear.parent(*this);
      button_clear.text("Clear");
      button_clear.location({542, 13});
      button_clear.click += [this] {
        picture = bitmap(picture.width(), picture.height());
        panel_painting.invalidate();
      };
      
      button_open.parent(*this);
      button_open.text("Open...");
      button_open.location({542, 47});
      button_open.click += [this] {
        open_file_dialog ofd;
        if (ofd.show_dialog() == forms::dialog_result::ok) {
          bitmap new_picture(ofd.file_name());
          if (new_picture.width() > 128 || new_picture.height() > 128)
            message_box::show(*this, "Image width and heignt must be lesser than 128 x 128", "Open image", message_box_buttons::ok, message_box_icon::error);
          else {
            picture = new_picture;
            panel_painting.size({picture.width() * zoom, picture.height() * zoom});
            panel_painting.invalidate();
          }
        }
      };

      label_zoom.parent(*this);
      label_zoom.auto_size(false);
      label_zoom.anchor(anchor_styles::top | anchor_styles::left);
      label_zoom.location({10, 60});
      label_zoom.text("Zoom");

      track_bar_zoom.parent(*this);
      track_bar_zoom.auto_size(false);
      track_bar_zoom.anchor(anchor_styles::top | anchor_styles::left);
      track_bar_zoom.location({60, 55});
      track_bar_zoom.set_range(1, 50);
      track_bar_zoom.tick_style(forms::tick_style::none);
      track_bar_zoom.value(zoom);
      track_bar_zoom.value_changed += [this] {
        zoom = track_bar_zoom.value();
        numeric_up_down_zoom.value(zoom);
        panel_painting.size({picture.width() * zoom, picture.height() * zoom});
        panel_painting.invalidate();
      };
      track_bar_zoom.size({390, 25});
      
      numeric_up_down_zoom.parent(*this);
      numeric_up_down_zoom.location({470, 55});
      numeric_up_down_zoom.set_range(1, 50);
      numeric_up_down_zoom.value(zoom);
      numeric_up_down_zoom.value_changed += [this] {
        zoom = numeric_up_down_zoom.value();
        track_bar_zoom.value(zoom);
        panel_painting.size({picture.width() * zoom, picture.height() * zoom});
        panel_painting.invalidate();
      };
      numeric_up_down_zoom.width(52);

      panel_main.parent(*this);
      panel_main.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      panel_main.auto_scroll(true);
      panel_main.border_style(forms::border_style::fixed_single);
      panel_main.location({10, 90});
      panel_main.size({620, 380});
      
      panel_painting.parent(panel_main);
      panel_painting.back_color(color::white_smoke);
      panel_painting.size({picture.width() * zoom, picture.height() * zoom});

      panel_painting.mouse_down += [this](control& sender, const mouse_event_args& e) {
        if (e.x()/zoom >= 0 && e.x()/zoom < picture.width() && e.y()/zoom >= 0 && e.y()/zoom < picture.height()) {
          picture.set_pixel(e.x()/zoom, e.y()/zoom, e.button() == mouse_buttons::left ? current_color : color::empty);
          panel_painting.invalidate(rectangle(e.x() / zoom * zoom, e.y() / zoom * zoom, zoom, zoom));
        }
      };
      
      panel_painting.mouse_move += [this](control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left && e.x()/zoom >= 0 && e.x()/zoom < picture.width() && e.y()/zoom >= 0 && e.y()/zoom < picture.height()) {
          picture.set_pixel(e.x()/zoom, e.y()/zoom, current_color);
          panel_painting.invalidate(rectangle(e.x() / zoom * zoom, e.y() / zoom * zoom, zoom, zoom));
        }
      };

      panel_painting.paint += [this](control& sender, paint_event_args& e) {
        for (int y = 0; y < panel_painting.client_size().height(); y += zoom)
          for (int x = 0; x < panel_painting.client_size().width(); x += zoom)
            if (!picture.get_pixel(x/zoom, y/zoom).is_empty())
              e.graphics().fill_rectangle(solid_brush(picture.get_pixel(x/zoom, y/zoom)), x, y, zoom, zoom);
        if (zoom > 3) {
          for (int index = 0; index < panel_painting.client_size().width(); index += zoom)
            e.graphics().draw_line(pen(color::light_blue, 1), index, 0, index, panel_painting.client_size().height());
          for (int index = 0; index < panel_painting.client_size().height(); index += zoom)
            e.graphics().draw_line(pen(color::light_blue, 1), 0, index, panel_painting.client_size().width(), index);
        }
      };
    }
  
  private:
    void choose_current_color(control& sender, const event_args& e) {
      for (auto panel : panel_colors)
        panel->border_style(panel->handle() != sender.handle() ? forms::border_style::none : forms::border_style::fixed_single);
      current_color = sender.back_color();
    }

    int zoom = 20;
    drawing::color current_color;
    bitmap picture {32, 32};

    panel panel_colors_container;
    vector<shared_ptr<panel>> panel_colors;
    button button_clear;
    button button_open;
    panel panel_main;
    panel panel_painting;
    label label_zoom;
    track_bar track_bar_zoom;
    numeric_up_down numeric_up_down_zoom;
  };
}

int main() {
  application::run(examples::form1());
}
