#include <xtd/xtd.tunit>
#include <algorithm>

class math_assert final : private xtd::tunit::base_assert {
public:
  template<typename TValue1, typename TValue2>
  static void is_max(TValue1 value1, TValue2 value2) {is_max(value1, value2, "", xtd::tunit::line_info());}
  
  template<typename TValue1, typename TValue2>
  static void is_max(TValue1 value1, TValue2 value2, const xtd::tunit::line_info& line_info) {is_max(value1, value2, "", line_info);}
  
  template<typename TValue1, typename TValue2>
  static void is_max(TValue1 value1, TValue2 value2, const std::string& message) {is_max(value1, value2, message, xtd::tunit::line_info());}

  template<typename TValue1, typename TValue2>
  static void is_max(TValue1 value1, TValue2 value2, const std::string& message, const xtd::tunit::line_info& line_info) {
    if (std::max(value1, value2) == value1)
      base_assert::succeed(message, line_info);
    else
      base_assert::fail("greater of " + base_assert::to_string(value2), base_assert::to_string(value1), message, line_info);
  }

  template<typename TValue1, typename TValue2>
  static void is_min(TValue1 value1, TValue2 value2) {is_min(value1, value2, "", xtd::tunit::line_info());}
  
  template<typename TValue1, typename TValue2>
  static void is_min(TValue1 value1, TValue2 value2, const xtd::tunit::line_info& line_info) {is_min(value1, value2, "", line_info);}
  
  template<typename TValue1, typename TValue2>
  static void is_min(TValue1 value1, TValue2 value2, const std::string& message) {is_min(value1, value2, message, xtd::tunit::line_info());}
  
  template<typename TValue1, typename TValue2>
  static void is_min(TValue1 value1, TValue2 value2, const std::string& message, const xtd::tunit::line_info& line_info) {
    if (std::min(value1, value2) == value1)
      base_assert::succeed(message, line_info);
    else
      base_assert::fail("lesser of " + base_assert::to_string(value2), base_assert::to_string(value1), message, line_info);
  }
};

class test_class_(math_test) {
public:
  void test_method_(test_case_success) {
    math_assert::is_max(100, 20);
  }

  void test_method_(test_case_failed) {
    math_assert::is_max(20, 100);
  }
};

int main() {
  return xtd::tunit::console_unit_test().run();
}

// This code can produce the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED math_test.test_case_success (0 ms total)
//   FAILED  math_test.test_case_failed (0 ms total)
//     Expected: greater of 100
//     But was:  20
//     Stack Trace: in |---OMITTED---|/create_your_own_assertion_class.cpp:47
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
