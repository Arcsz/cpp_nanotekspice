//
// INVERSE-4069.cpp for INVERSE-4069 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Thu Feb  9 18:32:12 2017 Riamon Vincent
//

#include "INVERSE-4069.hpp"

INVERSE4069::INVERSE4069(__attribute__((unused))nts::Tristate val) {
  for (int i = 0; i < 14; i++)
    _pins[i] = NULL;
  _outputs[2] = 1;
  _outputs[4] = 3;
  _outputs[6] = 5;
  _outputs[8] = 9;
  _outputs[10] = 11;
  _outputs[12] = 13;
}

INVERSE4069::~INVERSE4069() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13)
    return (1);
  else if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
    return (0);
  return (-1);
}

void INVERSE4069::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 14) {
    throw nts::PinException(nts::pinError("C4069", this_pin));
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

nts::Tristate INVERSE4069::not_gate(size_t first_pin) const {
  return (static_cast<nts::Tristate>(!first_pin));
}

nts::Tristate INVERSE4069::Compute(size_t this_pin) {
  if (this_pin > 14) {
    throw nts::PinException(nts::pinError("C4069", this_pin));
  }
  if (isInput(this_pin))
    return (this->calcInput(this_pin));
  else if (!isInput(this_pin))
    return (this->calcOutput(this_pin));
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate INVERSE4069::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1])
    return nts::Tristate::UNDEFINED;
  if (!isInput(this_pin))
    throw nts::OutputException("Can't use output as an input");
  return _pins[this_pin - 1]->Compute(_links[this_pin - 1]);
}

nts::Tristate INVERSE4069::calcOutput(size_t this_pin) {
  size_t first_pin = 0;

  if (this_pin > 14)
    return (nts::Tristate::UNDEFINED);
  first_pin = _outputs[this_pin];
  if (!_pins[first_pin - 1])
    return (nts::Tristate::UNDEFINED);
  return not_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]));
}

void INVERSE4069::Dump(void) const {
  std::cout << "4069 - INVERSE gate:" << std::endl;
  for (int i = 0;  i < 14; i++) {
    std::cout << "\tpin n°" << i + 1 << "= ";
    if (!_pins[i])
      std::cout << "NULL" << std::endl;
    else
      std::cout << _pins[i]->Compute(_links.at(i)) << std::endl;
  }
}
