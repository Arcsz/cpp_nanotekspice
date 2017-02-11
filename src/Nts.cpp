//
// Nts.cpp for  in /home/zeng_d/rendu/C++/cpp_nanotekspice
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sun Feb 12 00:07:52 2017 David Zeng
// Last update Sun Feb 12 00:07:52 2017 David Zeng
//

#include "Nts.hpp"
#include "Input.hpp"
#include "Clock.hpp"

nts::Nts::Nts() : _shell(_circuit), _parser(_circuit) {

}

nts::Nts::~Nts() {

}

void nts::Nts::run(std::vector<std::string> args) {
  _parser.parseFile(args[0]);
  args.erase(args.begin());

  nts::t_ast_node *root = _parser.createTree();
  _parser.parseTree(*root);
  _parser.freeTree(root);

  for (std::string const& str : args) {
    _circuit.setValue(str, false);
  }

  _circuit.checkLinks();

  _shell.shell();

}
