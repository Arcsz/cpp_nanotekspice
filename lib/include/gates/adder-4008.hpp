//
// adder-4008.hpp for adder-4008 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Feb  2 19:33:43 2017 Riamon Vincent
//

#ifndef adder4008_HPP_
# define adder4008_HPP_

#include "IComponent.hpp"

class adder4008 : public nts::IComponent {
public:
  adder4008();
  virtual ~adder4008();
  virtual nts::Tristate Compute(size_t this_pin = 1);
  virtual void SetLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void Dump(void) const;
  nts::Tristate calcInput(size_t pin);
  nts::Tristate calcOutput(size_t pin);
  nts::Tristate calcCarryOut(size_t pin);
  nts::Tristate add_gate(size_t first_pin, size_t second_pin, nts::Tristate& carry) const;

private:
  nts::IComponent *_pins[16];
  std::map<size_t, size_t> _links;
  std::map<size_t, std::pair<size_t, size_t> > _outputs;
};

#endif //adder4008_HPP_
