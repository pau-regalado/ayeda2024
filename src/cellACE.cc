#include "../include/cellACE.h"
#include "../include/lattice.h"

CellACE::CellACE(Position& position, State& state) : Cell(position, state) {
  std::cout << "Cree CellACE" << std::endl;
}

CellACE::~CellACE() {}


int CellACE::getLeftNeightbourStateValue(Lattice& lattice) {
  PositionDim<1> position(this->getPosition()[0] + neighbours[0][0]);
  return lattice.getCell(position).getStateInt();
}

int CellACE::getRightNeightbourStateValue(Lattice& lattice) {
  PositionDim<1> position(this->getPosition()[0] + neighbours[1][0]);
  return lattice.getCell(position).getStateInt();
}
