#ifndef _STATEDEAD_ 
#define _STATEDEAD_

#include <iostream>
#include "state.h"

class StateDead: public State {  
  public:
    StateDead(): State(0){}
    ~StateDead(){}
    std::string print() const;
    State* clone() const {return new StateDead();}
};

#endif