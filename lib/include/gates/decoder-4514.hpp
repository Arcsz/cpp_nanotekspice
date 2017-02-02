//
// decoder-4514.hpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Feb  2 14:56:49 2017 Riamon Vincent
//

#ifndef decoder4514_HPP_
# define decoder4514_HPP_

#include "IComponent.hpp"

class decoder4514 : public nts::IComponent {
public:
  decoder4514();
  virtual ~decoder4514();
  virtual nts::Tristate Compute(size_t this_pin = 1);
  virtual void SetLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void Dump(void) const;
  nts::Tristate calcInput(size_t pin);
  nts::Tristate calcOutput(size_t pin);
  nts::Tristate nand_gate(size_t first_pin, size_t second_pin) const;

private:
  nts::IComponent *_pins[14];
  std::map<size_t, size_t> _links;
  std::map<size_t, std::pair<size_t, size_t> > _outputs;
};

#endif //decoder4514_HPP_
