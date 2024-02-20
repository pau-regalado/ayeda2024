#ifndef _STATE_ 
#define _STATE_

#include <iostream>

class State {
  private:
    int state;
  public:
    State(int state = 0);
    int getState();
    int getState() const;
    void setState(int state);
    std::string print() const;
    friend std::ostream& operator<<(std::ostream& os, const State &s);
};

#endif