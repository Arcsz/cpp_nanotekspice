//
// AND-4081.cpp for AND-4081 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 15:15:59 2017 Riamon Vincent
//

#include "gates/AND-4081.hpp"

nts::AND4081::AND4081(Tristate val) : AComponent("4081", val, 14){
  _outputs[3] = std::make_pair(1, 2);
  _outputs[4] = std::make_pair(5, 6);
  _outputs[10] = std::make_pair(8, 9);
  _outputs[11] = std::make_pair(12, 13);
}

nts::AND4081::~AND4081() {
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

nts::Tristate nts::AND4081::and_gate(size_t first_pin, size_t second_pin) const {
  return static_cast<Tristate>(first_pin && second_pin);
}

nts::Tristate nts::AND4081::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError("C4081", this_pin));
  }

  if (isInput(this_pin)) {
    return this->calcInput(this_pin);
  } else if (!isInput(this_pin)) {
    return this->calcOutput(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::AND4081::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (isInput(this_pin) == 0) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::AND4081::calcOutput(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t firstPin = _outputs[this_pin].first;
  size_t secondPin = _outputs[this_pin].second;

  if (!_pins[firstPin] || !_pins[secondPin]) {
    return Tristate::UNDEFINED;
  }

  return and_gate(_pins[firstPin].compute(), _pins[secondPin].compute());
}
