#ifndef NTS_HPP_
# define NTS_HPP_

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
    Circuit _circuit;
    Parser _parser;
    // TODO add shell
  };
}

#endif /* !NTS_HPP_ */
