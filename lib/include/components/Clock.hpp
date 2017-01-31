//
// Clock.hpp for Clock in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Tue Jan 31 15:44:47 2017 Riamon Vincent
//

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

#include "IComponent.hpp"

class Clock : public nts::IComponent {
public:
  Clock(nts::Tristate val);
  virtual ~Clock();
  virtual nts::Tristate compute(size_t this_pin = 1);
  virtual void setLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void dump(void) const;
  void inverted(void);
  nts::Tristate getValue(void) const;
  std::pair<size_t, size_t> getLinks(void) const;
  void setValue(nts::Tristate const val);

private:
  nts::Tristate _val;
  IComponent *_pin[1];
  std::pair<size_t, size_t> _links;
};

#endif // !CLOCK_HPP_
