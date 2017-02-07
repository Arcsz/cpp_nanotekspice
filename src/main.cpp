//
// main.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:24 2017 David Zeng
// Last update Thu Feb  2 00:55:24 2017 David Zeng
//

#include "Nts.hpp"
#include "Exception.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "USAGE: " << argv[0] << " [FILENAME] [ARGS...]" << std::endl;
    return 1;
  }

  nts::Nts nanotekspice;
  try {
    nanotekspice.run({argv + 1, argv + argc});
  } catch (nts::Exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
