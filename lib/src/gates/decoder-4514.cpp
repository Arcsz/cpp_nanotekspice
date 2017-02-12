//
// decoder-4514.cpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sun Feb 12 14:03:03 2017 Riamon Vincent
//

#include "gates/decoder-4514.hpp"

nts::decoder4514::decoder4514(Tristate val) : AComponent(CONST::C4514, val, 14) {
}

nts::decoder4514::~decoder4514() {
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

nts::Tristate nts::decoder4514::nand_gate(size_t first_pin, size_t second_pin) const {
  return static_cast<Tristate>(!(first_pin && second_pin));
}

nts::Tristate nts::decoder4514::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }
  if (isInput(this_pin))
    return Tristate::UNDEFINED;
  return Tristate::UNDEFINED;
}

nts::Tristate nts::decoder4514::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::decoder4514::calcOutput(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t firstPin = _outputs[this_pin].first;
  size_t secondPin = _outputs[this_pin].second;

  if (!_pins[firstPin] || !_pins[secondPin]) {
    return Tristate::UNDEFINED;
  }

  return nand_gate(_pins[firstPin].compute(), _pins[secondPin].compute());
}
