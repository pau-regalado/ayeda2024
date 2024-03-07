#include "../include/cellACE.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"

CellACE::CellACE(const PositionDim<1>& position, const State& state) : Cell(position, state) {}

CellACE::~CellACE() {}

/*int CellACE::nextState(Lattice& lattice) {
  // nextState implementation
}*/

int CellACE::getLeftNeightbourStateValue(Lattice& lattice) {
  PositionDim<1> position(this->getPosition()[0] + neighbours[0][0]);
  return lattice.getCell(position).getStateInt();
}

int CellACE::getRightNeightbourStateValue(Lattice& lattice) {
  PositionDim<1> position(this->getPosition()[0] + neighbours[1][0]);
  return lattice.getCell(position).getStateInt();
}

void CellACE::updateState() {
  this->setState(this->getNextState());
}