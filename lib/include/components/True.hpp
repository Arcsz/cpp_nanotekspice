//
// True.hpp for True in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Mon Feb  6 17:36:56 2017 Riamon Vincent
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

#include "AComponent.hpp"

namespace nts {
  class True : public AComponent {
  public:
    True(Tristate val);
    ~True();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate getValue(void) const;
    void setValue(Tristate const val);
  };
}

#endif // !TRUE_HPP_
