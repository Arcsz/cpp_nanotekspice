//
// adder-4008.cpp for adder-4008 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Sat Feb 11 14:57:01 2017 Riamon Vincent
//

#include "adder-4008.hpp"

nts::adder4008::adder4008(__attribute__((unused))nts::Tristate val) {
  for (int i = 0; i < 16; i++)
    _pins[i] = NULL;
  _outputs[10] = std::make_pair(6, 7);
  _outputs[11] = std::make_pair(4, 5);
  _outputs[12] = std::make_pair(2, 3);
  _outputs[13] = std::make_pair(1, 15);
}

nts::adder4008::~adder4008() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 3 || pin == 4 ||
      pin == 5 || pin == 6 || pin == 7 || pin == 9 || pin == 15)
    return (1);
  else if (pin == 12 || pin == 13 || pin == 10 || pin == 11)
    return (0);
  else if (pin == 14)
    return (2);
  return (-1);
}

void nts::adder4008::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 16) {
    throw nts::PinException(nts::pinError("C4008", this_pin));
  } else if (_pins[this_pin - 1] == NULL) {
    _pins[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    try {
      comp.SetLink(target_pin, *this, this_pin);
    }
    catch (nts::ChipsetException const& err) {
      throw err;
    }
  }
}

nts::Tristate nts::adder4008::add_gate(size_t first_pin, size_t second_pin,
				  nts::Tristate& carry) const {
  char res = ((char)first_pin) + ((char)second_pin) + ((char)carry);
  carry = static_cast<nts::Tristate>(res >> 1);
  return static_cast<nts::Tristate>(res & 1);
}

nts::Tristate nts::adder4008::Compute(size_t this_pin) {
  if (this_pin > 16) {
    throw nts::PinException(nts::pinError("C4008", this_pin));
  }
  if (isInput(this_pin))
    return (this->calcInput(this_pin));
  else if (!isInput(this_pin))
    return (this->calcOutput(this_pin));
  else if (isInput(this_pin) == 2)
    return (this->calcCarryOut(this_pin));
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::adder4008::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1])
    return nts::Tristate::UNDEFINED;
  if (!isInput(this_pin))
    throw nts::OutputException("Can't use output as an input");
  return _pins[this_pin - 1]->Compute(_links[this_pin - 1]);
}

nts::Tristate nts::adder4008::calcOutput(size_t this_pin) {
  size_t first_pin = 0;
  size_t second_pin = 0;
  unsigned int i = 9;
  nts::Tristate carry = nts::Tristate::FALSE;
  nts::Tristate res = nts::Tristate::UNDEFINED;

  if (this_pin >= 16)
    return (res);
  if (_pins[8])
    carry = _pins[8]->Compute(_links[8]);
  while (++i <= this_pin)
    {
      if (this_pin < 16)
	{
	  first_pin = _outputs[i].first;
	  second_pin = _outputs[i].second;
	  if (_pins[first_pin - 1] && _pins[second_pin - 1])
	    res = add_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
			   _pins[second_pin - 1]->Compute(_links[second_pin - 1]),
			   carry);
	}
    }
  return (res);
}

nts::Tristate nts::adder4008::calcCarryOut(size_t this_pin) {
  size_t first_pin = 0;
  size_t second_pin = 0;
  unsigned int i = 9;
  nts::Tristate carry = nts::Tristate::FALSE;

  if (_pins[8])
    carry = _pins[8]->Compute(_links[8]);
  while (++i < this_pin)
    {
      if (this_pin < 16)
	{
	  first_pin = _outputs[i].first;
	  second_pin = _outputs[i].second;
	  if (_pins[first_pin - 1] && _pins[second_pin - 1])
	    add_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
		     _pins[second_pin - 1]->Compute(_links[second_pin - 1]),
		     carry);
	}
    }
  return (carry);
}

void nts::adder4008::Dump(void) const {
  for (int i = 0;  i < 16; i++) {
    std::cout << "\tpin n°" << i + 1 << "= ";
    if (!_pins[i])
      std::cout << "NULL" << std::endl;
    else
      std::cout << _pins[i]->Compute(_links.at(i)) << std::endl;
  }
}
