//
// Exception.cpp for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb  4 21:09:08 2017 David Zeng
// Last update Mon Feb  6 21:16:27 2017 Riamon Vincent
//

#include "Exception.hpp"

nts::Exception::Exception(std::string const& msg) : _msg(msg) {
}

nts::Exception::~Exception() {
}

char const *nts::Exception::what() const throw() {
  return _msg.c_str();
}

nts::InputException::InputException(std::string const& msg) : nts::Exception(msg) {
}

nts::OutputException::OutputException(std::string const& msg) : nts::Exception(msg) {
}

nts::ChipsetException::ChipsetException(std::string const& msg) : nts::Exception(msg) {
}

nts::UnknowTypeException::UnknowTypeException(std::string const& msg) : nts::Exception(msg) {
}

nts::PinException::PinException(std::string const& msg) : nts::Exception(msg) {
}

nts::FileException::FileException(std::string const& msg) : nts::Exception(msg) {
}

nts::ParserException::ParserException(std::string const& msg) : nts::Exception(msg) {
}
