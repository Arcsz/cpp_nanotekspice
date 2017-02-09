//
// Component.cpp for Components in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Fri Feb  3 14:29:39 2017 Riamon Vincent
// Last update Thu Feb  9 16:00:40 2017 Riamon Vincent
//

#include "Component.hpp"

const std::map<std::string, nts::Component::mkComp> nts::Component::_funcMap = {
  {"input",  &nts::Component::newComp<Input>},
  {"clock",  &nts::Component::newComp<Clock>},
  {"output", &nts::Component::newComp<Output>},
  {"true",   &nts::Component::newComp<True>},
  {"false",  &nts::Component::newComp<False>},
  {"4081",   &nts::Component::newComp<AND4081>},
  {"4071",   &nts::Component::newComp<OR4071>},
  {"4011",   &nts::Component::newComp<NAND4011>},
  {"4001",   &nts::Component::newComp<NOR4001>},
  {"4030",   &nts::Component::newComp<XOR4030>},
  {"4069",   &nts::Component::newComp<INVERSE4069>},
  {"4013",   &nts::Component::newComp<FLIPFLOP4013>},
  {"4008",   &nts::Component::newComp<adder4008>},
  {"4514",   &nts::Component::newComp<decoder4514>},
  {"4040",   &nts::Component::newComp<counter4040>},
  {"4801",   &nts::Component::newComp<rand4801>},
  {"2716",   &nts::Component::newComp<rdonly2716>},
  {"4094",   &nts::Component::newComp<register4094>},
  {"4017",   &nts::Component::newComp<Jdecade4017>},
};

nts::Component nts::Component::_instance;

Component nts::Component::getInstance() {
  return _instance;
}

nts::Component::Component() {
}

nts::Component::~Component() {
}

nts::IComponent *nts::Component::createComponent(std::string const& type,
						 std::string const& value) const {
  if (!_funcMap.count(type))
    return NULL;
  mkComp func = _funcMap.at(type);
  return (this->*func)(value);
}
