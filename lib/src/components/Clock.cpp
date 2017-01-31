//
// Clock.cpp for Clock in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Tue Jan 31 18:16:04 2017 Riamon Vincent
//

#include "components/Clock.hpp"

Clock::Clock(nts::Tristate val){
  _val = val;
  _pin[0] = NULL;
  _links.first = 0;
  _links.second = 0;
}

Clock::~Clock() {
}

nts::Tristate Clock::compute(size_t this_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; // To Do throw
      return nts::Tristate::UNDEFINED;
    }
  return _val;
}

void Clock::setLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 1) {
      std::cerr << "Pin " << this_pin << " doesn't exist" << std::endl; // To Do throw
      return ;
    } else if (_pin[this_pin - 1] == NULL) {
      _pin[this_pin - 1] = &comp;
      _links.first = this_pin - 1;
      _links.second = target_pin;
    }
}

void Clock::dump(void) const {
  std::cout << "Clock:" << std::endl;
  std::cout << "\tvalue= " << _val << std::endl;
  if (_pin[0] == NULL)
    std::cout << "\tpin n°1= NULL" << std::endl;
  else
    std::cout << "\tpin n°1= Linked" << std::endl;
}

void Clock::inverted(void) {
  if (_val == nts::Tristate::UNDEFINED)
    return ;
  _val = ((_val == nts::Tristate::TRUE) ? nts::Tristate::FALSE : nts::Tristate::TRUE);
}

nts::Tristate Clock::getValue(void) const {
  return _val;
}

std::pair<size_t, size_t> Clock::getLinks(void) const {
  return _links;
}

void Clock::setValue(nts::Tristate value) {
  _val = value;
}
