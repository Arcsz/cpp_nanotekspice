//
// Input.hpp for Input in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Thu Feb  9 01:04:35 2017 Riamon Vincent
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
  class Input : public AComponent {
  public:
    Input(Tristate val);
    ~Input();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate getValue(void) const;
    void setValue(Tristate const val);
  };
}

#endif // !INPUT_HPP_
