//
// register-4094.hpp for register-4094 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:40:05 2017 Riamon Vincent
//

#ifndef register4094_HPP_
# define register4094_HPP_

#include "IComponent.hpp"

namespace nts {
  class register4094 : public nts::IComponent {
  public:
    register4094(nts::Tristate val);
    virtual ~register4094();
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
}

#endif //register4094_HPP_
