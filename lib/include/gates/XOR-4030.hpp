//
// XOR-4030.hpp for XOR-4030 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Feb  2 11:04:47 2017 Riamon Vincent
//

#ifndef XOR4030_HPP_
# define XOR4030_HPP_

#include "IComponent.hpp"

class XOR4030 : public nts::IComponent {
public:
  XOR4030();
  virtual ~XOR4030();
  virtual nts::Tristate Compute(size_t this_pin = 1);
  virtual void SetLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void Dump(void) const;
  nts::Tristate calcInput(size_t pin);
  nts::Tristate calcOutput(size_t pin);
  nts::Tristate xor_gate(size_t first_pin, size_t second_pin) const;

private:
  nts::IComponent *_pins[14];
  std::map<size_t, size_t> _links;
  std::map<size_t, std::pair<size_t, size_t> > _outputs;
};

#endif //XOR4030_HPP_
