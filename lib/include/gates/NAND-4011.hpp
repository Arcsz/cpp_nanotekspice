//
// NAND-4011.hpp for NAND-4011 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Feb  2 11:18:48 2017 Riamon Vincent
//

#ifndef NAND4011_HPP_
# define NAND4011_HPP_

#include "IComponent.hpp"

class NAND4011 : public nts::IComponent {
public:
  NAND4011();
  virtual ~NAND4011();
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

#endif //NAND4011_HPP_
