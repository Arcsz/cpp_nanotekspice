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
    enum Counter {
      Q0 = 0, // pin 3
      Q1, // pin 2
      Q2, // pin 4
      Q3, // pin 7
      Q4, // pin 10
      Q5, // pin 1
      Q6, // pin 5
      Q7, // pin 6
      Q8, // pin 9
      Q9, // pin 11
      QN, // pin 12
    };

  public:
    Jdecade4017(Tristate val);
    ~Jdecade4017();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);

  private:
    void resetStates();
    void computeOutputs();

  private:
    bool _newCycle;
    size_t _cp0;
    size_t _cp1;
    size_t _reset;
    Tristate _states[QN + 1];
    int _current;
    bool _def;
    std::map<size_t, Tristate&> _outputs;
  };
}

#endif //Jdecade4017_HPP_
