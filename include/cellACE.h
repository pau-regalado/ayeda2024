#ifndef _CELLACE_ 
#define _CELLACE_

#include "../include/cell.h"
#include "../include/stateDead.h"
#include "../include/positionDim.h"

class CellACE : public Cell {
private:
  PositionDim<1>* position;
public:
  CellACE(const PositionDim<1>& position, const State& state);
  ~CellACE();
  virtual int nextState(Lattice& lattice) = 0;
  virtual void updateState();
};

#endif