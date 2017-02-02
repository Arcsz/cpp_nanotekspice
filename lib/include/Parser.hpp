//
// Parser.hpp<include> for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:54:52 2017 David Zeng
// Last update Thu Feb  2 00:54:52 2017 David Zeng
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "IComponent.hpp"

class Parser : public nts::IParser {
public:
  Parser();
  ~Parser();

  // add input to inputstream
  void feed(std::string const& input) override;

  // parsetree with given root
  void parseTree(nts::t_ast_node& root) override;

  // create actual tree based on inputs
  nts::t_ast_node *createTree() override;

private:

private:
  // list of input from feed()
  std::vector<std::string> _inputStream;
  // list of components
  std::map<std::string, nts::IComponent*> _components;
  // list of outputs
  std::vector<std::string> _output;
};

#endif /* !PARSER_HPP_ */
