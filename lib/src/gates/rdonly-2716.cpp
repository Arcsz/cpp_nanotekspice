//
// rdonly-2716.cpp for rdonly-2716 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 23:35:10 2017 Riamon Vincent
//

#include "gates/rdonly-2716.hpp"
#include "Output.hpp"

nts::rdonly2716::rdonly2716(Tristate val) : AComponent("2716", val, 14) {
}

nts::rdonly2716::~rdonly2716() {
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

nts::Tristate nts::rdonly2716::nand_gate(size_t first_pin, size_t second_pin) const {
  return static_cast<Tristate>(!(first_pin && second_pin));
}

nts::Tristate nts::rdonly2716::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError("C2716", this_pin));
  }
  if (isInput(this_pin))
    return Tristate::UNDEFINED;
  return Tristate::UNDEFINED;
}

nts::Tristate nts::rdonly2716::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  Output *out = new Output(nts::Tristate::UNDEFINED);
  if (out)
    throw OutputException("Can't use output as an input");

  return _pins[this_pin].compute();
}

nts::Tristate nts::rdonly2716::calcOutput(size_t this_pin) {
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
