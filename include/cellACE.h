#ifndef _CELLACE_ 
#define _CELLACE_

#include "../include/cell.h"
#include "../include/stateDead.h"

class CellACE : public Cell {
public:
  CellACE();
  CellACE(Position* position, State* state);
  ~CellACE();
  int nextState(Lattice& lattice);
};

#endif