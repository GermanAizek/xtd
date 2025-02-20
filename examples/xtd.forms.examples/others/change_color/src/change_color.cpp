#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    controls().push_back_range({change_color_button, label1, label2});
    client_size({400, 200});
    
    change_color_button.auto_size(true);
    change_color_button.location({10, 10});
    change_color_button.text("Change color");
    change_color_button.click += [&] {
      back_color(color::from_argb(rand.next<uint8_t>(), rand.next<uint8_t>(), rand.next<uint8_t>()));
      fore_color(color::from_argb(rand.next<uint8_t>(), rand.next<uint8_t>(), rand.next<uint8_t>()));
      label1.text(ustring::format("back_color = {}\nfore_color = {}", label1.back_color(), label1.fore_color()));
      label2.text(ustring::format("back_color = {}\nfore_color = {}", label2.back_color(), label2.fore_color()));
    };
    
    label1.auto_size(true);
    label1.location({10, 50});
    label1.text(ustring::format("back_color = {}\nfore_color = {}", label1.back_color(), label1.fore_color()));
    
    label2.auto_size(true);
    label2.back_color(color::dark_cyan);
    label2.fore_color(color::black);
    label2.location({10, 110});
    label2.text(ustring::format("back_color = {}\nfore_color = {}", label2.back_color(), label2.fore_color()));
  }
  
private:
  xtd::random rand;
  button change_color_button;
  label label1;
  label label2;
};

int main() {
  application::run(form1 {});
}
