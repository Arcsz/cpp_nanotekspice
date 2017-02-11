//
// Component.cpp for Components in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Feb  3 14:29:39 2017 Riamon Vincent
// Last update Thu Feb  9 21:45:34 2017 Riamon Vincent
//

#include "ComponentFactory.hpp"

const std::map<std::string, nts::ComponentFactory::mkComp> nts::ComponentFactory::_funcMap = {
  {"input",  &ComponentFactory::newComp<Input>},
  {"clock",  &ComponentFactory::newComp<Clock>},
  {"output", &ComponentFactory::newComp<Output>},
  {"true",   &ComponentFactory::newComp<True>},
  {"false",  &ComponentFactory::newComp<False>},
  {"4081",   &ComponentFactory::newComp<AND4081>},
  {"4071",   &ComponentFactory::newComp<OR4071>},
  {"4011",   &ComponentFactory::newComp<NAND4011>},
  {"4001",   &ComponentFactory::newComp<NOR4001>},
  {"4030",   &ComponentFactory::newComp<XOR4030>},
  {"4069",   &ComponentFactory::newComp<INVERSE4069>},
  {"4013",   &ComponentFactory::newComp<FLIPFLOP4013>},
  {"4008",   &ComponentFactory::newComp<adder4008>},
  {"4514",   &ComponentFactory::newComp<decoder4514>},
  {"4040",   &ComponentFactory::newComp<counter4040>},
  {"4801",   &ComponentFactory::newComp<rand4801>},
  {"2716",   &ComponentFactory::newComp<rdonly2716>},
  {"4094",   &ComponentFactory::newComp<register4094>},
  {"4017",   &ComponentFactory::newComp<Jdecade4017>},
};

nts::ComponentFactory nts::ComponentFactory::_instance;

nts::ComponentFactory nts::ComponentFactory::getInstance() {
  return _instance;
}

nts::ComponentFactory::ComponentFactory() {
}

nts::ComponentFactory::~ComponentFactory() {
}

nts::IComponent *nts::ComponentFactory::createComponent(std::string const& type,
							std::string const& value) const {
  if (_funcMap.count(type) == 0)
    return NULL;

  mkComp func = _funcMap.at(type);

  return (this->*func)(value);
}
