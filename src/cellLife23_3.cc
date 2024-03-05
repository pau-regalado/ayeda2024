#include "../include/cellLife23_3.h"

CellLife23_3::CellLife23_3() {}

CellLife23_3::CellLife23_3(Position* position, State* state) {
  this->position = position;
  this->state = state;
}

CellLife23_3::~CellLife23_3() {}

int CellLife23_3::nextState(Lattice& lattice) {}

void CellLife23_3::updateState() {}