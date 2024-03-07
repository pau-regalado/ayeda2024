#ifndef _STATE_ 
#define _STATE_

#include <iostream>

class State {
  protected:
    int state;

  public:
    State(int state = 0);
    int getState() const;
    virtual State* nextState(int vivas) = 0;
    virtual std::string print() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const State &s);

    State(const State& other) { state = other.state; }
    virtual State* clone() const = 0;
};

#endif