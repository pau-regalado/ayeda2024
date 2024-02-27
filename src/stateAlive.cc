#include "../include/stateAlive.h"
#include "../include/stateDead.h"
#include "../include/lattice.h"
#include "../include/cell.h"

State* StateAlive::nextState(int vivas){
  if ((vivas == 2) || (vivas == 3)){
      return new StateAlive();
  } else {
      return new StateDead();
  }
}

std::string StateAlive::print() const {
  return "🟧";
}