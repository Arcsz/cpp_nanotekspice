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

  // try to parse file, THROW FILE EXCEPTION
  void parseFile(std::string const& filename);

private:
  // create an ast_node
  nts::t_ast_node *createNode(std::string const& lexeme, nts::ASTNodeType type,
			      std::string const& value);

  // push ast_node into another ast_node
  void pushNode(nts::t_ast_node *node, nts::t_ast_node *child);

  // parse chipset
  bool parseChipset(nts::t_ast_node *root);
  bool parseComponent(nts::t_ast_node *line);

  // parse links
  bool parseLinks(nts::t_ast_node *root);
  bool parseLink(nts::t_ast_node *line);

private:
  // list of input from feed()
  std::vector<std::string> _inputStream;
  // list of components
  std::map<std::string, nts::IComponent*> _components;
};

#endif /* !PARSER_HPP_ */
