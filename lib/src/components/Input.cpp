//
// Input.cpp for Input in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 17:00:12 2017 Riamon Vincent
//

#include "components/Input.hpp"

nts::Input::Input(Tristate val) : AComponent(CONST::INPUT, val, 1) {
}

nts::Input::~Input() {
}

nts::Tristate nts::Input::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw PinException(pinError(_type, this_pin));
  }

  return _val;
}
nts::Tristate nts::Input::getValue(void) const {
  return _val;
}

void nts::Input::setValue(Tristate value) {
  if (value == Tristate::UNDEFINED) {
    throw InputException("Error Input: value must be 0 or 1");
  }

  _val = value;
}
