//
// FLIPFLOP-4013.hpp for FLIPFLOP-4013 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:40:48 2017 Riamon Vincent
//

#ifndef FLIPFLOP4013_HPP_
# define FLIPFLOP4013_HPP_

#include "AComponent.hpp"

namespace nts {
  class FLIPFLOP4013 : public AComponent {
  public:
    FLIPFLOP4013(Tristate val);
    ~FLIPFLOP4013();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //FLIPFLOP4013_HPP_
