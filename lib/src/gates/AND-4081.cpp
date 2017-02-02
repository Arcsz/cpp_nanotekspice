//
// AND-4081.cpp for AND-4081 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Thu Feb  2 09:44:01 2017 Riamon Vincent
//

#include "AND-4081.hpp"

AND4081::AND4081() {
  for (int i = 0; i < 14; i++)
    _pins[i] = NULL;
  _outputs[3] = std::make_pair(1, 2);
  _outputs[4] = std::make_pair(5, 6);
  _outputs[10] = std::make_pair(8, 9);
  _outputs[11] = std::make_pair(12, 13);
}

AND4081::~AND4081() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
      pin == 8 || pin == 9 || pin == 12 || pin == 13)
    return (1);
  else if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (0);
  return (-1);
}

void AND4081::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 14) {
    std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw
    return ;
  } else if (_pins[this_pin - 1] == NULL) {
    _pins[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    comp.SetLink(target_pin, *this, this_pin);
  }
}

nts::Tristate AND4081::and_gate(size_t first_pin, size_t second_pin) const {
  return (static_cast<nts::Tristate>(first_pin && second_pin));
}

nts::Tristate AND4081::Compute(size_t this_pin) {
  if (this_pin >= 14) {
    std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw without ret
    return nts::Tristate::UNDEFINED;
  }
  if (isInput(this_pin))
    return (this->calcInput(this_pin));
  else if (!isInput(this_pin))
    return (this->calcOutput(this_pin));
  return (nts::Tristate::UNDEFINED); //TODO 14 et 7 considered UNDEFINED ?
}

nts::Tristate AND4081::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1])
    return nts::Tristate::UNDEFINED;
  if (!isInput(this_pin)) {
    std::cerr << "Can't use output as an input" << std::endl; //TODO throw without ret
    return nts::Tristate::UNDEFINED;
  }
  return _pins[this_pin - 1]->Compute(_links[this_pin - 1]);
}

nts::Tristate AND4081::calcOutput(size_t this_pin) {
  size_t first_pin = 0;
  size_t second_pin = 0;

  if (this_pin >= 14)
    return (nts::Tristate::UNDEFINED);
  first_pin = _outputs[this_pin].first;
  second_pin = _outputs[this_pin].second;
  if (!_pins[first_pin - 1] || !_pins[second_pin - 1])
    return (nts::Tristate::UNDEFINED);
  return and_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
		 _pins[second_pin - 1]->Compute(_links[second_pin - 1]));
}

void AND4081::Dump(void) const {
  std::cout << "4081 - AND gate:" << std::endl;
  for (int i = 0;  i < 14; i++) {
      std::cout << "\tpin n°" << i + 1 << "= ";
      if (!_pins[i])
      	std::cout << "NULL" << std::endl;
      else
      	std::cout << _pins[i]->Compute(_links.at(i)) << std::endl;
      //std::cout << ((!_pins[i]) ? "NULL" : _pins[i]->Compute(_links.at(i))) << std::endl;
    }
}
