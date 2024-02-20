/*#include "../include/latticePeriodicBorder.h"

LatticePeriodicBorder::LatticePeriodicBorder(int size): Lattice(size){}

LatticePeriodicBorder::~LatticePeriodicBorder(){
  delete this->lattice;  
}

// Devuelve la celula en la posicion indicada.
// Si una coordenada toca el borde, se le asigna la posicion del lado opuesto,
// dando efecto de rejilla circular.
Cell& LatticePeriodicBorder::getCell(int size){
  if (size == 0) {
    size = this->size;
  }else if (size == this->size + 1) {
    size = 0;
  }
  return this->lattice[size];
}

const Cell& LatticePeriodicBorder::getCell(int size) const{
  if (size == 0) {
    size = this->size;
  }else if (size == this->size + 1) {
    size = 1;
  }
  return this->lattice[size];
}

void LatticePeriodicBorder::print(void){
  std::cout << this->lattice;
  //contEstados();
}
*/