#include "../include/latticePeriodicBorder.h"

LatticePeriodicBorder::LatticePeriodicBorder(int row, int col): Lattice(row, col){}
LatticePeriodicBorder::LatticePeriodicBorder(std::string filename): Lattice(filename){}

LatticePeriodicBorder::~LatticePeriodicBorder(){}

Cell& LatticePeriodicBorder::getCell(Position* p){
  int x = p->getX();
  int y = p->getY();
  if (x < 0) {
    x = this->row - 1;
  }else if (x >= this->row) {
    x = 0;
  }
  if (y < 0) {
    y = this->col - 1;
  }else if (y >= this->col) {
    y = 0;
  }
  return this->lattice[x][y];
  
}

const Cell& LatticePeriodicBorder::getCell(Position* p) const{
  int x = p->getX();
  int y = p->getY();
  if (x < 0) {
    x = this->row - 1;
  }else if (x >= this->row) {
    x = 0;
  }
  if (y < 0) {
    y = this->col - 1;
  }else if (y >= this->col) {
    y = 0;
  }
  return this->lattice[x][y];
}