#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

# include <map>
# include "IComponent.hpp"

namespace nts {

  class AComponent;

  struct Link {
    Link(AComponent *comp = NULL, size_t pin = 0);
    AComponent *comp;
    size_t pin;

    // contains comp ?
    operator bool() const;

    Tristate compute() const;
  };

  class AComponent : public IComponent {
  public:
    AComponent(std::string const& type, Tristate val, size_t maxPin);
    virtual ~AComponent();

    virtual Tristate Compute(size_t pin_num_this = 1) override = 0;
    void Dump(void) const override;

    void SetLink(size_t this_pin, IComponent& comp, size_t target_pin) override;
    std::string getType() const;

  protected:
    std::string _type;
    Tristate _val;
    size_t _maxPin;
    // map<Pin, Link<Component, Pin>>
    std::map<size_t, Link> _pins;
  };


  inline std::string pinError(std::string const& name, size_t pin) {
    return std::string(name + ": Error Pin: Pin " + std::to_string(pin) +
		       " doesn't exist");
  }
}

#endif /* !ACOMPONENT_HPP_ */
