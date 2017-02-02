//
// False.cpp for False in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Wed Feb  1 10:02:16 2017 Riamon Vincent
//

#include "components/False.hpp"

False::False(){
  _val = nts::Tristate::FALSE;
  // _links.first = 0;
  // _links.second = 0;
  _links[0] = 0;
  _pin[0] = NULL;
}

False::~False() {
}

nts::Tristate False::Compute(size_t this_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl;
      return nts::Tristate::UNDEFINED; // TODO throw
    }
  return _val;
}

void False::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
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

void False::Dump(void) const {
  std::cout << "False:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate False::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> False::getLinks(void) const {
  return _links;
}

void False::setValue(nts::Tristate value) {
  _val = value;
}
