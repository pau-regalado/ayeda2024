#include "../include/latticeReflectiveBorder.h"
//#include "../include/cell.h"

LatticeReflectiveBorder::LatticeReflectiveBorder(int size): Lattice(size){}

LatticeReflectiveBorder::~LatticeReflectiveBorder(){}

Cell& LatticeReflectiveBorder::getCell(int position){
  if(position == -1) {
    return this->lattice[0];    
  } else if(position == size) {
    return this->lattice[position - 1];
  }
  return this->lattice[position];
}

const Cell& LatticeReflectiveBorder::getCell(int position) const{
  if(position == -1) {
    return this->lattice[0];    
  } else if(position == size) {
    return this->lattice[position - 1];
  }
  return this->lattice[position];
}

