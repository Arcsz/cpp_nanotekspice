//
// Exception.cpp for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb  4 21:09:08 2017 David Zeng
// Last update Sat Feb  4 21:09:08 2017 David Zeng
//

#include "Exception.hpp"

nts::Exception::Exception(std::string const& msg) : _msg(msg) {
}

nts::Exception::~Exception() {
}

char const *nts::Exception::what() const throw() {
  return _msg.c_str();
}

nts::FileException::FileException(std::string const& msg) : nts::Exception(msg) {
}

nts::ParserException::ParserException(std::string const& msg) : nts::Exception(msg) {
}
