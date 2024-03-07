#ifndef _CELLACE_ 
#define _CELLACE_

#include "../include/cell.h"
#include "../include/positionDim.h"

class CellACE : public Cell {
private:
  std::vector<PositionDim<1>> neighbours = {{-1}, {1}};
public:
  CellACE(const PositionDim<1>& position, const State& state);
  ~CellACE();
  // virtual int nextState(Lattice& lattice) = 0;
  // virtual void updateState();
  void updateState();
  virtual int nextState(Lattice& lattice) = 0;
  int getLeftNeightbourStateValue(Lattice& lattice);
  int getRightNeightbourStateValue(Lattice& lattice);
};

#endif