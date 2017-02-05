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

# include <iostream>
# include <queue>
# include "cpp_nanotekspice_parser.hpp"
# include "IComponent.hpp"
# include "Option.hpp"

namespace nts {

  class Parser : public IParser {
  public:
    Parser();
    ~Parser();

    // add input to inputstream
    void feed(std::string const& input) override;

    // parsetree with given root
    void parseTree(t_ast_node& root) override;

    // create actual tree based on inputs
    t_ast_node *createTree() override;

    // try to parse file, THROW FILE EXCEPTION
    void parseFile(std::string const& filename);

    // dump every node
    void dump(t_ast_node const *root) const;

  private:
    // create an ast_node
    t_ast_node *createNode(std::string const& lexeme, ASTNodeType type,
				std::string const& value);

    // push ast_node into another ast_node
    void pushNode(t_ast_node *node, t_ast_node *child);

    // parse chipset
    bool parseChipset(t_ast_node *root);
    bool parseComponent(t_ast_node *line);

    // parse links
    bool parseLinks(t_ast_node *root);
    bool parseLink(t_ast_node *line);

    // parse value contained in parentheses
    Option<std::string> getCompValue(std::string const& line,
				     std::string& name) const;

  private:
    // list of input from feed()
    std::queue<std::string> _inputs;
    // list of components and their name
    std::map<IComponent*, std::string> _components;
  };

}

std::ostream& operator<<(std::ostream& os, nts::t_ast_node node);

#endif /* !PARSER_HPP_ */
