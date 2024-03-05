#ifndef _CELLLIFE_ 
#define _CELLLIFE_

#include "../include/cell.h"
#include "../include/stateDead.h"
#include "../include/positionDim.h"
class CellLife : public Cell {
private:
  PositionDim<2> position;
  std::vector<PositionDim<2>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1},
                                            { 0, -1},          { 0, 1},
                                            { 1, -1}, { 1, 0}, { 1, 1}};
public:
  CellLife();
  CellLife(const Position& position, const State& state) : Cell(position, state);
  ~CellLife();
  virtual int nextState(Lattice& lattice) = 0;
  virtual void updateState();
  int countAliveNeighbours(Lattice& lattice);
};

#endif

