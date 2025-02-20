#include <xtd/forms/main_menu.h>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(main_menu_tests) {
  public:
    void test_method_(new_main_menu) {
      main_menu menu;
      assert::is_not_zero(menu.handle(), csf_);
      assert::is_zero(menu.menu_items().size(), csf_);
    }
  };
}
