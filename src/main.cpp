//
// main.cpp for  in /home/zeng_d/test/C++/parser
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Thu Feb  2 00:55:24 2017 David Zeng
// Last update Thu Feb  2 00:55:24 2017 David Zeng
//

#include "../lib/include/Parser.hpp"

int main(int argc, char **argv) {
  Parser parser;

  parser.feed("hello world my friend");
  parser.feed("ab   ");
  parser.feed("     ab");
  parser.feed("     ab   ");
  parser.feed("       ");
  parser.feed("           #");
  parser.feed("#         ");
  parser.feed("        #         ");
  parser.createTree();
  return 0;
}
