#ifndef _STATEALIVE_ 
#define _STATEALIVE_

#include <iostream>
#include "state.h"

class StateAlive: public State {
  public:
    StateAlive(): State(1){}
    ~StateAlive(){}
    State* nextState(int vivas);
    std::string print() const;
};

#endif