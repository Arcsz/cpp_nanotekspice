//
// decoder-4514.hpp for decoder-4514 in /home/riamon_v/rendu/CPP/cpp_nanotekspice/lib/include/gates
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Wed Feb  1 10:40:37 2017 Riamon Vincent
// Last update Wed Mar  1 10:34:04 2017 Riamon Vincent
//

#ifndef decoder4514_HPP_
# define decoder4514_HPP_

#include "AComponent.hpp"

namespace nts {
  class decoder4514 : public AComponent {
  public:
    decoder4514(Tristate val);
    ~decoder4514();
    Tristate Compute(size_t this_pin = 1) override;
    Tristate calcInput(size_t pin);
    Tristate calcOutput(size_t pin);
    Tristate nand_gate(size_t first_pin, size_t second_pin) const;
    void computeS0();
    void computeS1();
    void computeS2();
    void computeS3();
    void computeS4();
    void computeS5();
    void computeS6();
    void computeS7();
    void computeS8();
    void computeS9();
    void computeS10();
    void computeS11();
    void computeS12();
    void computeS13();
    void computeS14();
    void computeS15();
    void setAllZero();

  private:
    typedef void (decoder4514::*computeS)();
    std::map<size_t, nts::decoder4514::computeS> _outFunc;
    std::map<size_t, Tristate/*std::pair<size_t, size_t>*/ > _outputs;
  };
}

#endif //decoder4514_HPP_
