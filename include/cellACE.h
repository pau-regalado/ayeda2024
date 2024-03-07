#ifndef _CELLACE_ 
#define _CELLACE_

#include "../include/positionDim.h"
#include "../include/cell.h"
// #include "../include/lattice.h"

// class Lattice;

class CellACE : public Cell {
private:
  std::vector<PositionDim<1>> neighbours = {{-1}, {1}};
public:
  CellACE(const Position& position, const State& state);
  ~CellACE();

  // virtual int nextState(Lattice& lattice) = 0;
  int getLeftNeightbourStateValue(Lattice& lattice);
  int getRightNeightbourStateValue(Lattice& lattice);
};

#endif