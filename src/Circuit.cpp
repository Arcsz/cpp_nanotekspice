//
// Circuit.cpp for Circuit in /home/riamon_v/rendu/CPP/cpp_nanotekspice
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Thu Feb  9 12:02:38 2017 Riamon Vincent
// Last update Thu Feb  9 15:53:37 2017 Riamon Vincent
//

#include "Circuit.hpp"
#include "Output.hpp"

nts::Circuit::Circuit() {

}

nts::Circuit::~Circuit() {

}

std::tuple<std::string, std::string> nts::Circuit::getValue(std::string const& str) {

}

void nts::Circuit::setValue(std::tuple<std::string, std::string> val) {

}

void nts::Circuit::addComponent(std::string const& type, std::string const& name,
				nts::IComponent *comp) {
  if (_components.count(name) > 0) {
    throw ComponentExistException("Element already exist");
    return ;
  }
  _components[name] = std::make_pair(type, comp);
}

void nts::Circuit::setLink() {
}

void nts::Circuit::outputDisplay() {
  for (auto const& pair : _components) {
    if (pair.second.first == "Output") {
      Output *output = static_cast<Output*>(pair.second.second);
      std::cout << pair.second.first << "=" << output->getValue() << std::endl;
    }
  }
}

void nts::Circuit::simulate() {
}
