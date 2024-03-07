#include "../include/lattice1D_open.h"
#include "../include/stateAlive.h"

Lattice1D_open::Lattice1D_open(const char* filename, const FactoryCell& f, int initialCellState = 0)
  : Lattice1D(filename, f) {
  if (initialCellState == 0) {
    this->border = f.createCell(PositionDim<1>(1, 0), StateDead());
  } else if (initialCellState == 1) {
    this->border = f.createCell(PositionDim<1>(1, 0), StateAlive());
  } else {
    throw InvalidCellTypeException();
  }
}

Lattice1D_open::~Lattice1D_open(){
  std::cout << "Destruyo Lattice1D_OPEN" << std::endl; 
}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& Lattice1D_open::getCell(const Position& position){
  if(position[0] < 0 || position[0] >= this->size) {
    return *this->border;
  }
  return this->lattice[position[0]];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& Lattice1D_open::getCell(const Position& position) const{
  if(position[0] < 0 || position[0] >= this->size) {
    return *this->border;
  }
  return this->lattice[position[0]];
}