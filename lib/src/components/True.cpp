//
// True.cpp for True in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Wed Feb  1 10:02:24 2017 Riamon Vincent
//

#include "components/True.hpp"

True::True(){
  _val = nts::Tristate::TRUE;
  _links[0] = 0;
  // _links.first = 0;
  // _links.second = 0;
  _pin[0] = NULL;
}

True::~True() {
}

nts::Tristate True::Compute(size_t this_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl;
      return nts::Tristate::UNDEFINED; // TODO throw
    }
  return _val;
}

void True::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; // TODO throw
      return ;
    } else if (_pin[this_pin - 1] == NULL) {
      _pin[this_pin - 1] = &comp;
      _links[this_pin - 1] = target_pin;
      // _links.first = this_pin - 1;
      // _links.second = target_pin;
    }
}

void True::Dump(void) const {
  std::cout << "True:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate True::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> True::getLinks(void) const {
  return _links;
}

void True::setValue(nts::Tristate value) {
  _val = value;
}
