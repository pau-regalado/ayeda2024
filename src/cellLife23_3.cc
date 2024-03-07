#include "../include/cellLife23_3.h"
#include "../include/stateAlive.h"

CellLife23_3::CellLife23_3(Position& position, State& state) : CellLife(position, state) {}

CellLife23_3::~CellLife23_3() {}

int CellLife23_3::nextState(Lattice& lattice) {
  int aliveNeighbours = this->countAliveNeighbours(lattice);
  if (this->getStateInt()) {
    if ((aliveNeighbours == 2) || (aliveNeighbours == 3)){
      this->nState = new StateAlive();
    } else {
      this->nState = new StateDead();
    }
  } else {
    if (aliveNeighbours == 3){
      this->nState = new StateAlive();
    } else {
      this->nState = new StateDead();
    }
  }
  
  return 0;
}