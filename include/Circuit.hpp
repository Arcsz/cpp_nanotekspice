#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

# include <memory>
# include <map>
# include <vector>
# include "IComponent.hpp"

namespace nts {
  class Circuit {
  public:
    Circuit();
    ~Circuit();

    // take initial values
    void takeInitValue(std::vector<std::string> const& vec);

  private:
    // list of components and their name
    std::map<std::string, std::unique_ptr<IComponent>> _components;
  };
}

#endif /* !CIRCUIT_HPP_ */
