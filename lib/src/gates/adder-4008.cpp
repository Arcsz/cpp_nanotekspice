//
// adder-4008.cpp for adder-4008 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Thu Feb  2 19:33:31 2017 Riamon Vincent
//

#include "adder-4008.hpp"

adder4008::adder4008() {
  for (int i = 0; i <= 16; i++)
    _pins[i] = NULL;
  _outputs[10] = std::make_pair(6, 7);
  _outputs[11] = std::make_pair(4, 5);
  _outputs[12] = std::make_pair(2, 3);
  _outputs[13] = std::make_pair(1, 15);
}

adder4008::~adder4008() {
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

void adder4008::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 16) {
    std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw
    return ;
  } else if (_pins[this_pin - 1] == NULL) {
    _pins[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    comp.SetLink(target_pin, *this, this_pin);
  }
}

nts::Tristate adder4008::add_gate(size_t first_pin, size_t second_pin,
				  nts::Tristate& carry) const {
  char res = (char)first_pin + (char)second_pin + (char)carry;
  carry = static_cast<nts::Tristate>(res >> 1);
  return static_cast<nts::Tristate>(res & 1);
}

nts::Tristate adder4008::Compute(size_t this_pin) {
  if (this_pin >= 16) {
    std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw without ret
    return nts::Tristate::UNDEFINED;
  }
  if (isInput(this_pin))
    return (this->calcInput(this_pin));
  else if (!isInput(this_pin))
    return (this->calcOutput(this_pin));
  else if (isInput(this_pin) == 2)
    return (this->calcCarryOut(this_pin));
  return (nts::Tristate::UNDEFINED); //TODO 14 et 7 considered UNDEFINED ?
}

nts::Tristate adder4008::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1])
    return nts::Tristate::UNDEFINED;
  if (!isInput(this_pin)) {
    std::cerr << "Can't use output as an input" << std::endl; //TODO throw without ret
    return nts::Tristate::UNDEFINED;
  }
  return _pins[this_pin - 1]->Compute(_links[this_pin - 1]);
}

nts::Tristate adder4008::calcOutput(size_t this_pin) {
  size_t first_pin = 0;
  size_t second_pin = 0;
  unsigned int i = 9;
  nts::Tristate carry = nts::Tristate::UNDEFINED;;
  nts::Tristate res = nts::Tristate::UNDEFINED;

  if (this_pin >= 16)
    return (res);
  if (_pins[8])
    carry = _pins[8]->Compute(_links[8]);
  while (++i < this_pin)
    {
      if (this_pin < 16)
	{
	  first_pin = _outputs[this_pin].first;
	  second_pin = _outputs[this_pin].second;
	  if (_pins[first_pin - 1] && _pins[second_pin - 1])
	    res = add_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
			   _pins[second_pin - 1]->Compute(_links[second_pin - 1]),
			   carry);
	}
    }
  return (res);
}

nts::Tristate adder4008::calcCarryOut(size_t this_pin) {
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
	  first_pin = _outputs[this_pin].first;
	  second_pin = _outputs[this_pin].second;
	  if (_pins[first_pin - 1] && _pins[second_pin - 1])
	    add_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
		     _pins[second_pin - 1]->Compute(_links[second_pin - 1]),
		     carry);
	}
    }
  return (carry);
}

void adder4008::Dump(void) const {
  std::cout << "4008 - adder gate:" << std::endl;
  for (int i = 0;  i < 16; i++) {
      std::cout << "\tpin n°" << i + 1 << "= ";
      if (!_pins[i])
      	std::cout << "NULL" << std::endl;
      else
      	std::cout << _pins[i]->Compute(_links.at(i)) << std::endl;
      //std::cout << ((!_pins[i]) ? "NULL" : _pins[i]->Compute(_links.at(i))) << std::endl;
    }
}
