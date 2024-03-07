#include "../include/cellACE30.h"
#include "../include/lattice.h"

CellACE30::CellACE30(Position& position, State& state) : CellACE(position, state) { }

CellACE30::~CellACE30() { }

int CellACE30::nextState(Lattice& lattice) {
  int L = this->getLeftNeightbourStateValue(lattice);
  int R = this->getRightNeightbourStateValue(lattice);
  int C = this->getStateInt();
  int S1 = C * R;
  int S2 = C + R + L;
  int S  = (S1 + S2) % 2;
  if (S) {
    this->setNextState(*(new StateAlive()));
  } else {
    this->setNextState(*(new StateDead()));
  }
  
  return L;
}