#include <functional>
#include "../lib/include/Parser.hpp"

bool test1() {
  nts::Parser parser;

  parser.parseFile("test1.nts");
  return true;
}

std::function<bool()> test(std::function<bool()> f, std::string const& str) {
  auto function = [f, str] () {
    std::cout << str << std::endl;
    return f();
  };
  return function;
}

int main() {
  std::function<bool()> tests[1] = {
    test(test1, "Empty value parentheses: \"input b()\""),
  };

  int i = 1;
  for (auto t : tests) {
    std::cout << "Test " << i << ": ";
    if (t()) {
      std::cout << "Passed" << std::endl;
    } else {
      std::cout << "Failed" << std::endl;
    }
    ++i;
  }
  return 0;
}
