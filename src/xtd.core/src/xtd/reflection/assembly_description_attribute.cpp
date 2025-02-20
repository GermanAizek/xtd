#include "../../../include/xtd/reflection/assembly_description_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_description_attribute::assembly_description_attribute(const ustring& description) : description_(description) {
}

assembly_description_attribute::assembly_description_attribute(const ustring& description, const object& executing_assembly) : description_(description) {
  __assembly_description_attribute__() = make_shared<xtd::reflection::assembly_description_attribute>(description);
}

shared_ptr<object> assembly_description_attribute::get_type_id() const {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_description_attribute>& __assembly_description_attribute__() {
  static shared_ptr<xtd::reflection::assembly_description_attribute> description;
  return description;
}
