#include "../include/cellACE.h"
#include "../include/lattice.h"

CellACE::CellACE(Position& position, State& state) : Cell(position, state) {
  std::cout << "Cree CellACE" << std::endl;
}

CellACE::~CellACE() {}


int CellACE::getLeftNeightbourStateValue(Lattice& lattice) {
  //std::cout << "Cojo vecino IZQ " << this->getPosition()[0] + neighbours[0][0] << std::endl;
  PositionDim<1> position(1, this->getPosition()[0] + neighbours[0][0]);
  //std::cout << "Creo la pos " << position[0] << std::endl;
  return lattice.getCell(position).getStateInt();
}

int CellACE::getRightNeightbourStateValue(Lattice& lattice) {
  //std::cout << "Cojo vecino DER" << std::endl;
  PositionDim<1> position(1, this->getPosition()[0] + neighbours[1][0]);
  return lattice.getCell(position).getStateInt();
}
