//
// Output.hpp for Output in /home/riamon_v/rendu/CPP/cpp_nanotekspice/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Jan 31 12:33:49 2017 Riamon Vincent
// Last update Tue Jan 31 16:12:58 2017 Riamon Vincent
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include "IComponent.hpp"

class Output : public nts::IComponent {
public:
  Output();
  virtual ~Output();
  virtual nts::Tristate compute(size_t this_pin = 1);
  virtual void setLink(size_t this_pin,
		       nts::IComponent& comp,
		       size_t target_pin);
  virtual void dump(void) const;
  nts::Tristate getValue(void) const;
  std::pair<size_t, size_t> getLinks(void) const;
  void setValue(nts::Tristate const val);

private:
  nts::Tristate _val;
  IComponent *_pin[1];
  std::pair<size_t, size_t> _links;
};

#endif // !OUTPUT_HPP_
