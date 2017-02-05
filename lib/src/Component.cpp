//
// Component.cpp for Components in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Fri Feb  3 14:29:39 2017 Riamon Vincent
// Last update Fri Feb  3 18:20:47 2017 Riamon Vincent
//

#include "Component.hpp"

nts::Component::Component()
  : _functab{
	  {"Input", &nts::Component::createInput},
	  {"Clock", &nts::Component::createClock},
	  {"Output", &nts::Component::createOutput},
	  {"True", &nts::Component::createTrue},
	  {"False", &nts::Component::createFalse},
	  {"4081", &nts::Component::create4081},
	  {"4071", &nts::Component::create4071},
	  {"4011", &nts::Component::create4011},
	  {"4001", &nts::Component::create4001},
	  {"4030", &nts::Component::create4030},
	  {"4069", &nts::Component::create4069},
	  {"4013", &nts::Component::create4013},
	  {"4008", &nts::Component::create4008},
	  {"4514", &nts::Component::create4514},
	  {"4040", &nts::Component::create4040},
	  {"4801", &nts::Component::create4801},
	  {"2716", &nts::Component::create2716},
	  {"4094", &nts::Component::create4094},
	  {"4017", &nts::Component::create4017}} {
}

nts::Component::~Component(){
}

nts::IComponent *nts::Component::createComponent(const std::string &type, const std::string &value) {
  return _functab[type](value);
}

static nts::Tristate getTristate(const std::string& val) {
  if (val == "0")
    return nts::Tristate::FALSE;
  else if (val == "1")
    return nts::Tristate::TRUE;
  return nts::Tristate::UNDEFINED;
}

nts::IComponent *nts::Component::createInput(const std::string &val) {
  return new Input(getTristate(val));
}

nts::IComponent *nts::Component::createClock(const std::string &val) {
  return new Clock(getTristate(val));
}

nts::IComponent *nts::Component::createOutput(const std::string &val) {
  (void)val;
  return new Output;
}

nts::IComponent *nts::Component::createTrue(const std::string &val) {
  (void)val;
  return new True;
}

nts::IComponent *nts::Component::createFalse(const std::string &val) {
  (void)val;
  return new False;
}

nts::IComponent *nts::Component::create4081(const std::string &val) {
  return new AND4081(getTristate(val));
}

nts::IComponent *nts::Component::create4071(const std::string &val) {
  return new OR4071(getTristate(val));
}

nts::IComponent *nts::Component::create4011(const std::string &val) {
  return new NAND4011(getTristate(val));
}

nts::IComponent *nts::Component::create4001(const std::string &val) {
  return new NOR4001(getTristate(val));
}

nts::IComponent *nts::Component::create4030(const std::string &val) {
  return new XOR4030(getTristate(val));
}

nts::IComponent *nts::Component::create4069(const std::string &val) {
  return new INVERSE4069(getTristate(val));
}

nts::IComponent *nts::Component::create4013(const std::string &val) {
  return new FLIPFLOP4013(getTristate(val));
}

nts::IComponent *nts::Component::create4008(const std::string &val) {
  return new adder4008(getTristate(val));
}

nts::IComponent *nts::Component::create4514(const std::string &val) {
  return new decoder4514(getTristate(val));
}

nts::IComponent *nts::Component::create4040(const std::string &val) {
  return new counter4040(getTristate(val));
}

nts::IComponent *nts::Component::create4801(const std::string &val) {
  return new rand4801(getTristate(val));
}

nts::IComponent *nts::Component::create2716(const std::string &val) {
  return new rdonly2716(getTristate(val));
}

nts::IComponent *nts::Component::create4094(const std::string &val) {
  return new register4094(getTristate(val));
}

nts::IComponent *nts::Component::create4017(const std::string &val) {
  return new Jdecade4017(getTristate(val));
}
