#include <exception>
#include <string>

class Error : public std::exception {
  public:
    Error() {}
    ~Error() {}
    virtual std::string what() = 0;
};


class Ac_Exception : public Error {
  public:
    std::string what() {
      return "Invalid access to coordinates";
    }
};

class ParsingException : public Error {
  public:
    std::string what() {
      return "Error parsing arguments";
    }
};

class BadArgumentException : public Error {
  public:
    std::string what() {
      return "Bad arguments";
    }
};

class InvalidCharacterException : public Error {
  public:
    std::string what() {
      return "Invalid character in lattice specification file";
    }
};

class InvalidCellTypeException : public Error {
  public:
    std::string what() {
      return "Invalid cell type";
    }
};