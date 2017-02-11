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
  for (std::string const& str : args) {
    _circuit.setValue(str, false);
  }
  auto comps = _circuit.getComp();
  for (auto const& pair : comps) {
    if (pair.second.first == "input") {
      if ((static_cast<Input *>(pair.second.second))->getValue() == nts::Tristate::UNDEFINED) {
	throw UninitializeCompException("Component Error: input '" + pair.first + "' not initialize");
      }
    } else if (pair.second.first == "clock") {
      if ((static_cast<Clock *>(pair.second.second))->getValue() == nts::Tristate::UNDEFINED) {
	throw UninitializeCompException("Component Error: clock '" + pair.first + "' not initialize");
      }
    }
  }
  _shell.shell();
}
