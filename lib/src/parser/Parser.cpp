//
// Parser.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:07 2017 David Zeng
// Last update Thu Feb  2 00:55:07 2017 David Zeng
//

#include <fstream>
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
  // create tree root
  nts::t_ast_node *root = new nts::t_ast_node(NULL);

  // parseChipset();
  // parseLinks();

  return root;
}

void Parser::parseFile(std::string const& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    return; // THROW EXCEPTION
  }

  std::string str;
  while (std::getline(file, str)) {
    feed(str);
  }
}

// -------------------------------PRIVATE---------------------------------------

nts::t_ast_node *Parser::createNode(std::string const& lexeme,
				    nts::ASTNodeType type,
				    std::string const& value) {
  nts::t_ast_node *node = new nts::t_ast_node(NULL);

  node->lexeme = lexeme;
  node->type = type;
  node->value = value;
  return node;
}

void Parser::pushNode(nts::t_ast_node *node, nts::t_ast_node *child) {
  if (node->children) {
    node->children->push_back(child);
  } else {
    node->children = new std::vector<nts::t_ast_node*>;
    node->children->push_back(child);
  }
}

bool Parser::parseChipset(nts::t_ast_node *root) {

}

bool Parser::parseComponent(nts::t_ast_node *line) {

}

bool Parser::parseLinks(nts::t_ast_node *root) {

}

bool Parser::parseLink(nts::t_ast_node *line) {

}
