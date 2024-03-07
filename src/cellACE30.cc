#include "../include/cellACE30.h"
#include "../include/lattice.h"

CellACE30::CellACE30(Position& position, State& state) : CellACE(position, state) { }

CellACE30::~CellACE30() { }

int CellACE30::nextState(Lattice& lattice) {
  int L = this->getLeftNeightbourStateValue(lattice);
  int R = this->getRightNeightbourStateValue(lattice);
  // Formula
  if (L) {
    this->setNextState(*(new StateDead()));
  } else {
    this->setNextState(*(new StateDead()));
  }
  
  return L;
}