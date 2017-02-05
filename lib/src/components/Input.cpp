//
// Input.cpp for Input in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Wed Feb  1 14:51:14 2017 Riamon Vincent
//

#include "components/Input.hpp"

Input::Input(nts::Tristate val){
  _val = val;
  _pin[0] = NULL;
  _links[0] = 0;
  // _links.first = 0;
  // _links.second = 0;
}

Input::~Input() {
}

nts::Tristate Input::Compute(size_t this_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw without ret
      return nts::Tristate::UNDEFINED;
    }
  return _val;
}

void Input::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; //TODO throw
      return ;
    } else if (_pin[this_pin - 1] == NULL) {
      _pin[this_pin - 1] = &comp;
      _links[this_pin - 1] = target_pin;
      // _links.first = this_pin - 1;
      // _links.second = target_pin;
    }
}

void Input::Dump(void) const {
  std::cout << "Input:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

nts::Tristate Input::getValue(void) const {
  return _val;
}

std::map<size_t, size_t> Input::getLinks(void) const {
  return _links;
}

void Input::setValue(nts::Tristate value) {
  _val = value;
}
