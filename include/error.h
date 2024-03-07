#ifndef _ERROR_ 
#define _ERROR_

#include <exception>
#include <string>

class Error : public std::exception {
  public:
    virtual std::string whats() = 0;
};


class Ac_Exception : public Error {
  public:
    std::string whats() {
      return "Invalid access to coordinates";
    }
};

class ParsingException : public Error {
  public:
    std::string whats() {
      return "Error parsing arguments";
    }
};

class BadArgumentException : public Error {
  public:
    std::string whats() {
      return "Bad arguments";
    }
};

class InvalidCharacterException : public Error {
  public:
    std::string whats() {
      return "Invalid character in lattice specification file";
    }
};

class InvalidCellTypeException : public Error {
  public:
    std::string whats() {
      return "Invalid cell type";
    }
};

#endif