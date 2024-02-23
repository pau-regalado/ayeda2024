#include "../include/latticeReflectiveBorder.h"

LatticeReflectiveBorder::LatticeReflectiveBorder(int size): Lattice(size){}

LatticeReflectiveBorder::~LatticeReflectiveBorder(){}

Cell& LatticeReflectiveBorder::getCell(int position){
  if(position < 0) {
    return this->lattice[0];    
  } else if(position >= size) {
    return this->lattice[size - 1];
  }
  return this->lattice[position];
}

const Cell& LatticeReflectiveBorder::getCell(int position) const{
  if(position < 0) {
    return this->lattice[0];    
  } else if(position >= size) {
    return this->lattice[size - 1];
  }
  return this->lattice[position];
}