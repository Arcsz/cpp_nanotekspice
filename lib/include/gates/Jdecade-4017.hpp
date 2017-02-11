//
// Jdecade-4017.hpp for Jdecade-4017 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:39:09 2017 Riamon Vincent
//

#ifndef Jdecade4017_HPP_
# define Jdecade4017_HPP_

#include "AComponent.hpp"

namespace nts {
  class Jdecade4017 : public AComponent {
  public:
    Jdecade4017(Tristate val);
    ~Jdecade4017();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //Jdecade4017_HPP_
