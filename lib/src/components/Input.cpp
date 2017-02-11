//
// Input.cpp for Input in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 15:08:00 2017 Riamon Vincent
//

#include "components/Input.hpp"

nts::Input::Input(Tristate val) : AComponent("Input", val, 1) {
}

nts::Input::~Input() {
}

nts::Tristate nts::Input::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw nts::PinException(nts::pinError("Input", this_pin));
  }
  return _val;
}
nts::Tristate nts::Input::getValue(void) const {
  return _val;
}

void nts::Input::setValue(nts::Tristate value) {
  if (value == nts::Tristate::UNDEFINED)
    throw nts::InputException("Error Input: value must be 0 or 1");
  else
    _val = value;
}
