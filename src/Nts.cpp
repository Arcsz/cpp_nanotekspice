#include "Nts.hpp"

nts::Nts::Nts() : _shell(_circuit), _parser(_circuit) {

}

nts::Nts::~Nts() {

}

void nts::Nts::run(std::vector<std::string> args) {
  _parser.parseFile(args[0]);
  args.erase(args.begin());

  nts::t_ast_node *root = _parser.createTree();
  _parser.parseTree(*root);
  for (std::string const& str : args) {
    _circuit.setValue(str, false);
  }
  _shell.shell();
}
