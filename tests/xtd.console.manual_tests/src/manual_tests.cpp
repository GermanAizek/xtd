#include <atomic>
#include <xtd/xtd.console>

using namespace std;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  //cout << xtd::strings::format("{}, {}!", "Hello", "World"s) << endl;
  xtd::console::output_code_page(65001);
  
  xtd::console::cancel_key_press += [&](xtd::console_cancel_event_args& e) {
    xtd::console::write_line("Event handler called");
    e.cancel(true);
  };
  
  //xtd::console::treat_control_c_as_input(true);
  xtd::console::write_line(xtd::console::treat_control_c_as_input());
  xtd::console::write_line("Press escape key to quit");
  xtd::console_key_info key;
  while (key.key() != xtd::console_key::escape) {
    key = xtd::console::read_key(true);
    xtd::console::write_line("key_press [key={}, key_char='{}', modifiers={}]", key.key(), key.key_char(), key.modifiers());
  }
}
