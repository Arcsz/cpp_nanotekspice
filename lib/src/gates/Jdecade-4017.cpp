//
// Jdecade-4017.cpp for Jdecade-4017 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 11:33:54 2017 Riamon Vincent
// Last update Thu Feb  9 18:33:18 2017 Riamon Vincent
//

#include "Jdecade-4017.hpp"

Jdecade4017::Jdecade4017(__attribute__((unused))nts::Tristate val) {
}

Jdecade4017::~Jdecade4017() {
}

static int isInput(size_t pin) {
  if (pin == 1 || pin == 2 || pin == 5 || pin == 6 ||
      pin == 8 || pin == 9 || pin == 12 || pin == 13)
    return (1);
  else if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (0);
  return (-1);
}

void Jdecade4017::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 14) {
    throw nts::PinException(nts::pinError("C4017", this_pin));
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

nts::Tristate Jdecade4017::nand_gate(size_t first_pin, size_t second_pin) const {
  return (static_cast<nts::Tristate>(!(first_pin && second_pin)));
}

nts::Tristate Jdecade4017::Compute(size_t this_pin) {
  if (this_pin > 14) {
    throw nts::PinException(nts::pinError("C4017", this_pin));
  }
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate Jdecade4017::calcInput(size_t this_pin) {
  if (!_pins[this_pin - 1])
    return nts::Tristate::UNDEFINED;
  if (!isInput(this_pin))
    throw nts::OutputException("Can't use output as an input");
  return _pins[this_pin - 1]->Compute(_links[this_pin - 1]);
}

nts::Tristate Jdecade4017::calcOutput(size_t this_pin) {
  size_t first_pin = 0;
  size_t second_pin = 0;

  if (this_pin > 14)
    return (nts::Tristate::UNDEFINED);
  first_pin = _outputs[this_pin].first;
  second_pin = _outputs[this_pin].second;
  if (!_pins[first_pin - 1] || !_pins[second_pin - 1])
    return (nts::Tristate::UNDEFINED);
  return nand_gate(_pins[first_pin - 1]->Compute(_links[first_pin - 1]),
		 _pins[second_pin - 1]->Compute(_links[second_pin - 1]));
}

void Jdecade4017::Dump(void) const {
  std::cout << "4017 - Jdecade gate:" << std::endl;
  for (int i = 0;  i < 14; i++) {
    std::cout << "\tpin n°" << i + 1 << "= ";
    if (!_pins[i])
      std::cout << "NULL" << std::endl;
    else
      std::cout << _pins[i]->Compute(_links.at(i)) << std::endl;
  }
}
