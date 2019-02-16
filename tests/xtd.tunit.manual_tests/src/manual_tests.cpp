#include <xtd/tunit>
#include <string>
#include <tuple>
#include <regex>
#include <vector>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

class version final {
public:
  version() = default;
  version(int major, int minor) : major_(major), minor_(minor) {}
  version(int major, int minor, int build) : major_(major), minor_(minor), build_(build) {}
  version(int major, int minor, int build, int revision) : major_(major), minor_(minor), build_(build), revision_(revision) {}
  version(const version&) = default;
  version& operator=(const version&) = default;
  
  bool operator==(const version& v) const {return this->major_ == v.major_ && this->minor_ == v.minor_ && this->build_ == v.build_ && this->revision_ == v.revision_;}
  bool operator!=(const version& v) const {return this->operator==(v);}
  
  int build() const {return this->build_;}
  int major() const {return this->major_;}
  int16_t major_revision() const {return (int16_t)((this->revision_ & 0xFFFF0000) >> 16);}
  int minor() const {return this->minor_;}
  int16_t mainor_revision() const {return (int16_t)(this->revision_ & 0x0000FFFF);}
  int revision() const {return this->revision_;}
  
  static version parse(const std::string& ver) {
    std::regex rgx("\\.");
    std::vector<std::string> versions;
    for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
      versions.push_back(*it);
    
    switch (versions.size()) {
      case 2: return version(std::stoi(versions[0]), std::stoi(versions[1]));
      case 3: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]));
      case 4: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]), std::stoi(versions[3]));
    }
    throw std::invalid_argument("bad format");
  }
  
  static bool try_parse(const std::string& ver, version& result) {
    try {
      result = parse(ver);
      return true;
    } catch (...) {
      return false;
    }
  }
  
  std::string to_string() const {
    return this->to_string(2 + (this->build_ != -1 ? 1 : 0) + (this->revision_ != -1 ? 1 : 0));;
  }
  
  std::string to_string(size_t field_count) const {
    if (field_count > 4 || (field_count >= 3 && this->build_ == -1) || (field_count == 4 && this->revision_ == -1))
      throw std::invalid_argument("field_count invalid");
    std::stringstream result;
    if (field_count >= 1)
      result << std::to_string(this->major_);
    if (field_count >= 2)
      result << "." << std::to_string(this->minor_);
    if (field_count >= 3)
      result << "." << std::to_string(this->build_);
    if (field_count == 4)
      result << "." << std::to_string(this->revision_);
    return result.str();
  }
  
  friend std::ostream& operator <<(std::ostream& os, const version& ver) {
    return os << ver.to_string();
  }
  
private:
  int major_ = 0;
  int minor_ = 0;
  int build_ = -1;
  int revision_ = -1;
};

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
    }
    
    void test_method_(test_case2) {
      xtd::tunit::assert::greater_or_equal(24, 12, "User message...", line_info_); // test ok
      //xtd::tunit::assert::greater(24, 48, "User message...", line_info_); // test throws an assertion_error exception.
      
      std::vector v1 = {1, 2, 3, 4};
      assert::are_equal(false, std::empty(v1));
      std::vector<int> v2;
      assert::are_equal(true, std::empty(v2));
      std::string s1 = "1234";
      assert::are_equal(false, std::empty(s1));
      std::string s2;
      assert::are_equal(false, std::empty(s2));
    }
    
    void test_method_(test_case3) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
