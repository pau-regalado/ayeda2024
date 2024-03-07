#include "../include/cellLife23_3.h"
#include "../include/stateAlive.h"

CellLife23_3::CellLife23_3(const Position& position, const State& state) {}

CellLife23_3::~CellLife23_3() {}

int CellLife23_3::nextState(Lattice& lattice) {}

void CellLife23_3::updateState() {}


State* CellLife23_3::nextStateS(int vivas){
  if ((vivas == 2) || (vivas == 3)){
      return new StateAlive();
  } else {
      return new StateDead();
  }
}