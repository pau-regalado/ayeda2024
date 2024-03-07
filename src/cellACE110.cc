#include "../include/cellACE110.h"
#include "../include/lattice.h"

CellACE110::CellACE110(Position& position, State& state): CellACE(position, state) {
  std::cout << "Cree CellACE110" << std::endl;
}

CellACE110::~CellACE110() { }

int CellACE110::nextState(Lattice& lattice) {
  int L = this->getLeftNeightbourStateValue(lattice);
  int R = this->getRightNeightbourStateValue(lattice);
  // Otra Formula
  if (L) {
    this->setNextState(*(new StateDead()));
  } else {
    this->setNextState(*(new StateDead()));
  }
  
  return L;
}