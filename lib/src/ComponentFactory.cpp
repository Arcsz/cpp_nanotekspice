//
// Component.cpp for Components in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Feb  3 14:29:39 2017 Riamon Vincent
// Last update Wed Mar  1 10:20:08 2017 Riamon Vincent
//

#include "ComponentFactory.hpp"

const std::map<std::string, nts::ComponentFactory::mkComp> nts::ComponentFactory::_funcMap = {
  {CONST::INPUT,  &ComponentFactory::newComp<Input>},
  {CONST::CLOCK,  &ComponentFactory::newComp<Clock>},
  {CONST::OUTPUT, &ComponentFactory::newComp<Output>},
  {CONST::TRUE,   &ComponentFactory::newComp<True>},
  {CONST::FALSE,  &ComponentFactory::newComp<False>},
  {CONST::C4081,  &ComponentFactory::newComp<AND4081>},
  {CONST::C4071,  &ComponentFactory::newComp<OR4071>},
  {CONST::C4011,  &ComponentFactory::newComp<NAND4011>},
  {CONST::C4001,  &ComponentFactory::newComp<NOR4001>},
  {CONST::C4030,  &ComponentFactory::newComp<XOR4030>},
  {CONST::C4069,  &ComponentFactory::newComp<INVERSE4069>},
  {CONST::C4013,  &ComponentFactory::newComp<FLIPFLOP4013>},
  {CONST::C4008,  &ComponentFactory::newComp<adder4008>},
  {CONST::C4514,  &ComponentFactory::newComp<decoder4514>},
  {CONST::C4040,  &ComponentFactory::newComp<counter4040>},
  {CONST::C4801,  &ComponentFactory::newComp<rand4801>},
  {CONST::C2716,  &ComponentFactory::newComp<rdonly2716>},
  {CONST::C4094,  &ComponentFactory::newComp<register4094>},
  {CONST::C4017,  &ComponentFactory::newComp<Jdecade4017>},
};

nts::ComponentFactory nts::ComponentFactory::_instance;

nts::ComponentFactory nts::ComponentFactory::getInstance() {
  return _instance;
}

nts::ComponentFactory::ComponentFactory() {
}


nts::ComponentFactory::~ComponentFactory() {
}

nts::AComponent *nts::ComponentFactory::createComponent(std::string const& type,
							std::string const& value) const {
  if (_funcMap.count(type) == 0) {
    return NULL;
  }

  mkComp func = _funcMap.at(type);

  return (this->*func)(value);
}
