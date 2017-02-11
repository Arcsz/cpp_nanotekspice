//
// counter-4040.hpp for counter-4040 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:42:30 2017 Riamon Vincent
//

#ifndef counter4040_HPP_
# define counter4040_HPP_

#include "AComponent.hpp"

namespace nts {
  class counter4040 : public AComponent {
  public:
    counter4040(Tristate val);
    ~counter4040();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //counter4040_HPP_
