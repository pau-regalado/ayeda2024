#include "../include/cellACE110.h"
#include "../include/lattice.h"

CellACE110::CellACE110(const Position& position, const State& state)
  : CellACE(position, state) { }

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