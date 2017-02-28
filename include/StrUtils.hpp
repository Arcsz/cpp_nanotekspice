#ifndef STRUTILS_HPP_
# define STRUTILS_HPP_

# include <string>

namespace StrUtils {

  inline bool isAlphaNum(std::string const& str) {
    for (char c : str) {
      if (!isalnum(c) && c != '_') {
	return false;
      }
    }
    return true;
  }

  inline bool isNumber(std::string const& str) {
    for (char c : str) {
      if (!isdigit(c)) {
	return false;
      }
    }
    return true;
  }

  // trim : epure str equivalent delete whitespace before and after expression
  inline std::string trim(std::string str) {
    // left trim and right trim
    size_t startPos = str.find_first_not_of(" \t");
    if (startPos != std::string::npos) {
      str = str.substr(startPos);
    }

    size_t endPos = str.find_last_not_of(" \t");
    if (endPos != std::string::npos) {
      str = str.substr(0, endPos + 1);
    }

    if (str.find_first_not_of(" \t") == std::string::npos) {
      str = "";
    }
    return str;
  }

}

#endif /* !STRUTILS_HPP_ */
