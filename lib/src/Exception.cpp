//
// Exception.cpp for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb  4 21:09:08 2017 David Zeng
// Last update Fri Feb 10 12:09:00 2017 Riamon Vincent
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

nts::UninitializeCompException::UninitializeCompException(std::string const& msg) : nts::Exception(msg) {
}

nts::ChipsetException::ChipsetException(std::string const& msg) : nts::Exception(msg) {
}

nts::ComponentExistException::ComponentExistException(std::string const& msg) : nts::Exception(msg) {
}

nts::ComponentNotFoundException::ComponentNotFoundException(std::string const& msg) : nts::Exception(msg) {
}

nts::UnknownTypeException::UnknownTypeException(std::string const& msg) : nts::Exception(msg) {
}

nts::PinException::PinException(std::string const& msg) : nts::Exception(msg) {
}

nts::LinkExistException::LinkExistException(std::string const& msg) : nts::Exception(msg) {
}

nts::FileException::FileException(std::string const& msg) : nts::Exception(msg) {
}

nts::ParserException::ParserException(std::string const& msg) : nts::Exception(msg) {
}

nts::UnmodifiedException::UnmodifiedException(std::string const& msg) : nts::Exception(msg) {
}
