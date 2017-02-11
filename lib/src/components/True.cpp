//
// True.cpp for True in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 15:08:38 2017 Riamon Vincent
//

#include "components/True.hpp"

nts::True::True(Tristate val) : AComponent("True", val, 1) {
  _val = Tristate::TRUE;
}

nts::True::~True() {
}

nts::Tristate nts::True::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin <= 0) {
    throw PinException(pinError("True", this_pin));
  }

  return _val;
}

nts::Tristate nts::True::getValue(void) const {
  return _val;
}
