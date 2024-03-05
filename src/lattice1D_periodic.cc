#include "../include/lattice1D_periodic.h"

Lattice1D_periodic::Lattice1D_periodic(int size): Lattice1D(size){}

Lattice1D_periodic::~Lattice1D_periodic(){}

Cell& Lattice1D_Periodic::getCell(int position){
  if (position == -1) {
    return this->lattice[size - 1];
  } else if(position == size) {
    return this->lattice[0];
  }
  return this->lattice[position];
}

const Cell& Lattice1D_periodic::getCell(int position) const{
  if (position == -1) {
    return this->lattice[position - 1];
  } else if(position == size) {
    return this->lattice[0];
  }
  return this->lattice[position];
}