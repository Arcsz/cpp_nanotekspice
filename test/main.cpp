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
#include "../lib/include/Parser.hpp"
#include "../lib/include/Exception.hpp"

// -----------------------------------TEST---------------------------------------

bool test1() {
  nts::Parser parser;

  try {
    parser.parseFile("test/parentheses.nts");
    parser.createTree();
  } catch (...) {
    return false;
  }
  return true;
}

bool test2() {
  nts::Parser parser;

  try {
    parser.parseFile("caca.nts");
  } catch (nts::FileException const& e) {
    std::cout << e.what() << std::endl;
    return true;
  }

  return false;
}

bool test3() {
  nts::Parser parser;

  try {
    parser.parseFile("test/many_token.nts");
    parser.createTree();
  } catch (nts::ParserException const& e) {
    std::cout << e.what() << std::endl;
    return true;
  }
  return false;
}

bool test4() {
  nts::Parser parser;

  try {
    parser.parseFile("test/missing_chipset.nts");
    parser.createTree();
  } catch (nts::ParserException const& e) {
    std::cout << e.what() << std::endl;
    return true;
  }
  return false;
}

bool test5() {
  nts::Parser parser;

  try {
    parser.parseFile("test/missing_link.nts");
    parser.createTree();
  } catch (nts::ParserException const& e) {
    std::cout << e.what() << std::endl;
    return true;
  }
  return false;
}

bool test6() {
  nts::Parser parser;

  try {
    parser.parseFile("test/double_chipset.nts");
    parser.createTree();
  } catch (nts::ParserException const& e) {
    std::cout << e.what() << std::endl;
    return true;
  }
  return false;
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
    test(test1, "Empty value parentheses: \"input b()\""),
    test(test2, "File not found"),
    test(test3, "Many token"),
    test(test4, "Missing chipset"),
    test(test5, "Missing link"),
    test(test6, "Double chipset"),
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
