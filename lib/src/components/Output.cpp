//
// Output.cpp for Output in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Sat Feb 11 15:08:50 2017 Riamon Vincent
//

#include "components/Output.hpp"

nts::Output::Output(Tristate val) : AComponent("Output", val, 1){
  _val = nts::Tristate::UNDEFINED;
}

nts::Output::~Output() {
}

nts::Tristate nts::Output::Compute(size_t this_pin) {
  if (this_pin > 1 || this_pin == 0) {
    throw nts::PinException(nts::pinError("Output", this_pin));
  }

  if (!_pins[this_pin]) {
    throw nts::OutputException("Output is not linked");
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
