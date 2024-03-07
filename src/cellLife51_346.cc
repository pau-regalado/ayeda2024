#include "../include/cellLife51_346.h"
#include "../include/stateAlive.h"

CellLife51_346::CellLife51_346(Position& position, State& state): CellLife(position, state) {}

CellLife51_346::~CellLife51_346() {}

int CellLife51_346::nextState(Lattice& lattice) {
  int aliveNeighbours = this->countAliveNeighbours(lattice);
  if (this->getStateInt()) {
    if ((aliveNeighbours == 1) || (aliveNeighbours == 5)){
      this->nState = new StateAlive();
    } else {
      this->nState = new StateDead();
    }
  } else {
    if ((aliveNeighbours == 3) || (aliveNeighbours == 4) || (aliveNeighbours == 6)){
      this->nState = new StateAlive();
    } else {
      this->nState = new StateDead();
    }
  }
  return 0;
}
