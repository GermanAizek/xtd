#include <xtd/xtd.strings>

#include <iostream>

using namespace std;
using namespace std::chrono_literals;

enum class buttons {
  none = 0b0,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
};

inline buttons& operator +=(buttons& lhs, buttons rhs) {lhs = static_cast<buttons>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
inline buttons& operator -=(buttons& lhs, buttons rhs) {lhs = static_cast<buttons>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
inline buttons& operator &=(buttons& lhs, buttons rhs) {lhs = static_cast<buttons>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
inline buttons& operator |=(buttons& lhs, buttons rhs) {lhs = static_cast<buttons>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
inline buttons& operator ^=(buttons& lhs, buttons rhs) {lhs = static_cast<buttons>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
inline buttons operator +(buttons lhs, buttons rhs) {return static_cast<buttons>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
inline buttons operator -(buttons lhs, buttons rhs) {return static_cast<buttons>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
inline buttons operator ~(buttons rhs) {return static_cast<buttons>(~static_cast<long long>(rhs));}
inline buttons operator &(buttons lhs, buttons rhs) {return static_cast<buttons>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
inline buttons operator |(buttons lhs, buttons rhs) {return static_cast<buttons>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
inline buttons operator ^(buttons lhs, buttons rhs) {return static_cast<buttons>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}

inline std::ostream& operator<<(std::ostream& os, buttons value) {
  return os << xtd::to_string(value, {{buttons::none, "none"}, {buttons::one, "one"}, {buttons::two, "two"}, {buttons::three, "three"}, {buttons::four, "four"}});
}

inline std::wostream& operator<<(std::wostream& os, buttons value) {
  return os << xtd::to_string(value, {{buttons::none, L"none"}, {buttons::one, L"one"}, {buttons::two, L"two"}, {buttons::three, L"three"}, {buttons::four, L"four"}});
}

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;

  wcout << xtd::strings::format(L"buttons={}", buttons::one + buttons::three) << endl;
}

// This code produces the following output:
//
// Hello, World!
