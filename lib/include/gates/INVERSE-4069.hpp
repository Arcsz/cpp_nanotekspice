//
// INVERSE-4069.hpp for INVERSE-4069 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:42:44 2017 Riamon Vincent
//

#ifndef INVERSE4069_HPP_
# define INVERSE4069_HPP_

#include "AComponent.hpp"

namespace nts {
  class INVERSE4069 : public AComponent {
  public:
    INVERSE4069(Tristate val);
    ~INVERSE4069();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate not_gate(size_t first_pin) const;

  private:
    std::map<size_t, size_t> _outputs;
  };
}

#endif //INVERSE4069_HPP_
