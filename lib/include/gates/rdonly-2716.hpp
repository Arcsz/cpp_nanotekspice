//
// rdonly-2716.hpp for rdonly-2716 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:43:29 2017 Riamon Vincent
//

#ifndef rdonly2716_HPP_
# define rdonly2716_HPP_

#include "AComponent.hpp"

namespace nts {
  class rdonly2716 : public AComponent {
  public:
    rdonly2716(Tristate val);
    ~rdonly2716();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //rdonly2716_HPP_
