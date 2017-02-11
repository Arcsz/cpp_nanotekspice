//
// Clock.hpp for Clock in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Mon Feb  6 17:33:04 2017 Riamon Vincent
//

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
  class Clock : public AComponent {
  public:
    Clock(Tristate val);
    ~Clock();
    Tristate Compute(size_t this_pin = 1) override;
    void inverted(void);
    Tristate getValue(void) const;
    void setValue(Tristate const val);
  };
}
#endif // !CLOCK_HPP_
