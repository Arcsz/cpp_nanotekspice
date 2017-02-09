//
// Output.cpp for Output in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Thu Feb  9 21:25:46 2017 Riamon Vincent
//

#include "components/Output.hpp"

nts::Output::Output(Tristate val) {
  (void)val;
  _val = nts::Tristate::UNDEFINED;
  _links[0] = 0;
  _pin[0] = NULL;
}

nts::Output::~Output() {
}

nts::Tristate nts::Output::Compute(size_t this_pin) {
  if (this_pin > 1) {
    throw nts::PinException(nts::pinError("Output", this_pin));
  }
  if (_pin[this_pin - 1] != NULL) {
    _val = _pin[this_pin - 1]->Compute(_links[this_pin - 1]);
    return _val;
  }
  throw nts::OutputException("Output not link");
}

void nts::Output::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 1) {
    throw nts::PinException(nts::pinError("Output", this_pin));
  } else if (_pin[this_pin - 1] == NULL) {
    _pin[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    try {
      comp.SetLink(target_pin, *this, this_pin);
    }
    catch(nts::ChipsetException const& err) {
      throw err;
    }
  }
}

void nts::Output::Dump(void) const {
  std::cout << "Output:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate nts::Output::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> nts::Output::getLinks(void) const {
  return _links;
}

// void Output::setValue(nts::Tristate value) {
//   _val = value;
// }
