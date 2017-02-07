#ifndef NTS_HPP_
# define NTS_HPP_

# include "Shell.hpp"
# include "Parser.hpp"
# include "Circuit.hpp"

namespace nts {

  class Nts {
  public:
    Nts();
    ~Nts();

    // start main process
    void run(std::vector<std::string> args);

  private:
    Shell _shell;
    Circuit _circuit;
    Parser _parser;
  };
}

#endif /* !NTS_HPP_ */
