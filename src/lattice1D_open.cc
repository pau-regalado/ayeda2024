#include "../include/lattice1D_open.h"

Lattice1D_open::Lattice1D_open(int position, int initialCellState): Lattice1D(position){
  Position auxPosition(0);
  State state(initialCellState);
  this->border = Cell(auxPosition, state);
}

Lattice1D_open::~Lattice1D_open(){}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& Lattice1D_open::getCell(int position){
  if(position < 0 || position >= this->size) {
    return this->border;
    std::cout << border << std::endl;
  }
  return this->lattice[position];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& Lattice1D_open::getCell(int position) const{
  if(position < 0 || position >= this->size) {
    return this->border;
  }
  return this->lattice[position];
}