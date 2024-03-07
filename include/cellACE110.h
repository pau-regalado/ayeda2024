#ifndef _CELLACE110_ 
#define _CELLACE110_

#include "../include/cellACE.h"

class CellACE110 : public CellACE {
public:
  CellACE110(Position& position, State& state);
  ~CellACE110();
  
  int nextState(Lattice& lattice);
};

#endif
