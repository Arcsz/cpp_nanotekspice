//
// False.cpp for False in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 15:08:35 2017 Riamon Vincent
//

#include "components/False.hpp"

nts::False::False(Tristate val) : AComponent("False", val, 1) {
  _val = nts::Tristate::FALSE;
}

nts::False::~False() {
}

nts::Tristate nts::False::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw PinException(pinError("False", this_pin));
  }

  return _val;
}

nts::Tristate nts::False::getValue(void) const {
  return _val;
}
