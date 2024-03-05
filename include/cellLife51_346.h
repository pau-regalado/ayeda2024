#ifndef _CELLLIFE51_346_ 
#define _CELLLIFE51_346_

#include "../include/cellLife.h"
#include "../include/stateDead.h"
class CellLife51_346 : public CellLife {
public:
  CellLife51_346();
  CellLife51_346(const Position& position, const State& state) : CellLife(position, state) {}
  ~CellLife51_346();
  int nextState(Lattice& lattice);
  void updateState();
};

#endif