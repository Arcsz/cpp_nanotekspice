//
// Output.cpp for Output in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sun Feb 12 16:58:53 2017 Riamon Vincent
//

#include "components/Output.hpp"

nts::Output::Output(Tristate val) : AComponent("Output", val, 1){
  _val = nts::Tristate::UNDEFINED;
}

nts::Output::~Output() {
}

nts::Tristate nts::Output::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin == 0) {
    throw PinException(pinError("Output", this_pin));
  }

  if (!_pins[this_pin]) {
    throw OutputException("Output is not linked to anything");
  }

  _val = _pins[this_pin].compute();
  return _val;
}

nts::Tristate nts::Output::getValue(void) const {
  return _val;
}

void nts::Output::setValue(nts::Tristate value) {
  _val = value;
}
