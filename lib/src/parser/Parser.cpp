//
// Parser.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:07 2017 David Zeng
// Last update Thu Feb  2 00:55:07 2017 David Zeng
//

#include "Parser.hpp"

Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::feed(std::string const& input) {
  // delete comments
  std::string str = input.substr(0, input.find("#"));

  // left trim and right trim
  size_t startPos = str.find_first_not_of(" \t");
  if (startPos != std::string::npos) {
    str = str.substr(startPos);
  }

  size_t endPos = str.find_last_not_of(" \t");
  if (endPos != std::string::npos) {
    str = str.substr(0, endPos + 1);
  }

  // check if it's not empty and doesn't only contain whitespace
  if (!str.empty() && str.find_first_not_of(" \t") != std::string::npos) {
    _inputStream.push_back(str);
  }
}

void Parser::parseTree(nts::t_ast_node& root) {

}

nts::t_ast_node *Parser::createTree() {
  for (std::string inp : _inputStream) {
    std::cout << inp << std::endl;
  }
}
