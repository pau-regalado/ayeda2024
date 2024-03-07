#ifndef _STATEDEAD_ 
#define _STATEDEAD_

#include <iostream>
#include "state.h"

class StateDead: public State {  
  public:
    StateDead(): State(0){}
    ~StateDead(){std::cout << "Destruyo muerta" <<  std::endl;}
    State* nextState(int vivas);
    std::string print() const;
};

#endif