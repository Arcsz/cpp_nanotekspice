//
// main.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:24 2017 David Zeng
// Last update Thu Feb  2 00:55:24 2017 David Zeng
//

#include "../lib/include/Exception.hpp"
#include "../lib/include/Parser.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "USAGE: " << argv[0] << " [FILENAME] [ARGS...]" << std::endl;
    return 1;
  }

  try {
    nts::Parser parser;
    // TODO: parse command line and give right arg to parser
    parser.parseFile(argv[1]);
    nts::t_ast_node *root = parser.createTree();
    // TODO DELETE DUMP
    parser.dump(root);
  } catch (nts::Exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
