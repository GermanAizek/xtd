#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    seven_segment_display1.height(250);
    seven_segment_display1.location({(client_size().width() - seven_segment_display1.width()) / 2, (client_size().height() - seven_segment_display1.height()) / 2});
    seven_segment_display1.parent(*this);
    seven_segment_display1.fore_color(color::red);
    seven_segment_display1.anchor(anchor_styles::top | anchor_styles::bottom);
    
    timer1.interval(300ms);
    timer1.enabled(true);
    timer1.tick += [&] {
      seven_segment_display1.segment_style(segment_styles[(counter / chaser.size()) % segment_styles.size()]);
      seven_segment_display1.value(chaser[counter++ % chaser.size()]);
    };
    
    back_color(color::average(color::black, seven_segment_display1.fore_color(), 0.20));
    text("Seven segment display example");
    resize += [&] {
      seven_segment_display1.left((client_size().width() - seven_segment_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  std::vector<segments> chaser = {
    segments::none,
    segments::a,
    segments::a | segments::b,
    segments::a | segments::b | segments::c,
    segments::a | segments::b | segments::c | segments::d,
    segments::a | segments::b | segments::c | segments::d | segments::e,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g,
    segments::dp,
    segments::pc
  };
  std::vector<segment_style> segment_styles = {
    segment_style::standard,
    segment_style::modern,
    segment_style::mixed,
    segment_style::expanded,
    segment_style::design,
    segment_style::stick
  };
  seven_segment_display seven_segment_display1;
  timer timer1;
};

int main() {
  application::run(form1 {});
}
