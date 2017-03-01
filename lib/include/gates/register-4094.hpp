//
// register-4094.hpp for register-4094 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:40:05 2017 Riamon Vincent
//

#ifndef register4094_HPP_
# define register4094_HPP_

# include "AComponent.hpp"

namespace nts {
  class register4094 : public AComponent {
  private:
    enum Counter {
      Q1 = 0, // pin 4
      Q2, // pin 5
      Q3, // pin 6
      Q4, // pin 7
      Q5, // pin 14
      Q6, // pin 13
      Q7, // pin 12
      Q8, // pin 11
    };

  public:
    register4094(Tristate val);
    ~register4094();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);

  private:
    void shift(Tristate val);

  private:
    size_t _clock;
    size_t _data;
    size_t _strobe;
    size_t _oe;
    Tristate _states[8];
    Tristate _qs2; // q's
    Tristate _qs1; // qs
    Tristate _oldClock;
    std::map<size_t, Tristate&> _outputs;
  };
}

#endif //register4094_HPP_
