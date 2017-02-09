//
// Shell.hpp for Shell in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Feb  7 15:13:26 2017 Riamon Vincent
// Last update Tue Feb  7 23:30:02 2017 Riamon Vincent
//

#include <iostream>
#include <csignal>
#include "Circuit.hpp"

namespace nts {
  class Shell {
  public:
    static bool _loop;
  public:
    Shell(Circuit& circuit);
    ~Shell();
    void shell();
    void exit();
    void display();
    void simulate();
    void loop();
    void dump();
    void setValue(std::string const& name, size_t const val) const;
    typedef void (Shell::*cmdFunc)();

  private:
    bool _run;
    Circuit& _circuit;
    static const std::map<std::string, cmdFunc> _cmdFunc;
  };
}
