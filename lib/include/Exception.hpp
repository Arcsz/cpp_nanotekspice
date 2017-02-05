//
// Exception.hpp for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Feb  4 21:09:10 2017 David Zeng
// Last update Sat Feb  4 21:09:10 2017 David Zeng
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
