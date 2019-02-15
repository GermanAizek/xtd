#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // Used test_class_attribute<> to add unit test suit.
  class test;
  test_class_attribute<test> test_class_attr {"Test"};
  
  // The test class must be inherit from test_class class.
  class test : public test_class {
  public:
    // This is the method that is called 1 time before test class run.
    class_initialize_attribute class_initialize_attr {"class_initialize", *this, &test::class_initialize};
    static void class_initialize() {
    }
    
    // This is the method that is called 1 time after test class run.
    class_cleanup_attribute class_cleanup_attr {"class_cleanup", *this, &test::class_cleanup};
    static void class_cleanup() {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    test_initialize_attribute test_initialize_attr {"test_initialize", *this, &test::test_initialize};
    static void test_initialize() {
    }
    
    // This is the method that is called after any tests in a fixture are run.
    test_cleanup_attribute test_cleanup_attr {"test_cleanup", *this, &test::test_cleanup};
    static void test_cleanup() {
    }
    
    test_method_attribute test_case1_attr {"test_case1", *this, &test::test_case1};
    void test_case1() {
    }
    
    test_method_attribute test_case2_attr {"test_case2", *this, &test::test_case2};
    void test_case2() {
    }
    
    test_method_attribute test_case3_attr {"test_case3", *this, &test::test_case3, test_state::ignored};
    void test_case3() {
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
