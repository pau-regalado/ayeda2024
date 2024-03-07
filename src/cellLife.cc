#include "../include/cellLife.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"
#include "../include/lattice.h"

CellLife::CellLife(Position& position, State& state)
    : Cell(position, state){}

CellLife::~CellLife() {}


int CellLife::countAliveNeighbours(Lattice& lattice) {
  int alives = 0;
  for (int i = 0; i < neighbours.size(); i++) {
    PositionDim<2> position(2, this->getPosition()[0] + neighbours[i][0], this->getPosition()[1] + neighbours[i][1]);
    alives += lattice.getCell(position).getStateInt();
  }
  return alives;
}

