//
// main.cpp<test> for  in /home/zeng_d/rendu/C++/cpp_nanotekspice/test
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sun Feb  5 15:25:08 2017 David Zeng
// Last update Sun Feb  5 15:25:08 2017 David Zeng
//

#include <functional>
#include "Parser.hpp"
#include "Exception.hpp"
#include "Circuit.hpp"

// ---------------------------------TEST UTILS-----------------------------------

bool testFileShouldThrow(std::string const& filename, bool should) {
  try {
    Circuit circuit;
    nts::Parser parser(circuit);
    parser.parseFile(filename);
    parser.createTree();
  } catch (nts::Exception const& e) {
    std::cout << e.what() << std::endl;
    return should;
  }
  return !should;
}

// -----------------------------------TEST---------------------------------------

bool test1() {
  return testFileShouldThrow("test/parentheses.nts", true);
}

bool test2() {
  return testFileShouldThrow("caca.nts", true);
}

bool test3() {
  return testFileShouldThrow("test/many_token.nts", true);
}

bool test4() {
  return testFileShouldThrow("test/missing_chipset.nts", true);
}

bool test5() {
  return testFileShouldThrow("test/missing_link.nts", true);
}

bool test6() {
  return testFileShouldThrow("test/double_chipset.nts", true);
}

bool test7() {
  return testFileShouldThrow("test/normal.nts", false);
}

bool test8() {
  return testFileShouldThrow("test/non_alphanum_comp.nts", true);
}

bool test9() {
  return testFileShouldThrow("test/non_alphanum_link.nts", true);
}

// -------------------------------TEST ENGINE------------------------------------

typedef std::function<bool()> TEST;

TEST test(TEST f, std::string const& str) {
  TEST function = [f, str] () {
    std::cout << str << "\033[00;0m" << std::endl;
    return f();
  };

  return function;
}

int main() {
  std::vector<TEST> tests = {
    test(test1, "Non matching parentheses"),
    test(test2, "File not found"),
    test(test3, "Many token"),
    test(test4, "Missing chipset"),
    test(test5, "Missing link"),
    test(test6, "Double chipset"),
    test(test7, "Normal"),
    test(test8, "Non alphanumeric component"),
    test(test9, "Non alphanumeric link"),
  };

  int i = 1;
  for (TEST t : tests) {
    std::cout << "\033[0;36;1m" << "\nTest " << i << ": ";
    try {
      if (t()) {
	std::cout << "\033[0;32;1m""Passed""\033[00;0m" << std::endl;
      } else {
	std::cout << "\033[0;31;1m""Failed""\033[00;0m" << std::endl;
      }
    } catch (std::exception const& e) {
      std::cout << e.what() << std::endl;
      std::cout << "\033[0;31;1m""Failed""\033[00;0m" << std::endl;
    }
    ++i;
  }

  return 0;
}
