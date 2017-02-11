//
// XOR-4030.hpp for XOR-4030 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:42:07 2017 Riamon Vincent
//

#ifndef XOR4030_HPP_
# define XOR4030_HPP_

#include "AComponent.hpp"

namespace nts {
  class XOR4030 : public AComponent {
  public:
    XOR4030(Tristate val);
    ~XOR4030();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate xor_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //XOR4030_HPP_
