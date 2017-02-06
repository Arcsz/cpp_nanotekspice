//
// Clock.cpp for Clock in /home/riamon_v/rendu/CPP/cpp_nanotekspice/src/components
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:59:50 2017 Riamon Vincent
// Last update Mon Feb  6 10:39:13 2017 Riamon Vincent
//

#include "components/Clock.hpp"

Clock::Clock(nts::Tristate val){
  _val = val;
  _pin[0] = NULL;
  _links[0] = 0;
}

Clock::~Clock() {
}

nts::Tristate Clock::Compute(size_t this_pin) {
  if (this_pin >= 1) {
    std::stringstream ss;

    ss << "Pin " << this_pin << " doesn't exist" << std::endl;
    throw nts::PinException(ss.str());
  }
  return _val;
}

void Clock::SetLink(size_t this_pin, nts::IComponent& comp, size_t target_pin) {
  if (this_pin >= 1) {
    std::stringstream ss;

    ss << "Pin " << this_pin << " doesn't exist" << std::endl;
    throw nts::PinException(ss.str());
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

void Clock::Dump(void) const {
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

std::map<size_t, size_t> Clock::getLinks(void) const {
  return _links;
}

// void Clock::setValue(nts::Tristate value) {
//   if (value == nts::UNDEFINED)
//     throw nts::ClockException("Error Clock: value must be 0 or 1");
//   else
//     _val = value;
// }
