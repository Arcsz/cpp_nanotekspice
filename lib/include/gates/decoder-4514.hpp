//
// decoder-4514.hpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Thu Mar  2 11:29:03 2017 Riamon Vincent
//

#ifndef decoder4514_HPP_
# define decoder4514_HPP_

#include <functional>
#include <utility>
#include "AComponent.hpp"

namespace nts {
  class decoder4514 : public AComponent {
  public:
    decoder4514(Tristate val);
    ~decoder4514();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;
    void computeS(Tristate, Tristate, Tristate, Tristate, size_t);
    void setAll(Tristate);

  private:
    std::map<size_t, Tristate> _outputs;
  };
}

#endif //decoder4514_HPP_
