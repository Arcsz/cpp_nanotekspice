//
// Component.hpp for Component in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Fri Feb  3 14:30:15 2017 Riamon Vincent
// Last update Fri Feb  3 18:27:48 2017 Riamon Vincent
//

#ifndef COMPONENT_HPP_
# define COMPONENT_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "AND-4081.hpp"
#include "OR-4071.hpp"
#include "NAND-4011.hpp"
#include "NOR-4001.hpp"
#include "XOR-4030.hpp"
#include "INVERSE-4069.hpp"
#include "FlipFlop-4013.hpp"
#include "adder-4008.hpp"
#include "decoder-4514.hpp"
#include "counter-4040.hpp"
#include "rand-4801.hpp"
#include "rdonly-2716.hpp"
#include "register-4094.hpp"
#include "Jdecade-4017.hpp"

namespace nts {
  class Component {
  public:
    Component();
    ~Component();
    typedef nts::IComponent *(*CompFunction)(const std::string& value);
    IComponent *createComponent(const std::string &type, const std::string &value);

  private:
    std::map<std::string, CompFunction> _functab;
    static IComponent *createInput(const std::string& val);
    static IComponent *createClock(const std::string& val);
    static IComponent *createOutput(const std::string& val);
    static IComponent *createTrue(const std::string& val);
    static IComponent *createFalse(const std::string& val);
    static IComponent *create4081(const std::string& val);
    static IComponent *create4071(const std::string& val);
    static IComponent *create4011(const std::string& val);
    static IComponent *create4001(const std::string& val);
    static IComponent *create4030(const std::string& val);
    static IComponent *create4069(const std::string& val);
    static IComponent *create4013(const std::string& val);
    static IComponent *create4008(const std::string& val);
    static IComponent *create4514(const std::string& val);
    static IComponent *create4040(const std::string& val);
    static IComponent *create4801(const std::string& val);
    static IComponent *create2716(const std::string& val);
    static IComponent *create4094(const std::string& val);
    static IComponent *create4017(const std::string& val);
  };
}

#endif //!COMPONENT_HPP_
