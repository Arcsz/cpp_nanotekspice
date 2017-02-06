//
// Parser.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:07 2017 David Zeng
// Last update Mon Feb  6 15:08:54 2017 Riamon Vincent
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

  t_ast_node *chipsetNode = createNode(line, ASTNodeType::SECTION, "chipsets");

  // check first component and push as many component as possible
  if (_inputs.empty() || !parseComponent(chipsetNode)) {
    throw ParserException("Expected at least 1 component"); // TODO CONFIRM THIS
  } else {
    while (!_inputs.empty() && parseComponent(chipsetNode));
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
			    "with the following line:\n" + line);
    }

    value = value.substr(0, value.size() - 1);
    return Option<std::string>(value);
  }

  return Option<std::string>();
}

bool nts::Parser::parseComponent(t_ast_node *chipsets) {
  std::string line = _inputs.front();
  if (line == ".links:") {
    return false;
  }

  std::string component;
  std::string name;
  std::stringstream lineStream(line);
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
  if (_inputs.empty() || !parseLink(linksNode)) {
    throw ParserException("Expected at least 1 link"); // TODO CONFIRM THIS
  } else {
    while (!_inputs.empty() && parseLink(linksNode));
  }

  pushNode(root, linksNode);
  return true;
}

nts::t_ast_node *nts::Parser::getLink(std::string const& str, ASTNodeType type) {
  std::string name = str.substr(0, str.find(':'));
  std::string pin = str.substr(str.find(':') + 1, str.size());

  if (name.empty() || pin.empty()) {
    throw ParserException("Syntax error while parsing link: " + str);
  }

  t_ast_node *link = createNode(str, type, "link");
  pushNode(link, createNode(name, ASTNodeType::COMPONENT, "component"));
  pushNode(link, createNode(pin, ASTNodeType::STRING, "pin"));
  return link;
}

bool nts::Parser::parseLink(t_ast_node *links) {
  std::string line = _inputs.front();
  if (line == ".links:" || line == ".chipsets:") {
    throw ParserException("Expected link but got section: " + line);
  }

  std::string link1;
  std::string link2;
  std::stringstream lineStream(line);
  if (!(lineStream >> link1) || !(lineStream >> link2)) {
    return false;
  }
  // throw exception if there is still smth in the stringstream
  if (lineStream.rdbuf()->in_avail() != 0) {
    std::string remain;
    getline(lineStream, remain);
    throw ParserException("Expected end of line but got: " + remain);
  }

  t_ast_node *newLine = createNode(line, ASTNodeType::NEWLINE, "newline");
  pushNode(newLine, getLink(link1, ASTNodeType::LINK));
  pushNode(newLine, getLink(link2, ASTNodeType::LINK_END));

  pushNode(links, newLine);
  _inputs.pop();
  return true;
}

std::ostream& operator<<(std::ostream& os, nts::t_ast_node node) {
  os << "lexeme: \"" << node.lexeme << "\" value: \"" << node.value << "\"";
  return os;
}
