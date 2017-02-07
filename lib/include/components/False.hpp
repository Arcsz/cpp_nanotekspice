//
// False.hpp for False in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Mon Feb  6 17:35:28 2017 Riamon Vincent
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

#include "IComponent.hpp"

namespace nts {
  class False : public nts::IComponent {
  public:
    False(Tristate val);
    virtual ~False();
    virtual nts::Tristate Compute(size_t this_pin = 1);
    virtual void SetLink(size_t this_pin,
			 nts::IComponent& comp,
			 size_t target_pin);
    virtual void Dump(void) const;
    nts::Tristate getValue(void) const;
    std::map<size_t, size_t> getLinks(void) const;
    void setValue(nts::Tristate const val);

  private:
    nts::Tristate _val;
    nts::IComponent *_pin[1];
    std::map<size_t, size_t> _links;
  };
}

#endif // !FALSE_HPP_
