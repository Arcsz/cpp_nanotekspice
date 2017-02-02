//
// INVERSE-4069.hpp for INVERSE-4069 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Feb  2 11:30:56 2017 Riamon Vincent
//

#ifndef INVERSE4069_HPP_
# define INVERSE4069_HPP_

#include "IComponent.hpp"

class INVERSE4069 : public nts::IComponent {
public:
  INVERSE4069();
  virtual ~INVERSE4069();
  virtual nts::Tristate Compute(size_t this_pin = 1);
  virtual void SetLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void Dump(void) const;
  nts::Tristate calcInput(size_t pin);
  nts::Tristate calcOutput(size_t pin);
  nts::Tristate not_gate(size_t first_pin) const;

private:
  nts::IComponent *_pins[14];
  std::map<size_t, size_t> _links;
  std::map<size_t, size_t> _outputs;
};

#endif //INVERSE4069_HPP_
