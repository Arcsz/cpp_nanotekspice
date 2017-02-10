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

    // set value
    void setValue(std::string const& str, bool isShell);
    void addComponent(std::string const&, std::string const&, IComponent *);
    void setLink(std::string const& name1, size_t pin1,
		 std::string const& name2, size_t pin2);
    void outputDisplay();
    void simulate();
    void dump();
    void clockInverse();

    void printComp() const;
    std::map<std::string, std::pair<std::string, IComponent *>> getComp() const;

  private:
    typedef std::unique_ptr<nts::IComponent> IComp;
    // map<name, comp>
    std::map<std::string, std::pair<std::string, IComponent*>> _components;
  };
}

#endif /* !CIRCUIT_HPP_ */
