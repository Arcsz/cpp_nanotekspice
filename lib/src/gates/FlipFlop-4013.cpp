//
// FLIPFLOP-4013.cpp for FLIPFLOP-4013 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Fri Feb 17 14:28:46 2017 Riamon Vincent
//

#include "gates/FlipFlop-4013.hpp"

nts::FLIPFLOP4013::FLIPFLOP4013(Tristate val) : AComponent(CONST::C4013, val, 14) {
  _outputs[1] = {.clock = 3, .reset = 4, .data = 5, .set = 6,
		 false, Tristate::FALSE};
  _outputs[2] = {.clock = 3, .reset = 4, .data = 5, .set = 6,
		 true, Tristate::FALSE};

  _outputs[13] = {.clock = 11, .reset = 10, .data = 9, .set = 8,
		  false, Tristate::FALSE};
  _outputs[12] = {.clock = 11, .reset = 10, .data = 9, .set = 8,
		  true, Tristate::FALSE};
}

nts::FLIPFLOP4013::~FLIPFLOP4013() {
}

static int isInput(size_t pin) {
  switch (pin) {
  // UNDEFINED
  case 7:
  case 14:
    return -1;

  // OUTPUT
  case 1 ... 2:
  case 12 ... 13:
    return 0;

  // INPUT
  default:
    return 1;
  }
}

nts::Tristate nts::FLIPFLOP4013::Compute(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }

  if (isInput(this_pin) == 1) {
    return this->calcInput(this_pin);
  } else if (isInput(this_pin) == 0) {
    return this->calcOutput(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::FLIPFLOP4013::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

nts::Tristate nts::FLIPFLOP4013::computeBarre(FlipFlop& output, Tristate state) {
  if (output.barre && state == Tristate::TRUE) {
    state = Tristate::FALSE;
  } else if (output.barre && state == Tristate::FALSE) {
    state = Tristate::TRUE;
  }

  output.oldValue = state;
  return state;
}

nts::Tristate nts::FLIPFLOP4013::computeDataInput(FlipFlop& output) {
  size_t clock = output.clock;
  if (!_pins[clock]) {
    return Tristate::UNDEFINED;
  }

  size_t clockVal = _pins[clock].compute();
  if (clockVal == Tristate::FALSE) {
    return output.oldValue;
  }

  size_t data = output.data;
  if (!_pins[data]) {
    return Tristate::UNDEFINED;
  }

  size_t dataVal = _pins[data].compute();
  if (dataVal == Tristate::TRUE) {
    return computeBarre(output, Tristate::TRUE);
  }
  if (dataVal == Tristate::FALSE) {
    return computeBarre(output, Tristate::FALSE);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::FLIPFLOP4013::calcOutput(size_t this_pin) {
  if (this_pin > 14 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }

  size_t reset = _outputs[this_pin].reset;
  size_t set = _outputs[this_pin].set;
  if (!_pins[reset] || !_pins[set]) {
    return Tristate::UNDEFINED;
  }

  size_t resetVal = _pins[reset].compute();
  size_t setVal = _pins[set].compute();
  if (resetVal == Tristate::TRUE && setVal == Tristate::TRUE) {
    _outputs[this_pin].oldValue = Tristate::TRUE;
    return Tristate::TRUE;
  }
  if (resetVal == Tristate::FALSE && setVal == Tristate::TRUE) {
    return computeBarre(_outputs[this_pin], Tristate::TRUE);
  }
  if (resetVal == Tristate::TRUE && setVal == Tristate::FALSE) {
    return computeBarre(_outputs[this_pin], Tristate::FALSE);
  }

  return computeDataInput(_outputs[this_pin]);
}
