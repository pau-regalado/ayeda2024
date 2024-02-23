#include "../include/latticePeriodicBorder.h"

LatticePeriodicBorder::LatticePeriodicBorder(int size): Lattice(size){}

LatticePeriodicBorder::~LatticePeriodicBorder(){}

Cell& LatticePeriodicBorder::getCell(int position){
  if (position == -1) {
    return this->lattice[size - 1];
  } else if(position == size) {
    return this->lattice[0];
  }
  return this->lattice[position];
}

const Cell& LatticePeriodicBorder::getCell(int position) const{
  if (position == -1) {
    return this->lattice[position - 1];
  } else if(position == size) {
    return this->lattice[0];
  }
  return this->lattice[position];
}