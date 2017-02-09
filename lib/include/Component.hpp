//
// Component.hpp for Component in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Feb  3 14:30:15 2017 Riamon Vincent
// Last update Thu Feb  9 01:16:53 2017 Riamon Vincent
//

#ifndef COMPONENT_HPP_
# define COMPONENT_HPP_

# include "IComponent.hpp"
# include "Input.hpp"
# include "Clock.hpp"
# include "Output.hpp"
# include "True.hpp"
# include "False.hpp"
# include "AND-4081.hpp"
# include "OR-4071.hpp"
# include "NAND-4011.hpp"
# include "NOR-4001.hpp"
# include "XOR-4030.hpp"
# include "INVERSE-4069.hpp"
# include "FlipFlop-4013.hpp"
# include "adder-4008.hpp"
# include "decoder-4514.hpp"
# include "counter-4040.hpp"
# include "rand-4801.hpp"
# include "rdonly-2716.hpp"
# include "register-4094.hpp"
# include "Jdecade-4017.hpp"

namespace nts {

  class Component {
  public:
    Component();
    ~Component();
    IComponent *createComponent(std::string const& type,
				std::string const& value) const;

    typedef IComponent *(Component::*mkComp)(std::string const& value) const;

  private:
    static const std::map<std::string, mkComp> _funcMap;

    inline Tristate getTristate(std::string const& val) const {
      if (val == "0")
	return nts::Tristate::FALSE;
      else if (val == "1")
	return nts::Tristate::TRUE;
      return nts::Tristate::UNDEFINED;
    }

    template<class T>
    IComponent *newComp(std::string const& val) const {
      return new T(getTristate(val));
    }
  };
}

#endif //!COMPONENT_HPP_
