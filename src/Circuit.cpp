//
// Circuit.cpp for Circuit in /home/riamon_v/rendu/CPP/cpp_nanotekspice
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Feb  9 12:02:38 2017 Riamon Vincent
// Last update Fri Feb 10 12:44:04 2017 Riamon Vincent
//

#include "Circuit.hpp"
#include "StrUtils.hpp"
#include "ComponentFactory.hpp"

nts::Circuit::Circuit() {

}

nts::Circuit::~Circuit() {
  for (auto& comp : _components) {
    delete comp.second;
  }
}

void nts::Circuit::setValue(std::string const& str, bool isShell) {
  std::string name = StrUtils::trim(str.substr(0, str.find('=')));
  std::string value = StrUtils::trim(str.substr(str.find('=') + 1, str.size()));

  if (_components.count(name) == 0) {
    throw ComponentNotFoundException("Component not found: " + name);
  } else if ((isShell && _components[name]->getType() != CONST::INPUT) ||
	     (!isShell && _components[name]->getType() != CONST::INPUT &&
	      _components[name]->getType() != CONST::CLOCK)) {
    throw UnmodifiedException("Component: " + name + " of type: " +
			      _components[name]->getType() + " can't be modified");
  }

  AComponent *comp = _components[name];
  if (_components[name]->getType() == CONST::INPUT) {
    Input *input = static_cast<Input*>(comp);
    input->setValue(ComponentFactory::getTristate(value));
  } else {
    Clock *clock = static_cast<Clock*>(comp);
    clock->setValue(ComponentFactory::getTristate(value));
  }
}

void nts::Circuit::addComponent(std::string const& name, AComponent *comp) {
  if (_components.count(name) > 0) {
    throw ComponentExistException("Component already exist: " + name);
  }

  _components[name] = comp;
}

void nts::Circuit::setLink(std::string const& name1, size_t pin1,
			   std::string const& name2, size_t pin2) {
  if (_components.count(name1) == 0) {
    throw ComponentNotFoundException("Component not found: " + name1);
  } else if (_components.count(name2) == 0) {
    throw ComponentNotFoundException("Component not found: " + name2);
  }

  IComponent *comp1 = _components[name1];
  IComponent *comp2 = _components[name2];

  comp1->SetLink(pin1, *comp2, pin2);
}

void nts::Circuit::outputDisplay() {
  for (auto const& pair : _components) {
    if (pair.second->getType() == CONST::OUTPUT) {
      Output *output = static_cast<Output*>(pair.second);
      std::cout << pair.first << "=" << output->getValue() << std::endl;
    }
  }
}

void nts::Circuit::simulate() {
  for (auto const& pair : _components) {
    if (pair.second->getType() == CONST::OUTPUT) {
      (static_cast<Output *>(pair.second))->Compute();
    }
  }
  clockInverse();
}

void nts::Circuit::clockInverse() {
  for (auto const& pair : _components) {
    if (pair.second->getType() == CONST::CLOCK) {
      (static_cast<Clock*>(pair.second))->inverted();
    }
  }
}

void nts::Circuit::dump() {
  for (auto const& pair : _components) {
    std::cout << pair.second->getType() << ": " << pair.first << std::endl;
    pair.second->Dump();
  }
}

void nts::Circuit::printComp() const {
  for (auto const& pair : _components) {
    std::cout << pair.first << ": " << pair.second->getType() << std::endl;
  }
}

void nts::Circuit::checkLinks() const {
  for (auto const& pair : _components) {

    if (pair.second->getType() == CONST::INPUT) {
      Input *input = static_cast<Input *>(pair.second);

      if (input->getValue() == Tristate::UNDEFINED) {
  	throw UninitializeCompException("Component Error: input '" +
					pair.first + "' not initialized");
      }
    } else if (pair.second->getType() == CONST::CLOCK) {
      Clock *clock = static_cast<Clock *>(pair.second);

      if (clock->getValue() == Tristate::UNDEFINED) {
  	throw UninitializeCompException("Component Error: clock '" +
					pair.first + "' not initialized");
      }
    }
  }
}
