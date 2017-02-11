//
// INVERSE-4069.cpp for INVERSE-4069 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 15:15:42 2017 Riamon Vincent
//

#include "gates/INVERSE-4069.hpp"

nts::INVERSE4069::INVERSE4069(Tristate val) : AComponent("4069", val, 14) {
  _outputs[2] = 1;
  _outputs[4] = 3;
  _outputs[6] = 5;
  _outputs[8] = 9;
  _outputs[10] = 11;
  _outputs[12] = 13;
}

nts::INVERSE4069::~INVERSE4069() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13) {
    return 1;
  } else if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12) {
    return 0;
  }
  return -1;
}

nts::Tristate nts::INVERSE4069::not_gate(size_t first_pin) const {
  return static_cast<Tristate>(!first_pin);
}

nts::Tristate nts::INVERSE4069::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError("C4069", this_pin));
  }

  if (isInput(this_pin)) {
    return this->calcInput(this_pin);
  } else if (!isInput(this_pin)) {
    return this->calcOutput(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::INVERSE4069::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1]) {
    return Tristate::UNDEFINED;
  }

  if (!isInput(this_pin)) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::INVERSE4069::calcOutput(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t firstPin = _outputs[this_pin];

  if (!_pins[firstPin]) {
    return Tristate::UNDEFINED;
  }

  return not_gate(_pins[firstPin].compute());
}
