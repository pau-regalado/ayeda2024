#ifndef _CELLLIFE23_3_ 
#define _CELLLIFE23_3_

#include "../include/cellLife.h"
#include "../include/stateDead.h"
class CellLife23_3 : public CellLife {
public:
  CellLife23_3();
  CellLife23_3(const Position& position, const State& state) : CellLife(position, state) {}
  ~CellLife23_3();
  int nextState(Lattice& lattice);
  void updateState();
};

#endif