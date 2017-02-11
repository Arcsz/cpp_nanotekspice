//
// Shell.cpp for Shell in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Feb  7 21:13:05 2017 Riamon Vincent
// Last update Sat Feb 11 23:29:36 2017 Riamon Vincent
//

#include "StrUtils.hpp"
#include "Shell.hpp"

bool nts::Shell::_loop = false;

const std::map<std::string, nts::Shell::cmdFunc> nts::Shell::_cmdFunc = {
  {"exit", &Shell::exit},
  {"display", &Shell::display},
  {"loop", &Shell::loop},
  {"simulate", &Shell::simulate},
  {"dump", &Shell::dump},
};

nts::Shell::Shell(Circuit& circuit) : _run(true), _circuit(circuit) {
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
      try {
	_circuit.setValue(line, true);
      } catch (Exception const& e) {
	std::cerr << e.what() << std::endl;
      }
    }
    else if (line != "")
      {
	if (!_cmdFunc.count(line)) {
	  std::cout << line << ": Command not found" << std::endl;
	} else {
	  cmdFunc a = _cmdFunc.at(line);
	  (this->*a)();
	}
      }
    if (line != "exit")
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
  Shell::_loop = true;
  while (Shell::_loop) {
    _circuit.simulate();
  }
}

void nts::Shell::dump() {
  _circuit.dump();
}
