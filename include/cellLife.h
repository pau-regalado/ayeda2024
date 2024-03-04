#ifndef _CELLLIFE_ 
#define _CELLLIFE_

#include "../include/cell.h"
#include "../include/stateDead.h"
class CellLife : public Cell {
public:
  CellLife();
  CellLife(Position* position, State* state) : Cell(position, state) {}
  ~CellLife();
  int nextState(Lattice& lattice);
};

#endif