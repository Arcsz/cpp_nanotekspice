//
// rand-4801.hpp for rand-4801 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Mon Feb  6 17:41:49 2017 Riamon Vincent
//

#ifndef rand4801_HPP_
# define rand4801_HPP_

#include "AComponent.hpp"

namespace nts {
  class rand4801 : public AComponent {
  public:
    rand4801(Tristate val);
    ~rand4801();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;

  private:
    std::map<size_t, std::pair<size_t, size_t> > _outputs;
  };
}

#endif //rand4801_HPP_
