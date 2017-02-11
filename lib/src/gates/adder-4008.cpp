//
// adder-4008.cpp for adder-4008 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 15:11:54 2017 Riamon Vincent
//

#include "gates/adder-4008.hpp"

nts::adder4008::adder4008(Tristate val) : AComponent("4008", val, 16) {
  _outputs[10] = {6, 7};
  _outputs[11] = {4, 5};
  _outputs[12] = {2, 3};
  _outputs[13] = {1, 15};
}

nts::adder4008::~adder4008() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 3 || pin == 4 ||
      pin == 5 || pin == 6 || pin == 7 || pin == 9 || pin == 15) {
    return 1;
  } else if (pin == 12 || pin == 13 || pin == 10 || pin == 11) {
    return 0;
  } else if (pin == 14) {
    return 2;
  }
  return -1;
}

nts::Tristate nts::adder4008::add_gate(size_t first_pin, size_t second_pin,
				       Tristate& carry) const {
  char res = ((char)first_pin) + ((char)second_pin) + ((char)carry);
  carry = static_cast<Tristate>(res >> 1);
  return static_cast<Tristate>(res & 1);
}

nts::Tristate nts::adder4008::Compute(size_t this_pin) {
  if (this_pin > 16 || this_pin == 0) {
    throw PinException(pinError("C4008", this_pin));
  }

  if (isInput(this_pin) == 1) {
    return this->calcInput(this_pin);
  } else if (!isInput(this_pin)) {
    return this->calcOutput(this_pin);
  } else if (isInput(this_pin) == 2) {
    return this->calcCarryOut(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::adder4008::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (!isInput(this_pin)) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::adder4008::calcOutput(size_t this_pin) {
  Tristate res = Tristate::UNDEFINED;
  if (this_pin >= 16) {
    return res;
  }

  Tristate carry = Tristate::FALSE;
  if (_pins[9]) {
    carry = _pins[9].compute();
  }

  for (size_t i = 10; i <= this_pin; ++i) {
    size_t firstPin = _outputs[i].first;
    size_t secondPin = _outputs[i].second;

    if (_pins[firstPin] && _pins[secondPin]) {
      res = add_gate(_pins[firstPin].compute(), _pins[secondPin].compute(), carry);
    }
  }

  return res;
}

nts::Tristate nts::adder4008::calcCarryOut(size_t this_pin) {
  Tristate carry = Tristate::FALSE;
  if (_pins[9]) {
    carry = _pins[9].compute();
  }

  if (this_pin >= 16) {
    return carry;
  }

  for (size_t i = 10; i < this_pin; ++i) {
    size_t first_pin = _outputs[i].first;
    size_t second_pin = _outputs[i].second;

    if (_pins[first_pin] && _pins[second_pin]) {
      add_gate(_pins[first_pin].compute(), _pins[second_pin].compute(), carry);
    }
  }

  return carry;
}
