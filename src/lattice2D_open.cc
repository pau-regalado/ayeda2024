#include "../include/lattice2D_open.h"
#include "../include/stateAlive.h"

Lattice2D_open::Lattice2D_open(const char* filename, const FactoryCell& f, int initialCellState = 0)
  : Lattice2D(filename, f) {

  if (initialCellState == 0) {
    this->border = f.createCell(PositionDim<2>(2, 0, 0), StateDead());
  } else if (initialCellState == 1) {
    this->border = f.createCell(PositionDim<2>(2, 0, 0), StateAlive());
  } else {
    throw InvalidCellTypeException();
  }
}

Lattice2D_open::~Lattice2D_open(){
  std::cout << "Destruyo Lattice2D_open" << std::endl; 
}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& Lattice2D_open::getCell(const Position& position){
  if(position[0] < 0 || position[0] >= this->row || position[1] < 0 || position[1] >= this->col) {
    return *this->border;
  }
  return this->lattice[position[0]][position[1]];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& Lattice2D_open::getCell(const Position& position) const{
  if(position[0] < 0 || position[0] >= this->row || position[1] < 0 || position[1] >= this->col) {
    return *this->border;
  }
  return this->lattice[position[0]][position[1]];
}