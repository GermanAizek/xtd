#include <filesystem>
#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test {
public:
  static void main() {
    debug::assert(false);
    console::write_line("Hello, World!");
  }
};

startup_(xtd_core_manual_test);
