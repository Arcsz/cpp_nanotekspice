//
// AComponent.cpp for  in /home/zeng_d/rendu/C++/cpp_nanotekspice
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb 11 18:32:28 2017 David Zeng
// Last update Sun Feb 12 13:56:07 2017 Riamon Vincent
//

#include "AComponent.hpp"

nts::Link::Link(AComponent *comp, size_t otherPin)
  : comp(comp), pin(otherPin) {
}

nts::Link::operator bool() const {
  return comp;
}

bool nts::Link::operator!() const {
  return !comp;
}

nts::Tristate nts::Link::compute() const {
  return comp->Compute(pin);
}

nts::AComponent::AComponent(std::string const& type, Tristate val, size_t maxPin)
  : _type(type), _val(val), _maxPin(maxPin) {
  // initialize pins
  for (size_t i = 1; i <= maxPin; ++i) {
    _pins[i];
  }
}

nts::AComponent::~AComponent() {

}

void nts::AComponent::SetLink(size_t this_pin, IComponent& comp, size_t target_pin) {
  AComponent& other = static_cast<AComponent&>(comp);

  // check pin validity
  if (this_pin > _maxPin || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  } else if (target_pin > other._maxPin || target_pin == 0) {
    throw PinException(pinError(other._type, target_pin));
  }

  // check if links already exist
  if (_pins[this_pin]) {
    throw LinkExistException(_type + ": Pin " + std::to_string(this_pin) +
			     " is already linked");
  } else if (other._pins[target_pin]) {
    throw LinkExistException(other._type + ": Pin " + std::to_string(target_pin) +
			     " is already linked");
  }

  _pins[this_pin] = {&other, target_pin};
  other._pins[target_pin] = {this, this_pin};
}

void nts::AComponent::Dump(void) const {
  for (size_t i = 1;  i <= _maxPin; ++i) {
    // if it's a component, not a gate
    if (_maxPin == 1) {
      std::cout << "\tvalue = " << _val << std::endl;
    }

    std::cout << "\tpin " << i << " = ";

    if (_pins.at(i)) {
      if (_maxPin == 1) {
	std::cout << "Linked" << std::endl;
      } else {
	std::cout << _pins.at(i).compute() << std::endl;
      }
    } else {
      std::cout << "NULL" << std::endl;
    }
  }
}

std::string const& nts::AComponent::getType() const {
  return _type;
}
