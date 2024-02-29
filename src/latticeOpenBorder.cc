#include "../include/latticeOpenBorder.h"
#include "../include/stateAlive.h"
#include "../include/stateDead.h"

LatticeOpenBorder::LatticeOpenBorder(int row, int col, int initialCellState) : Lattice(row, col) {
    State* state = nullptr;
    if (initialCellState == 0) {
        state = new StateDead();
    } else {
        state = new StateAlive();
    }
    this->border = new Cell(new Position(0, 0), state);
}

LatticeOpenBorder::LatticeOpenBorder(std::string filename, int initialCellState) : Lattice(filename) {
    State* state = nullptr;
    if (initialCellState == 0) {
        state = new StateDead();
    } else {
        state = new StateAlive();
    }
    this->border = new Cell(new Position(0, 0), state);
}

LatticeOpenBorder::~LatticeOpenBorder(){}

Cell& LatticeOpenBorder::getCell(Position* p){
  int x = p->getX();
  int y = p->getY();
  if (x < 0 || x >= row || y < 0 || y >= col) {
      return *border;
  }
  return lattice[x][y];
}

const Cell& LatticeOpenBorder::getCell(Position* position) const{
  if (position->getX() < 0 || position->getX() >= row || position->getY() < 0 || position->getY() >= col) {
      return *border;
  }
  return lattice[position->getX()][position->getY()];
}