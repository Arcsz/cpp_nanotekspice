//
// NOR-4001.hpp for NOR-4001 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:42:59 2017 Riamon Vincent
//

#ifndef NOR4001_HPP_
# define NOR4001_HPP_

#include "AComponent.hpp"

namespace nts {
  class NOR4001 : public AComponent {
  public:
    NOR4001(Tristate val);
    ~NOR4001();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nor_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //NOR4001_HPP_
