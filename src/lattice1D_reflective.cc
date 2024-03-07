#include "../include/lattice1D_reflective.h"
#include "../include/stateAlive.h"

Lattice1D_reflective::Lattice1D_reflective(const char* filename, const FactoryCell& f)
  : Lattice1D(filename, f) {
}

Lattice1D_reflective::~Lattice1D_reflective(){
  std::cout << "Destruyo Lattice1D_reflective" << std::endl; 
}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& Lattice1D_reflective::getCell(const Position& position){
  if(position[0] < 0) {
    return *this->lattice[0];
  }
  if(position[0] >= this->size) {
    return *this->lattice[this->size - 1];
  }
  return *this->lattice[position[0]];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& Lattice1D_reflective::getCell(const Position& position) const{
  if(position[0] < 0) {
    return *this->lattice[0];
  }
  if(position[0] >= this->size) {
    return *this->lattice[this->size - 1];
  }
  return *this->lattice[position[0]];
}