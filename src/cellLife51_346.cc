#include "../include/cellLife51_346.h"
#include "../include/stateAlive.h"

CellLife51_346::CellLife51_346(const Position& position, const State& state) {}

CellLife51_346::~CellLife51_346() {}

int CellLife51_346::nextState(Lattice& lattice) {}

void CellLife51_346::updateState() {}

State* CellLife51_346::nextStateS(int vivas){
  if ((vivas == 2) || (vivas == 3)){
      return new StateAlive();
  } else {
      return new StateDead();
  }
}