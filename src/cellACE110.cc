#include "../include/cellACE110.h"
#include "../include/lattice.h"

CellACE110::CellACE110(Position& position, State& state): CellACE(position, state) {
  std::cout << "Cree CellACE110" << std::endl;
}

CellACE110::~CellACE110() { }

int CellACE110::nextState(Lattice& lattice) {
  std::cout << "next state 110" << std::endl;
  int L = this->getLeftNeightbourStateValue(lattice);
  int R = this->getRightNeightbourStateValue(lattice);
  int C = this->getStateInt();
  int S1 = C + R;
  int S2 = C * R;
  int S3 = C * R * L;
  int S  = (S1 + S2 + S3) % 2;

  if (S) {
    this->setNextState(*(new StateAlive()));
  } else {
    this->setNextState(*(new StateDead()));
  }
  
  return S;
}