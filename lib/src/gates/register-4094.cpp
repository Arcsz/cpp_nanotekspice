//
// register-4094.cpp for register-4094 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sun Feb 12 14:02:45 2017 Riamon Vincent
//

#include "gates/register-4094.hpp"

nts::register4094::register4094(Tristate val)
  : AComponent(CONST::C4094, val, 16), _clock(3), _data(2), _strobe(1), _oe(15) {
  _outputs = std::map<size_t, Tristate&>{
    {4, _states[Q1]},
    {5, _states[Q2]},
    {6, _states[Q3]},
    {7, _states[Q4]},
    {14, _states[Q5]},
    {13, _states[Q6]},
    {12, _states[Q7]},
    {11, _states[Q8]},
    {10, _qs2},
    {9, _qs1}
  };

  _states[Q1] = Tristate::UNDEFINED;
  _states[Q2] = Tristate::UNDEFINED;
  _states[Q3] = Tristate::UNDEFINED;
  _states[Q4] = Tristate::UNDEFINED;
  _states[Q5] = Tristate::UNDEFINED;
  _states[Q6] = Tristate::UNDEFINED;
  _states[Q7] = Tristate::UNDEFINED;
  _states[Q8] = Tristate::UNDEFINED;
  _qs2 = Tristate::UNDEFINED;
  _qs1 = Tristate::UNDEFINED;

  _oldClock = Tristate::UNDEFINED;
}

nts::register4094::~register4094() {
}

static int isInput(size_t pin) {
  switch (pin) {
  // INPUT
  case 1 ... 3:
  case 15:
    return 1;

  // OUTPUT
  case 4 ... 7:
  case 9 ... 14:
    return 0;

  // DEFAULT
  default:
    return -1;
  };
}

nts::Tristate nts::register4094::Compute(size_t this_pin) {
  if (this_pin > _maxPin || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }

  if (isInput(this_pin)) {
    return this->calcInput(this_pin);
  } else if (isInput(this_pin) == 0) {
    return this->calcOutput(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::register4094::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

void nts::register4094::shift(Tristate val) {
  Tristate old;
  for (int i = Q1; i < Q8 + 1; ++i) {
    old = _states[i];
    _states[i] = val;
    val = old;
  }
}

// TODO REFACTOR THIS FUNCTION
nts::Tristate nts::register4094::calcOutput(size_t this_pin) {
  Tristate clock = _pins[_clock].compute();
  Tristate data = _pins[_data].compute();
  Tristate strobe = _pins[_strobe].compute();
  Tristate oe = _pins[_oe].compute();

  if (this_pin > _maxPin  || this_pin == 0 || clock == Tristate::UNDEFINED ||
      oe == Tristate::UNDEFINED) {
    return Tristate::UNDEFINED;
  }

  if (oe == Tristate::FALSE) {
    if (this_pin == 10 || this_pin == 9) {
      if (clock == Tristate::TRUE) {
	_qs1 = _states[Q7]; // TODO CONFIRM FOLLOWUP
      } else {
	_qs2 = _states[Q7];
      }

      return _outputs.at(this_pin);
    }

    return Tristate::UNDEFINED;
  }

  if (strobe == Tristate::UNDEFINED) {
    return Tristate::UNDEFINED;
  }

  if (clock == Tristate::TRUE && strobe == Tristate::FALSE) {
    return _outputs.at(this_pin);
  }

  if (data == Tristate::UNDEFINED) {
    return Tristate::UNDEFINED;
  }

  if (clock == Tristate::FALSE) {
    if (this_pin == 10) {
      _qs2 = _states[Q7];
    }
    _oldClock = clock;
    return _outputs.at(this_pin);
  }

  if (strobe == Tristate::TRUE && clock != _oldClock) {
    _oldClock = clock;
    shift(data);
  }

  if (this_pin == 9) {
    _qs1 = _states[Q7];
  }

  return _outputs.at(this_pin);
}
