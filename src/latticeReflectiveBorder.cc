#include "../include/latticeReflectiveBorder.h"

LatticeReflectiveBorder::LatticeReflectiveBorder(int row, int col): Lattice(row, col){}
LatticeReflectiveBorder::LatticeReflectiveBorder(std::string filename): Lattice(filename){}

LatticeReflectiveBorder::~LatticeReflectiveBorder(){}

Cell& LatticeReflectiveBorder::getCell(Position* p){
  int x = p->getX();
  int y = p->getY();
  if (x < 0){
    x = 0;
    if (y < 0) {
      y = 0;
    } else if (y >= this->col) {
      y = this->col - 1;
    }
  }
  if (x >= this->row){
    x = this->row - 1;
    if (y < 0) {
      y = 0;
    } else if (y == this->col) {
      y = this->col - 1;
    }
  }
  if (y < 0){
    y = 0;
    if (x < 0) {
      x = 0;
    } else if (x == this->row) {
      x = this->row - 1;
    }
  }
  if (y >= this->col){
    y = this->col - 1;
    if (x < 0) {
      x = 0;
    } else if (x == this->row ) {
      x = this->row - 1;
    }
  }
  //std::cout << y << x;
  return this->lattice[x][y];
}

const Cell& LatticeReflectiveBorder::getCell(Position* p) const{
  int x = p->getX();
  int y = p->getY();
  if (x < 0){
    x = 0;
    if (y < 0) {
      y = 0;
    } else if (y >= this->col) {
      y = this->col - 1;
    }
  }
  if (x >= this->row){
    x = this->row - 1;
    if (y < 0) {
      y = 0;
    } else if (y == this->col) {
      y = this->col - 1;
    }
  }
  if (y < 0){
    y = 0;
    if (x < 0) {
      x = 0;
    } else if (x == this->row) {
      x = this->row - 1;
    }
  }
  if (y >= this->col){
    y = this->col - 1;
    if (x < 0) {
      x = 0;
    } else if (x == this->row ) {
      x = this->row - 1;
    }
  }
  return this->lattice[x][y];
}