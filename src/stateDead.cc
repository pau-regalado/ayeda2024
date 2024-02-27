#include "../include/stateDead.h"
#include "../include/stateAlive.h"
#include "../include/lattice.h"
#include "../include/cell.h"

State* StateDead::nextState(int vivas){  
  if (vivas == 3){
    return new StateAlive();
  } else {
    return new StateDead();
  }
}

std::string StateDead::print() const {
  return "🟦";
}