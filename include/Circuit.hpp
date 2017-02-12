#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

# include <memory>
# include <map>
# include <vector>
# include <tuple>
# include "AComponent.hpp"

namespace nts {
  class Circuit {
  public:
    Circuit();
    ~Circuit();

    // set value
    void setValue(std::string const& str, bool isShell);
    void addComponent(std::string const& name, AComponent *comp);
    void setLink(std::string const& name1, size_t pin1,
		 std::string const& name2, size_t pin2);
    void outputDisplay() const;
    void simulate();
    void dump();
    void clockInverse();

    void checkLinks() const;
    void printComp() const;

  private:
    std::map<std::string, AComponent*> _components;
  };
}

#endif /* !CIRCUIT_HPP_ */
