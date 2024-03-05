#include <exception>
#include <string>

class Error : public std::exception {
private :
  std::string message;

public:
  Error() {}
  ~Error() {}
  virtual std::string toString() = 0;
};


class Ac_Exception : public Error {
  std::string toString() {
    return "Invalid access to coordinates";
  }
};