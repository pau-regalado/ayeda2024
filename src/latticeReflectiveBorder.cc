/*#include "../include/latticeReflectiveBorder.h"

LatticeReflectiveBorder::LatticeReflectiveBorder(int size): Lattice(size){}

LatticeReflectiveBorder::~LatticeReflectiveBorder(){
    delete this->lattice;     
}

Cell& LatticeReflectiveBorder::getCell(int size){
  if (size == 0){
    size = 1;
    if (size == 0) {
      size = 1;
    } else if (size == this->size + 1) {

    }
  }

  if (y == ncsize_ + 1){
    y = ncols_;
    if (x == 0) {
      x = 1;
    } else if (x == nrows_ + 1) {
      x = nrows_;
    }
  }
  return this->lattice[x][y];
}


const Cell& LatticeReflectiveBorder::getCell(int size) const{
  if (x == 0){
    x = 1;
    if (y == 0) {
      y = 1;
    } else if (y == ncols_ + 1) {
      y = ncols_;
    }
  }


  if (y == ncols_ + 1){
    y = ncols_;
    if (x == 0) {
      x = 1;
    } else if (x == nrows_ + 1) {
      x = nrows_;
    }
  }
  return this->lattice[x][y];
}

void LatticeReflectiveBorder::print(void){
  std::cout << this->lattice[i];
  //contEstados();
}
*/