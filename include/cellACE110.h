#ifndef _CELLACE110_ 
#define _CELLACE110_

#include "../include/cellACE.h"
#include "../include/stateDead.h"

class CellACE110 : public CellACE {
public:
  CellACE110();
  CellACE110(const Position& position, const State& state);
  ~CellACE110();
  int nextState(Lattice& lattice);
  void updateState();
};

#endif