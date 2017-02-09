//
// Shell.cpp for Shell in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Feb  7 21:13:05 2017 Riamon Vincent
// Last update Thu Feb  9 21:05:47 2017 Riamon Vincent
//

#include "StrUtils.hpp"
#include "Shell.hpp"

bool nts::Shell::_loop = false;

const std::map<std::string, nts::Shell::cmdFunc> nts::Shell::_cmdFunc = {
  {"exit", &nts::Shell::exit},
  {"display", &nts::Shell::display},
  {"loop", &nts::Shell::loop},
  {"simulate", &nts::Shell::simulate},
  {"dump", &nts::Shell::dump},
};

nts::Shell::Shell(Circuit& circuit) : _run(true), _circuit(circuit) {
  (void)_circuit; // TODO REMOVE
}

nts::Shell::~Shell() {
}

void ctrl_c_function(int n) {
  (void)n;
  if (nts::Shell::_loop == true) {
    nts::Shell::_loop = false;
    std::cout << std::endl;
  } else {
    std::cout << "\n> " << std::flush;
  }
}

void nts::Shell::shell() {
  std::signal(SIGINT, ctrl_c_function);

  simulate();
  display();

  std::cout << "> ";
  std::string line;
  while (_run && getline(std::cin, line)) {
    line = StrUtils::trim(line);

    if (line.find('=') != std::string::npos) {
      
    }
    else if (!_cmdFunc.count(line)) {
      std::cout << line << ": Command not found" << std::endl;
    } else {
      cmdFunc a = _cmdFunc.at(line);
      (this->*a)();
    }
    std::cout << "> ";
  }
}

void nts::Shell::exit() {
  _run = false;
}

void nts::Shell::display() {
  _circuit.outputDisplay();
}

void nts::Shell::simulate() {
  _circuit.simulate();
}

void nts::Shell::loop() {
  nts::Shell::_loop = true;
  while (nts::Shell::_loop)
    _circuit.simulate();
}

void nts::Shell::dump() {
  _circuit.dump();
}

void nts::Shell::setValue(std::string const& name, size_t val) const {
}
