//
// rand-4801.hpp for rand-4801 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:41:49 2017 Riamon Vincent
//

#ifndef rand4801_HPP_
# define rand4801_HPP_

#include "IComponent.hpp"

namespace nts {
  class rand4801 : public nts::IComponent {
  public:
    rand4801(nts::Tristate val);
    virtual ~rand4801();
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

#endif //rand4801_HPP_
