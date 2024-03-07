#ifndef _STATEALIVE_ 
#define _STATEALIVE_

#include <iostream>
#include "state.h"

class StateAlive: public State {
  public:
    StateAlive(): State(1){}
    ~StateAlive(){}
    std::string print() const;
    State* clone() const {return new StateAlive();}
};

#endif