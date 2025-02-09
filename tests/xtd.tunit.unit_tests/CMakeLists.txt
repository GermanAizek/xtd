cmake_minimum_required(VERSION 3.3)

# Options
if (MSVC)
  add_compile_options(/wd4834)
endif ()

# Project
project(xtd.tunit.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(
  src/main.cpp
  src/xtd/tunit/tests/assert_unit_tests.h
  src/xtd/tunit/tests/assert_abort_aborted_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_char_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_char_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_char16_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_char16_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_char32_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_wchar_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_const_wchar_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_double_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_double_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_double_NaN_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_double_with_tolerence_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_double_with_tolerence_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_float_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_float_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_float_NaN_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_float_with_tolerence_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_float_with_tolerence_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_long_double_with_tolerence_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_equal_long_double_with_tolerence_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char16_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char16_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char32_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_char32_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_wchar_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_equal_const_wchar_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_same_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_not_same_succeed_tests.cpp
  src/xtd/tunit/tests/assert_are_same_failed_tests.cpp
  src/xtd/tunit/tests/assert_are_same_succeed_tests.cpp
  src/xtd/tunit/tests/assert_contains_collection_failed_tests.cpp
  src/xtd/tunit/tests/assert_contains_collection_succeed_tests.cpp
  src/xtd/tunit/tests/assert_contains_string_failed_tests.cpp
  src/xtd/tunit/tests/assert_contains_string_succeed_tests.cpp
  src/xtd/tunit/tests/assert_does_not_throw_failed_tests.cpp
  src/xtd/tunit/tests/assert_does_not_throw_succeed_tests.cpp
  src/xtd/tunit/tests/assert_fail_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_empty_collection_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_empty_collection_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_empty_string_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_empty_string_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_false_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_false_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_greater_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_greater_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_greater_or_equal_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_greater_or_equal_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_instance_of_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_instance_of_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_less_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_less_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_less_or_equal_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_less_or_equal_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_double_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_double_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_float_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_float_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_long_double_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_NaN_long_double_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_negative_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_negative_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_empty_collection_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_empty_collection_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_empty_string_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_empty_string_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_instance_of_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_instance_of_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_nullptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_unique_ptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_unique_ptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_shared_ptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_shared_ptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_null_weak_ptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_zero_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_not_zero_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_nullptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_pointer_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_unique_ptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_unique_ptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_shared_ptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_shared_ptr_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_null_weak_ptr_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_positive_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_positive_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_succeed_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_true_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_true_succeed_tests.cpp
  src/xtd/tunit/tests/assert_is_zero_failed_tests.cpp
  src/xtd/tunit/tests/assert_is_zero_succeed_tests.cpp
  src/xtd/tunit/tests/assert_throws_failed_tests.cpp
  src/xtd/tunit/tests/assert_throws_succeed_tests.cpp
  src/xtd/tunit/tests/assert_throws_any_failed_tests.cpp
  src/xtd/tunit/tests/assert_throws_any_succeed_tests.cpp
  src/xtd/tunit/tests/insert_basic_output_stream_operator_tests.cpp
  src/xtd/tunit/tests/one_test_one_test_case_tests.cpp
  src/xtd/tunit/tests/one_test_two_test_cases_tests.cpp
  src/xtd/tunit/tests/one_test_two_test_cases_and_one_ignore_test_case_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char_pointer_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char16_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char16_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char32_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_char32_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_wchar_t_pointer_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_string_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_string_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_u16string_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_u16string_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_u32string_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_u32string_succeed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_wstring_failed_tests.cpp
  src/xtd/tunit/tests/string_assert_are_equal_ignoring_case_wstring_succeed_tests.cpp
  src/xtd/tunit/tests/two_tests_five_test_cases_tests.cpp
  src/xtd/tunit/tests/unit_tests_event_listener.h
)
target_type(TEST_APPLICATION)
