//
// counter-4040.cpp for counter-4040 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sun Feb 12 14:03:08 2017 Riamon Vincent
//

#include "gates/counter-4040.hpp"

nts::counter4040::counter4040(Tristate val)
  : AComponent(CONST::C4040, val, 16), _clock(10), _reset(11), _def(false),
    _count(0), _oldClock(Tristate::UNDEFINED) {
  _outputs = std::map<size_t, Tristate&>{
    {1, _counter.q12},
    {2, _counter.q6},
    {3, _counter.q5},
    {4, _counter.q7},
    {5, _counter.q4},
    {6, _counter.q3},
    {7, _counter.q2},
    {9, _counter.q1},
    {12, _counter.q9},
    {13, _counter.q8},
    {14, _counter.q10},
    {15, _counter.q11}
  };

  resetCounter();

  _count = 0;
}

nts::counter4040::~counter4040() {
}

void nts::counter4040::resetCounter() {
  _counter = {
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE,
    Tristate::FALSE
  };
  _count = 0;
}

static int isInput(size_t pin) {
  switch (pin) {
  // INPUT
  case 10 ... 11:
    return 1;

  // OUTPUT
  case 1 ... 7:
  case 12 ... 15:
  case 9:
    return 0;

  // DEFAULT
  default:
    return -1;
  };
}

nts::Tristate nts::counter4040::Compute(size_t this_pin) {
  if (this_pin > _maxPin || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }

  if (isInput(this_pin) == 1) {
    return this->calcInput(this_pin);
  } else if (isInput(this_pin) == 0) {
    return this->calcOutput(this_pin);
  }

  return Tristate::UNDEFINED;
}

nts::Tristate nts::counter4040::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

void nts::counter4040::updateCounter() {
  _counter = {
    static_cast<Tristate>(!!(_count & (1u << 0))),
    static_cast<Tristate>(!!(_count & (1u << 1))),
    static_cast<Tristate>(!!(_count & (1u << 2))),
    static_cast<Tristate>(!!(_count & (1u << 3))),
    static_cast<Tristate>(!!(_count & (1u << 4))),
    static_cast<Tristate>(!!(_count & (1u << 5))),
    static_cast<Tristate>(!!(_count & (1u << 6))),
    static_cast<Tristate>(!!(_count & (1u << 7))),
    static_cast<Tristate>(!!(_count & (1u << 8))),
    static_cast<Tristate>(!!(_count & (1u << 9))),
    static_cast<Tristate>(!!(_count & (1u << 10))),
    static_cast<Tristate>(!!(_count & (1u << 11)))
  };
}

nts::Tristate nts::counter4040::calcOutput(size_t this_pin) {
  Tristate clock = _pins[_clock].compute();
  Tristate reset = _pins[_reset].compute();

  if (this_pin > _maxPin || this_pin == 0
      || ((reset == Tristate::FALSE || reset == Tristate::UNDEFINED) && !_def)) {
    return Tristate::UNDEFINED;
  }

  _def = true;

  if (reset == Tristate::TRUE) {
    resetCounter();
    return Tristate::FALSE;
  }

  if (clock == Tristate::FALSE && clock != _oldClock) {
    ++_count;
    updateCounter();
    if (_count & (1u << 12)) {
      _count = 0;
    }
  }

  _oldClock = clock;

  return _outputs.at(this_pin);
}
