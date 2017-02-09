//
// True.cpp for True in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Thu Feb  9 21:20:58 2017 Riamon Vincent
//

#include "components/True.hpp"

nts::True::True(Tristate val){
  (void)val;
  _val = nts::Tristate::TRUE;
  _links[0] = 0;
  _pin[0] = NULL;
}

nts::True::~True() {
}

nts::Tristate nts::True::Compute(size_t this_pin) {
  if (this_pin > 1) {
    throw nts::PinException(nts::pinError("True", this_pin));
  }
  return _val;
}

void nts::True::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin > 1) {
    throw nts::PinException(nts::pinError("True", this_pin));
  } else if (_pin[this_pin - 1] == NULL) {
    _pin[this_pin - 1] = &comp;
    _links[this_pin - 1] = target_pin;
    try {
      comp.SetLink(target_pin, *this, this_pin);
    }
    catch (nts::ChipsetException const& err) {
      throw err;
    }
  }
}

void nts::True::Dump(void) const {
  std::cout << "True:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate nts::True::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> nts::True::getLinks(void) const {
  return _links;
}

// void Input::setValue(nts::Tristate value) {
//   if (value == nts::Tristate::UNDEFINED)
//     throw nts::InputException("Error Input: value must be 0 or 1");
//   else
//     _val = value;
// }
