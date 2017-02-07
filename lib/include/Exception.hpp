//
// Exception.hpp for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb  4 21:09:10 2017 David Zeng
// Last update Mon Feb  6 21:17:31 2017 Riamon Vincent
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <string>
# include <exception>

namespace nts {

  class Exception : public std::exception {
  public:
    Exception(std::string const& msg);
    virtual ~Exception();

    char const *what() const throw();

  private:
    std::string _msg;
  };

  class InputException : public Exception {
  public:
    InputException(std::string const& msg);
  };

  class OutputException : public Exception {
  public:
    OutputException(std::string const& msg);
  };

  class UnknowTypeException : public Exception {
  public:
    UnknowTypeException(std::string const& msg);
  };

  class ChipsetException : public Exception {
  public:
    ChipsetException(std::string const& msg);
  };

  class PinException : public Exception {
  public:
    PinException(std::string const& msg);
  };

  /**
   * File not found / can't be opened
   */
  class FileException : public Exception {
  public:
    FileException(std::string const& msg);
  };

  /**
   * Parsing error : syntactic error
   */
  class ParserException : public Exception {
  public:
    ParserException(std::string const& msg);
  };

}

#endif /* !EXCEPTION_HPP_ */
