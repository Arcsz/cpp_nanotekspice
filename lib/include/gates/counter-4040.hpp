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

# include "AComponent.hpp"

namespace nts {
  class counter4040 : public AComponent {
  private:
    struct Counter {
      Tristate q1; // pin 9
      Tristate q2; // pin 7
      Tristate q3; // pin 6
      Tristate q4; // pin 5
      Tristate q5; // pin 3
      Tristate q6; // pin 2
      Tristate q7; // pin 4
      Tristate q8; // pin 13
      Tristate q9; // pin 12
      Tristate q10; // pin 14
      Tristate q11; // pin 15
      Tristate q12; // pin 1
    };
  public:
    counter4040(Tristate val);
    ~counter4040();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);

  private:
    void resetCounter();
    void updateCounter();

  private:
    size_t _clock;
    size_t _reset;
    Counter _counter;
    // binary counter
    bool _def;
    bool _newCycle;
    unsigned int _count;
    // map < Pin, TristateOutput >
    std::map<size_t, Tristate&> _outputs;
  };
}

#endif //counter4040_HPP_
