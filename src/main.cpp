//
// main.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:24 2017 David Zeng
// Last update Thu Feb  2 00:55:24 2017 David Zeng
//

#include "../lib/include/Parser.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "USAGE: " << argv[0] << " [FILENAME] [ARGS...]" << std::endl;
  }

  Parser parser;
  // TODO: parse command line and give right arg to parser
  parser.parseFile(argv[1]);
  parser.createTree();
  return 0;
}
