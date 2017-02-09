//
// Circuit.cpp for Circuit in /home/riamon_v/rendu/CPP/cpp_nanotekspice
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Feb  9 12:02:38 2017 Riamon Vincent
// Last update Thu Feb  9 16:21:47 2017 Riamon Vincent
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
  if (_components.count(name) > 0) {
    throw ComponentExistException("Component already exist: " + name);
  }
  _components[name] = std::make_pair(type, comp);
}

void nts::Circuit::setLink(std::string const& name1, size_t pin1,
			   std::string const& name2, size_t pin2) {
  if (_components.count(name1) == 0) {
    throw ComponentNotFoundException("Component not found: " + name1);
  } else if (_components.count(name2) == 0) {
    throw ComponentNotFoundException("Component not found: " + name2);
  }
  IComponent *comp1 = _components[name1].second;
  IComponent *comp2 = _components[name2].second;
  comp1->SetLink(pin1, *comp2, pin2);
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
  for (auto const& pair : _components) {
    std::cout << pair.first << ": " << pair.second.first << std::endl;
  }
}
