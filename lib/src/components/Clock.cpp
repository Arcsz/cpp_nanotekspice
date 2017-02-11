//
// Clock.cpp for Clock in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 15:08:17 2017 Riamon Vincent
//

#include "components/Clock.hpp"

nts::Clock::Clock(Tristate val) : AComponent("Clock", val, 1) {
}

nts::Clock::~Clock() {
}

nts::Tristate nts::Clock::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin == 0) {
    throw PinException(pinError("Clock", this_pin));
  }

  return _val;
}

void nts::Clock::inverted(void) {
  if (_val == Tristate::UNDEFINED) {
    return;
  }

  _val = (_val == Tristate::TRUE) ? Tristate::FALSE : Tristate::TRUE;
}

nts::Tristate nts::Clock::getValue(void) const {
  return _val;
}

void nts::Clock::setValue(Tristate value) {
  if (value == Tristate::UNDEFINED) {
    throw InputException("Error Clock: value must be 0 or 1");
  }

  _val = value;
}
