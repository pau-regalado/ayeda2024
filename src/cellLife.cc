#include "../include/cellLife.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"

CellLife::CellLife(Position& position, State& state)
    : Cell(position, state){}

CellLife::~CellLife() {}


int CellLife::countAliveNeighbours(Lattice& lattice) {
  /*int alives = 0;
  for (int i = 0; i < neighbours.size(); i++ ) {
    PositionDim<1> position(this->getPosition()[0] + neighbours[i][0]);
    alives += lattice.getCell(position).getStateInt();
  }
  return alives;*/
  return 0;
}

