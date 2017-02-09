//
// IComponent.hpp for IComponent in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Mon Jan 30 13:48:39 2017 Riamon Vincent
// Last update Thu Feb  9 21:17:03 2017 Riamon Vincent
//

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

# include <sstream>
# include <iostream>
# include <map>
# include "Exception.hpp"

namespace nts {
  enum Tristate {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
  };

  class IComponent {
  public:
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent& component,
			 size_t pin_num_target) = 0;
    virtual void Dump(void) const = 0;
    virtual ~IComponent(void) {}
  };

  inline std::string pinError(std::string const& name, size_t pin) {
    return std::string(name + ": Error Pin: Pin " + std::to_string(pin) + " doesn't exist");
  }
}

//using namespace nts;

#endif // !ICOMPONENT_HPP_
