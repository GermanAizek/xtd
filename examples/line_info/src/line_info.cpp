#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const line_info& info) {
  cout << "message: " << message << endl;
  cout << "member name: " << info.member_name() << endl;
  cout << "source file path: " << info.file_path() << endl;
  cout << "source line number: " << info.line_number() << endl;
}

// The main entry point for the application.
int main() {
  trace_message("Something happened.", {__func__, __FILE__, __LINE__});
}

// This code can produce the following output:
//
// message: Something happened.
// member name: main
// source file path: /Users/UserName/Projects/xtd/xtd.tunit/examples/line_info/src/line_info.cpp
// source line number: 16
