//
// Input.cpp for Input in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 17:00:12 2017 Riamon Vincent
//

#include "Input.hpp"

nts::Input::Input(nts::Tristate val){
  _val = val;
  _pin[0] = NULL;
  _links[0] = 0;
}

nts::Input::~Input() {
}

nts::Tristate nts::Input::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw nts::PinException(nts::pinError("Input", this_pin));
  }
  return _val;
}

void nts::Input::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw nts::PinException(nts::pinError("Input", this_pin));
  } else if (_pin[this_pin - 1] == NULL) {
    _pin[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    try{
      comp.SetLink(target_pin, *this, this_pin);
    }
    catch(nts::ChipsetException const& err) {
      throw err;
    }
  }
}

void nts::Input::Dump(void) const {
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate nts::Input::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> nts::Input::getLinks(void) const {
  return _links;
}

void nts::Input::setValue(nts::Tristate value) {
  if (value == nts::Tristate::UNDEFINED)
    throw nts::InputException("Error Input: value must be 0 or 1");
  else
    _val = value;
}
