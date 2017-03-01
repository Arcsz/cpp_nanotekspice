//
// decoder-4514.cpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Wed Mar  1 18:16:15 2017 Riamon Vincent
//

#include "gates/decoder-4514.hpp"

nts::decoder4514::decoder4514(Tristate val) : AComponent(CONST::C4514, val, 24) {
  _outputs[11] = Tristate::UNDEFINED;
  _outputs[9] = Tristate::UNDEFINED;
  _outputs[10] = Tristate::UNDEFINED;
  _outputs[8] = Tristate::UNDEFINED;
  _outputs[7] = Tristate::UNDEFINED;
  _outputs[6] = Tristate::UNDEFINED;
  _outputs[5] = Tristate::UNDEFINED;
  _outputs[4] = Tristate::UNDEFINED;
  _outputs[18] = Tristate::UNDEFINED;
  _outputs[17] = Tristate::UNDEFINED;
  _outputs[20] = Tristate::UNDEFINED;
  _outputs[19] = Tristate::UNDEFINED;
  _outputs[14] = Tristate::UNDEFINED;
  _outputs[13] = Tristate::UNDEFINED;
  _outputs[16] = Tristate::UNDEFINED;
  _outputs[15] = Tristate::UNDEFINED;
}

nts::decoder4514::~decoder4514() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 3 || pin == 21 || pin == 22) {
    return 1;
  } else if (pin == 11 || pin == 9 || pin == 10 || pin == 8 ||
	     pin == 7 || pin == 6 || pin == 5 || pin == 4 ||
	     pin == 18 || pin == 17 || pin == 20 || pin == 19 ||
	     pin == 14 || pin == 13 || pin == 16 || pin == 15 || pin == 23) {
    return 0;
  }
  return -1;
}

void nts::decoder4514::computeS0() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[11] = Tristate::TRUE;
  else
    _outputs[11] = Tristate::FALSE;
}

void nts::decoder4514::computeS1() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[9] = Tristate::TRUE;
  else
    _outputs[9] = Tristate::FALSE;
}

void nts::decoder4514::computeS2() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[10] = Tristate::TRUE;
  else
    _outputs[10] = Tristate::FALSE;
}

void nts::decoder4514::computeS3() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[8] = Tristate::TRUE;
  else
    _outputs[8] = Tristate::FALSE;
}

void nts::decoder4514::computeS4() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[7] = Tristate::TRUE;
  else
    _outputs[7] = Tristate::FALSE;

}

void nts::decoder4514::computeS5() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[6] = Tristate::TRUE;
  else
    _outputs[6] = Tristate::FALSE;
}

void nts::decoder4514::computeS6() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[5] = Tristate::TRUE;
  else
    _outputs[5] = Tristate::FALSE;
}

void nts::decoder4514::computeS7() {
  if (_pins[2].compute() == Tristate::FALSE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[4] = Tristate::TRUE;
  else
    _outputs[4] = Tristate::FALSE;
}

void nts::decoder4514::computeS8() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[18] = Tristate::TRUE;
  else
    _outputs[18] = Tristate::FALSE;
}

void nts::decoder4514::computeS9() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[17] = Tristate::TRUE;
  else
    _outputs[17] = Tristate::FALSE;
}

void nts::decoder4514::computeS10() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[20] = Tristate::TRUE;
  else
    _outputs[20] = Tristate::FALSE;
}

void nts::decoder4514::computeS11() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::FALSE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[19] = Tristate::TRUE;
  else
    _outputs[19] = Tristate::FALSE;
}

void nts::decoder4514::computeS12() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[14] = Tristate::TRUE;
  else
    _outputs[14] = Tristate::FALSE;
}

void nts::decoder4514::computeS13() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::FALSE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[13] = Tristate::TRUE;
  else
    _outputs[13] = Tristate::FALSE;
}

void nts::decoder4514::computeS14() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::FALSE)
    _outputs[16] = Tristate::TRUE;
  else
    _outputs[16] = Tristate::FALSE;
}

void nts::decoder4514::computeS15() {
  if (_pins[2].compute() == Tristate::TRUE &&
      _pins[3].compute() == Tristate::TRUE &&
      _pins[21].compute() == Tristate::TRUE &&
      _pins[22].compute() == Tristate::TRUE)
    _outputs[15] = Tristate::TRUE;
  else
    _outputs[15] = Tristate::FALSE;
}

void nts::decoder4514::setAll(Tristate state) {
  for (int i = 0; i <= 16; i++) {
    if (!isInput(i))
      _outputs[i] = state;
  }
}

nts::Tristate nts::decoder4514::Compute(size_t this_pin) {
  if (this_pin == 12 || this_pin > 23 || this_pin == 0) {
    throw PinException(pinError(_type, this_pin));
  }
  if (isInput(this_pin) == 1) {
    return this->calcInput(this_pin);
  } else if (isInput(this_pin) == 0) {
    return this->calcOutput(this_pin);
  }
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
  if (this_pin == 12 || this_pin > 23 || this_pin == 0) {
    return Tristate::UNDEFINED;
  }
  std::map<size_t, nts::decoder4514::computeS> _outFunc;

  _outFunc[11] = &nts::decoder4514::computeS0;
  _outFunc[9] = &nts::decoder4514::computeS1;
  _outFunc[10] = &nts::decoder4514::computeS2;
  _outFunc[8] = &nts::decoder4514::computeS3;
  _outFunc[7] = &nts::decoder4514::computeS4;
  _outFunc[6] = &nts::decoder4514::computeS5;
  _outFunc[5] = &nts::decoder4514::computeS6;
  _outFunc[4] = &nts::decoder4514::computeS7;
  _outFunc[18] = &nts::decoder4514::computeS8;
  _outFunc[17] = &nts::decoder4514::computeS9;
  _outFunc[20] = &nts::decoder4514::computeS10;
  _outFunc[19] = &nts::decoder4514::computeS11;
  _outFunc[14] = &nts::decoder4514::computeS12;
  _outFunc[13] = &nts::decoder4514::computeS13;
  _outFunc[16] = &nts::decoder4514::computeS14;
  _outFunc[15] = &nts::decoder4514::computeS15;

  if (_pins[1].compute() == 0) {
    setAll(Tristate::UNDEFINED);
    return Tristate::UNDEFINED;
  }
  else if (_pins[23].compute() == 1) {
    setAll(Tristate::FALSE);
    return Tristate::FALSE;
  }
  else
    (this->*_outFunc[this_pin])();
  return _outputs.at(this_pin);
}
