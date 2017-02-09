//
// Circuit.cpp for Circuit in /home/riamon_v/rendu/CPP/cpp_nanotekspice
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Feb  9 12:02:38 2017 Riamon Vincent
// Last update Thu Feb  9 17:57:32 2017 Riamon Vincent
//

#include "Circuit.hpp"
#include "Output.hpp"
#include "Clock.hpp"

nts::Circuit::Circuit() {

}

nts::Circuit::~Circuit() {

}

std::pair<std::string, std::string> nts::Circuit::getValue(std::string const& str) {

}

void nts::Circuit::setValue(std::pair<std::string, std::string> val) {

}

void nts::Circuit::addComponent(std::string const& type, std::string const& name,
				nts::IComponent *comp) {
  if (_components.count(name) > 0)
    throw ComponentExistException("Element already exist");
  _components[name] = std::make_pair(type, comp);
}

void nts::Circuit::setLink() {
}

void nts::Circuit::outputDisplay() {
  for (auto const& pair : _components) {
    if (pair.second.first == "output") {
      Output *output = static_cast<Output*>(pair.second.second);
      std::cout << pair.second.first << "=" << output->getValue() << std::endl;
    }
  }
}

void nts::Circuit::simulate() {
  for (auto const& pair : _components) {
    if (pair.second.first == "output") {
      (static_cast<Output *>(pair.second.second))->Compute();
    }
  }
  clockInverse();
}

void nts::Circuit::clockInverse() {
  for (auto const& pair : _components) {
    if (pair.second.first == "clock") {
      (static_cast<Clock*>(pair.second.second))->inverted();
    }
  }
}

void nts::Circuit::dump() {
  for (auto const& pair : _components) {
    std::cout << pair.second.first << ":" << std::endl;
    pair.second.second->Dump();
  }
}

void nts::Circuit::printComp() const {
  for (std::pair<std::string, std::pair<std::string, IComponent*>> pair : _components) {
    std::cout << pair.first << ": " << pair.second.first << std::endl;
  }
}
