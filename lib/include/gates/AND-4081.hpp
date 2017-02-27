//
// AND-4081.hpp for AND-4081 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Fri Feb 17 16:00:31 2017 Riamon Vincent
//

#ifndef AND4081_HPP_
# define AND4081_HPP_

#include "AComponent.hpp"

namespace nts {
  class AND4081 : public AComponent {
  public:
    AND4081(Tristate val);
    ~AND4081();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate and_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //AND4081_HPP_
