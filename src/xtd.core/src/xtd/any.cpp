#include "../../include/xtd/ustring.h"
#include "../../include/xtd/any.h"
#include "../../include/xtd/types.h"

using namespace std;
using namespace xtd;

std::unordered_map<std::type_index, std::function<std::string(std::any const&)>> __any_stringer__ {
  __to_any_stringer__<void>([]()->std::string {return "{}";}),
  __to_any_stringer__<bool>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char8_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char16_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char32_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<wchar_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<byte_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int16_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int32_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int64_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<llong_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<sbyte_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint16_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint32_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint64_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<ullong_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<float>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<double>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<decimal_t>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<ustring>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u8string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u16string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u32string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::wstring>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const char*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const char8_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const char16_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const char32_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const wchar_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char8_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char16_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char32_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<wchar_t*>([](auto value)->std::string {return ustring::format("{}", value);}),
};
