cmake_minimum_required(VERSION 3.3)

project(string_asserts)
find_package(xtd REQUIRED)

add_projects(
  string_assert_are_equal_ignoring_case
  string_assert_are_not_equal_ignoring_case
  string_assert_contains
)
