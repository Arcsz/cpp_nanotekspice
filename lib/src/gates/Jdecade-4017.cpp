//
// Jdecade-4017.cpp for Jdecade-4017 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Fri Feb 17 16:50:28 2017 Riamon Vincent
//

#include "gates/Jdecade-4017.hpp"

nts::Jdecade4017::Jdecade4017(Tristate val)
  : AComponent(CONST::C4017, val, 16), _newCycle(true), _cp0(14),
    _cp1(13), _reset(15), _current(Q0), _def(false) {
  _outputs = std::map<size_t, Tristate&>{
    {1,  _states[Q5]},
    {2,  _states[Q1]},
    {3,  _states[Q0]},
    {4,  _states[Q2]},
    {5,  _states[Q6]},
    {6,  _states[Q7]},
    {7,  _states[Q3]},
    {9,  _states[Q8]},
    {10, _states[Q4]},
    {11, _states[Q9]},
    {12, _states[QN]},
  };

  resetStates();
}

nts::Jdecade4017::~Jdecade4017() {
}

void nts::Jdecade4017::resetStates() {
  _states[Q0] = Tristate::TRUE;
  _states[Q1] = Tristate::FALSE;
  _states[Q2] = Tristate::FALSE;
  _states[Q3] = Tristate::FALSE;
  _states[Q4] = Tristate::FALSE;
  _states[Q5] = Tristate::FALSE;
  _states[Q6] = Tristate::FALSE;
  _states[Q7] = Tristate::FALSE;
  _states[Q8] = Tristate::FALSE;
  _states[Q9] = Tristate::FALSE;
  _states[QN] = Tristate::TRUE;
}

static int isInput(size_t pin) {
  switch (pin) {
  // INPUT
  case 13 ... 15:
    return 1;

  // OUTPUT
  case 1 ... 7:
  case 9 ... 12:
    return 0;

  // DEFAULT
  default:
    return -1;
  };
}

nts::Tristate nts::Jdecade4017::Compute(size_t this_pin) {
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

nts::Tristate nts::Jdecade4017::calcInput(size_t this_pin) {
  if (!_pins[this_pin]) {
    return Tristate::UNDEFINED;
  }

  if (_pins[this_pin].comp->getType() == CONST::OUTPUT) {
    throw OutputException("Can't use output as an input");
  }

  return _pins[this_pin].compute();
}

static nts::Tristate computePin(nts::Link& link) {
  if (link) {
    return link.compute();
  }

  return nts::Tristate::UNDEFINED;
}

void nts::Jdecade4017::computeOutputs() {
  _newCycle = false;
  _states[_current] = Tristate::FALSE;
  if (++_current > Q9) {
    _current = Q0;
  }
  _states[_current] = Tristate::TRUE;
  _states[QN] = static_cast<Tristate>(_current < Q5);
}

nts::Tristate nts::Jdecade4017::calcOutput(size_t this_pin) {
  Tristate reset = computePin(_pins[_reset]);
  Tristate cp0 = computePin(_pins[_cp0]);
  Tristate cp1 = computePin(_pins[_cp1]);

  if (this_pin > _maxPin || this_pin == 0 || reset == Tristate::UNDEFINED ||
      (cp0 == Tristate::UNDEFINED && cp1 == Tristate::UNDEFINED) ||
      (reset == Tristate::FALSE && !_def)) {
    return Tristate::UNDEFINED;
  }

  _def = true;

  if (reset == Tristate::TRUE) {
    _current = Q0;
    _newCycle = true;
    resetStates();
    return Tristate::FALSE;
  }

  if (((cp0 == Tristate::TRUE && cp1 != Tristate::TRUE) ||
      (cp1 == Tristate::FALSE && cp0 != Tristate::FALSE)) && _newCycle) {
    computeOutputs();
  } else if (!((cp0 == Tristate::TRUE && cp1 != Tristate::TRUE) ||
	       (cp1 == Tristate::FALSE && cp0 != Tristate::FALSE))) {
    _newCycle = true;
  }

  return _outputs.at(this_pin);
}
