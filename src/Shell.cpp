//
// Shell.cpp for Shell in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Feb  7 21:13:05 2017 Riamon Vincent
// Last update Thu Feb  9 15:44:23 2017 Riamon Vincent
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
  nts::Shell::_loop = false;
}

void nts::Shell::shell() {
  std::string line;

  std::signal(SIGINT, ctrl_c_function);
  simulate();
  display();
  std::cout << "> ";
  while (_run && getline(std::cin, line))
    {
      line = StrUtils::trim(line);
      if (!_cmdFunc.count(line))
	std::cout << line << ": Command not found" << std::endl;
      else {
	cmdFunc a = _cmdFunc.at(line);
        (this->*a)();
      }
      std::cout << "> ";
    }
}

void nts::Shell::exit() {
  _run = false;
  std::cout << "exit run: " << _run << std::endl;
}

void nts::Shell::display() {
  std::cout << "display" << std::endl;
  _circuit.outputDisplay();
  //TODO _circuit->outputDisplay()
}

void nts::Shell::simulate() {
  std::cout << "simulate" << std::endl;
  //TODO _circuit->simulate()
}

void nts::Shell::loop() {
  nts::Shell::_loop = true;
  while (nts::Shell::_loop);
    //TODO simulate();
}

void nts::Shell::dump() {
  std::cout << "dump" << std::endl;
  //TODO _circuit->dump()
}

void nts::Shell::setValue(std::string const& name, size_t val) const {
};
