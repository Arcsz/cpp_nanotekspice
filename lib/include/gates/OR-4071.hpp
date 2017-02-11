//
// OR-4071.hpp for OR-4071 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:39:34 2017 Riamon Vincent
//

#ifndef OR4071_HPP_
# define OR4071_HPP_

#include "AComponent.hpp"

namespace nts {
  class OR4071 : public AComponent {
  public:
    OR4071(Tristate val);
    ~OR4071();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate or_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //OR4071_HPP_
