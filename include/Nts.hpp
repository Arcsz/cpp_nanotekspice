//
// Nts.hpp for  in /home/zeng_d/rendu/C++/cpp_nanotekspice
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sun Feb 12 00:08:01 2017 David Zeng
// Last update Sun Feb 12 00:08:01 2017 David Zeng
//

#ifndef NTS_HPP_
# define NTS_HPP_

# include "Circuit.hpp"
# include "Shell.hpp"
# include "Parser.hpp"

namespace nts {

  class Nts {
  public:
    Nts();
    ~Nts();

    // start main process
    void run(std::vector<std::string> args);

  private:
    Circuit _circuit;
    Shell _shell;
    Parser _parser;
  };
}

#endif /* !NTS_HPP_ */
