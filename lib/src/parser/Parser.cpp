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
#include <sstream>
#include "Parser.hpp"
#include "Exception.hpp"

nts::Parser::Parser() {

}

nts::Parser::~Parser() {

}

void nts::Parser::feed(std::string const& input) {
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
    _inputs.push(str);
  }
}

void nts::Parser::parseTree(t_ast_node& root) {

}

nts::t_ast_node *nts::Parser::createTree() {
  t_ast_node *root = createNode("", ASTNodeType::DEFAULT, "root");

  if (!parseChipset(root)) {
    throw ParserException("Missing chipset section");
  }
  if (!parseLinks(root)) {
    throw ParserException("Missing links section");
  }

  return root;
}

void nts::Parser::parseFile(std::string const& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw FileException("Can't open file: " + filename);
  }

  std::string str;
  while (std::getline(file, str)) {
    feed(str);
  }
}

void nts::Parser::dump(t_ast_node const *root) const {
  // TODO DELETE
  if (root->type != ASTNodeType::NEWLINE) {
    std::cout << *root << std::endl;
  }

  if (root->children) {
    if (root->type != ASTNodeType::NEWLINE) {
      std::cout << "children:" << std::endl;
    }
    for (t_ast_node const *node : *root->children) {
      dump(node);
    }
  }

  if (root->type == ASTNodeType::NEWLINE) {
    std::cout << std::endl;
  }
}

// -------------------------------PRIVATE---------------------------------------

nts::t_ast_node *nts::Parser::createNode(std::string const& lexeme,
				    ASTNodeType type,
				    std::string const& value) {
  t_ast_node *node = new t_ast_node(NULL);

  node->lexeme = lexeme;
  node->type = type;
  node->value = value;
  return node;
}

void nts::Parser::pushNode(t_ast_node *node, t_ast_node *child) {
  // check if it already has children
  if (node->children) {
    node->children->push_back(child);
  } else {
    node->children = new std::vector<t_ast_node*>;
    node->children->push_back(child);
  }
}

bool nts::Parser::parseChipset(t_ast_node *root) {
  if (_inputs.empty()) {
    return false;
  }

  std::string line = _inputs.front();
  if (line != ".chipsets:") {
    return false;
  }
  _inputs.pop();

  // create a chipset node
  t_ast_node *chipsetNode = createNode(line, ASTNodeType::SECTION, "chipsets");

  // check first component and push as many component as possible
  if (!parseComponent(chipsetNode)) {
    throw ParserException("Expected at least 1 component"); // TODO CONFIRM THIS
  } else {
    while (parseComponent(chipsetNode));
  }

  pushNode(root, chipsetNode);
  return true;
}

Option<std::string> nts::Parser::getCompValue(std::string const& line,
					      std::string& name) const {
  size_t parenPos = name.find('(');

  if (parenPos != std::string::npos) {
    std::string value = name.substr(parenPos + 1);
    name = name.substr(0, parenPos);

    if (name.empty() || value[value.size() - 1] != ')') {
      throw ParserException("Syntax error while parsing component "
			    "with the following line\n" + line);
    }

    value = value.substr(0, value.size() - 1);
    return Option<std::string>(value);
  }

  return Option<std::string>();
}

bool nts::Parser::parseComponent(t_ast_node *chipsets) {
  if (_inputs.empty()) {
    return false;
  }

  std::string line = _inputs.front();
  if (line == ".links:") {
    return false;
  }

  std::stringstream lineStream(line);

  //parse component
  std::string component;
  std::string name;
  if (!(lineStream >> component) || !(lineStream >> name)) {
    return false;
  }

  // throw exception if there is still smth in the stringstream
  if (lineStream.rdbuf()->in_avail() != 0) {
    std::string remain;
    getline(lineStream, remain);
    throw ParserException("Expected end of line but got: " + remain);
  }
  Option<std::string> optValue = getCompValue(line, name);

  // create node and push them in chipsets
  t_ast_node *newLine = createNode(line, ASTNodeType::NEWLINE, "newline");
  pushNode(newLine, createNode(component, ASTNodeType::COMPONENT, "component"));
  pushNode(newLine, createNode(name, ASTNodeType::STRING, "name"));
  if (optValue) {
    pushNode(newLine, createNode(*optValue, ASTNodeType::STRING, "value"));
  }

  // push this line into chipsets and pop this input
  pushNode(chipsets, newLine);
  _inputs.pop();
  return true;
}

bool nts::Parser::parseLinks(t_ast_node *root) {
  if (_inputs.empty()) {
    return false;
  }

  std::string line = _inputs.front();
  if (line != ".links:") {
    return false;
  }
  _inputs.pop();

  t_ast_node *linksNode = createNode(line, ASTNodeType::SECTION, "links");

  // check first link and push as many link as possible
  if (!parseLink(linksNode)) {
    throw ParserException("Expected at least 1 link"); // TODO CONFIRM THIS
  } else {
    while (parseLink(linksNode));
  }

  pushNode(root, linksNode);
  return true;
}

bool nts::Parser::parseLink(t_ast_node *links) {
  if (_inputs.empty()) {
    return false;
  }

  std::string line = _inputs.front();
  if (line == ".links:" || line == ".chipsets:") {
    throw ParserException("Expected link but got Section: " + line);
  }

  _inputs.pop();
  return true;
}

std::ostream& operator<<(std::ostream& os, nts::t_ast_node node) {
  os << "lexeme: \"" << node.lexeme << "\" value: \"" << node.value << "\"";
  return os;
}
