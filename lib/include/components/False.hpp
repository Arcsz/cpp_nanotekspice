//
// False.hpp for False in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Mon Feb  6 17:35:28 2017 Riamon Vincent
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

#include "AComponent.hpp"

namespace nts {
  class False : public AComponent {
  public:
    False(Tristate val);
    ~False();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate getValue(void) const;
    void setValue(Tristate const val);
  };
}

#endif // !FALSE_HPP_
