#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

# include <memory>
# include <map>
# include <vector>
# include <tuple>
# include "IComponent.hpp"

namespace nts {
  class Circuit {
  public:
    Circuit();
    ~Circuit();

    std::pair<std::string, std::string> getValue(std::string const& str);

    // set value
    void setValue(std::pair<std::string, std::string> val);
    void addComponent(std::string const&, std::string const&, IComponent *);
    void setLink();
    void outputDisplay();
    void simulate();
    void dump();
    void clockInverse();

    void printComp() const;

  private:
    typedef std::unique_ptr<nts::IComponent> IComp;
    // map<name, comp>
    std::map<std::string, std::pair<std::string, IComponent*>> _components;
  };
}

#endif /* !CIRCUIT_HPP_ */
