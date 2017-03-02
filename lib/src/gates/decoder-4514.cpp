//
// decoder-4514.cpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Thu Mar  2 18:26:00 2017 Riamon Vincent
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

void nts::decoder4514::computeS(Tristate a0, Tristate a1,
				Tristate a2, Tristate a3, size_t pin) {
  if (_pins[2].compute() == a0 && _pins[3].compute() == a1
      && _pins[21].compute() == a2 && _pins[22].compute() == a3)
    _outputs[pin] = Tristate::TRUE;
  else
    _outputs[pin] = Tristate::FALSE;
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
  std::map<size_t, std::function<void() > > _outFunc;

  _outFunc[11] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::FALSE, Tristate::FALSE, Tristate::FALSE, 11);
  };
  _outFunc[9] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::FALSE,  Tristate::FALSE, Tristate::TRUE, 9);
  };
  _outFunc[10] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::FALSE, Tristate::TRUE, Tristate::FALSE, 10);
  };
  _outFunc[8] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::FALSE, Tristate::TRUE, Tristate::TRUE, 8);
  };
  _outFunc[7] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::TRUE, Tristate::FALSE, Tristate::FALSE, 7);
  };
  _outFunc[6] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::TRUE, Tristate::FALSE, Tristate::TRUE, 6);
  };
  _outFunc[5] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::TRUE, Tristate::TRUE, Tristate::FALSE, 5);
  };
  _outFunc[4] = [this] () {
    this->computeS(Tristate::FALSE, Tristate::TRUE, Tristate::TRUE, Tristate::TRUE, 4);
  };
  _outFunc[18] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::FALSE, Tristate::FALSE, Tristate::FALSE, 18);
  };
  _outFunc[17] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::FALSE, Tristate::FALSE, Tristate::TRUE, 17);
  };
  _outFunc[20] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::FALSE, Tristate::TRUE, Tristate::FALSE, 20);
  };
  _outFunc[19] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::FALSE, Tristate::TRUE, Tristate::TRUE, 19);
  };
  _outFunc[14] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::TRUE, Tristate::FALSE, Tristate::FALSE, 14);
  };
  _outFunc[13] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::TRUE, Tristate::FALSE, Tristate::TRUE, 13);
  };
  _outFunc[16] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::TRUE, Tristate::TRUE, Tristate::FALSE, 16);
  };
  _outFunc[15] = [this] () {
    this->computeS(Tristate::TRUE, Tristate::TRUE, Tristate::TRUE, Tristate::TRUE, 15);
  };

  if (_pins[1].compute() == 0) {
    setAll(Tristate::UNDEFINED);
    return Tristate::UNDEFINED;
  }
  else if (_pins[23].compute() == 1) {
    setAll(Tristate::FALSE);
    return Tristate::FALSE;
  }
  else {
    _outFunc[this_pin]();
  }
  return _outputs.at(this_pin);
}
