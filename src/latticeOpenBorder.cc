#include "../include/latticeOpenBorder.h"

LatticeOpenBorder::LatticeOpenBorder(int position, int initialCellState): Lattice(position){
  Position auxPosition(0);
  State state(initialCellState);
  this->border = Cell(auxPosition, state);
}

LatticeOpenBorder::~LatticeOpenBorder(){}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& LatticeOpenBorder::getCell(int position){
  if(position < 0 || position >= this->size) {
    return this->border;
    std::cout << border << std::endl;
  }
  return this->lattice[position];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& LatticeOpenBorder::getCell(int position) const{
  if(position < 0 || position >= this->size) {
    return this->border;
  }
  return this->lattice[position];
}