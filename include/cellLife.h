#ifndef _CELLLIFE_ 
#define _CELLLIFE_

#include "../include/cell.h"
#include "../include/stateDead.h"
#include "../include/positionDim.h"
class CellLife : public Cell {
private:
  std::vector<PositionDim<2>> neighbours = {PositionDim<2>(2, -1, -1), PositionDim<2>(2, -1,  0), PositionDim<2>(2, -1,  1),
                                            PositionDim<2>(2,  0, -1),                            PositionDim<2>(2,  0,  1),
                                            PositionDim<2>(2,  1, -1), PositionDim<2>(2,  1,  0), PositionDim<2>(2,  1,  1)};
                                            
public:
  CellLife(Position& position, State& state);
  ~CellLife();
  // virtual int nextState(Lattice& lattice) = 0;
  int countAliveNeighbours(Lattice& lattice);
};

#endif

