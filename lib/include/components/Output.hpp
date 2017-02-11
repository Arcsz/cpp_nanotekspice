//
// Output.hpp for Output in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Mon Feb  6 17:36:31 2017 Riamon Vincent
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
  class Output : public AComponent {
  public:
    Output(Tristate val);
    ~Output();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate getValue(void) const;
    void setValue(Tristate const val);
  };
}

#endif // !OUTPUT_HPP_
