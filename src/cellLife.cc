#include "../include/cellLife.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"

CellLife::~CellLife() {}

int CellLife::nextState(Lattice& lattice) {
    // nextState implementation
}

int CellLife::nextState(Lattice& lattice) {
  this->nState = this->state->nextState(this->countAliveNeighbours(lattice));
  return 0;
}

void CellLife::updateState() {
  this->state = this->nState;
}

int CellLife::countAliveNeighbours(Lattice& lattice) {
  /*int alives = 0;
  for (int i = 0; i < neighbours.size(); i++ ) {
    PositionDim<1> position(this->getPosition()[0] + neighbours[i][0]);
    alives += lattice.getCell(position).getStateInt();
  }
  return alives;*/
}


std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}
