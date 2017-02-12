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
  private:
    typedef struct FlipFlop {
      size_t clock;
      size_t reset;
      size_t data;
      size_t set;
      bool barre;
      Tristate oldValue;
    } FlipFlop;

  public:
    FLIPFLOP4013(Tristate val);
    ~FLIPFLOP4013();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate computeBarre(FlipFlop& output, Tristate state);
    Tristate computeDataInput(FlipFlop& output);

  private:
    std::map<size_t, FlipFlop> _outputs;
  };
}

#endif //FLIPFLOP4013_HPP_
