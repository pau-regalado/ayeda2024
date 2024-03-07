#ifndef _CELLACE30_ 
#define _CELLACE30_

#include "../include/cellACE.h"

class CellACE30 : public CellACE {
public:
  CellACE30(const Position& position, const State& state);
  ~CellACE30();
  
  int nextState(Lattice& lattice);
};

#endif