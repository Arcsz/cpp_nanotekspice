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
# include "Circuit.hpp"

namespace nts {

  class Parser : public IParser {
  public:
    Parser(Circuit& circuit);
    ~Parser();

    // add input to inputstream
    void feed(std::string const& input) override;

    // parsetree with given root
    void parseTree(t_ast_node& root) override;

    // create actual tree based on inputs
    t_ast_node *createTree() override;

    // try to parse file, THROW FILE EXCEPTION
    void parseFile(std::string const& filename);

    void freeTree(t_ast_node *root) const;

  private:
    // -------------------------------LEXER-------------------------------------

    // create an ast_node
    t_ast_node *createNode(std::string const& lexeme, ASTNodeType type,
			   std::string const& value) const;

    // push ast_node into another ast_node
    void pushNode(t_ast_node *node, t_ast_node *child) const;

    // parse chipset
    bool parseChipset(t_ast_node *root);
    bool parseComponent(t_ast_node *line);

    // parse links
    bool parseLinks(t_ast_node *root);
    bool parseLink(t_ast_node *line);

    t_ast_node *getLinkNode(std::string const& str, ASTNodeType type) const;

    // parse value contained in parentheses
    Option<std::string> getCompValue(std::string const& line,
				     std::string& name) const;

    // check EOL
    void throwRemain(std::stringstream& sstr) const;

    // -------------------------------PARSER------------------------------------

    // get chipset
    void getChipset(t_ast_node *chipset);
    void getComponent(t_ast_node *component);

    // get links
    void getLinks(t_ast_node *links);
    void getLink(t_ast_node *link);

  private:
    // list of input from feed()
    std::queue<std::string> _inputs;
    // circuit to execute
    Circuit& _circuit;
  };

}

#endif /* !PARSER_HPP_ */
