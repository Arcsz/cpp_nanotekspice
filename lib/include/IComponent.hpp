//
// IComponent.hpp for IComponent in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Jan 30 13:48:39 2017 Riamon Vincent
// Last update Wed Feb  1 09:35:35 2017 Riamon Vincent
//

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

#include <iostream>
#include <map>

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
}

#endif // !ICOMPONENT_HPP_
