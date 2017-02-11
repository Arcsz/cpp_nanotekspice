//
// register-4094.cpp for register-4094 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 15:14:04 2017 Riamon Vincent
//

#include "gates/register-4094.hpp"

nts::register4094::register4094(Tristate val) : AComponent("4094", val, 14) {
}

nts::register4094::~register4094() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
      pin == 8 || pin == 9 || pin == 12 || pin == 13) {
    return 1;
  } else if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
    return 0;
  }
  return -1;
}

nts::Tristate nts::register4094::nand_gate(size_t first_pin, size_t second_pin) const {
  return static_cast<Tristate>(!(first_pin && second_pin));
}

nts::Tristate nts::register4094::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError("C4094", this_pin));
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::register4094::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (!isInput(this_pin)) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::register4094::calcOutput(size_t this_pin) {
  if (this_pin > 14  || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t firstPin = _outputs[this_pin].first;
  size_t secondPin = _outputs[this_pin].second;

  if (!_pins[firstPin] || !_pins[secondPin]) {
    return Tristate::UNDEFINED;
  }

  return nand_gate(_pins[firstPin].compute(), _pins[secondPin].compute());
}
