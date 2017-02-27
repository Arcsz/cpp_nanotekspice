//
// Jdecade-4017.hpp for Jdecade-4017 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Fri Feb 17 16:14:15 2017 Riamon Vincent
//

#ifndef Jdecade4017_HPP_
# define Jdecade4017_HPP_

#include "AComponent.hpp"

namespace nts {
  class Jdecade4017 : public AComponent {
  private:
    typedef struct Jdecade {
      size_t clock;
      size_t master_reset;
      Tristate value;
    } Jdecade;

  public:
    Jdecade4017(Tristate val);
    ~Jdecade4017();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, Jdecade> _outputs;
  };
}

#endif //Jdecade4017_HPP_
