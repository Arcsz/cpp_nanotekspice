//
// adder-4008.hpp for adder-4008 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:37:38 2017 Riamon Vincent
//

#ifndef adder4008_HPP_
# define adder4008_HPP_

#include "AComponent.hpp"

namespace nts {
  class adder4008 : public AComponent {
  public:
    adder4008(Tristate val);
    ~adder4008();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate calcCarryOut(size_t pin);
    Tristate add_gate(size_t first_pin, size_t second_pin, Tristate& carry) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //adder4008_HPP_
