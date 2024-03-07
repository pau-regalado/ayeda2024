#include "../include/lattice1D_periodic.h"
#include "../include/stateAlive.h"

Lattice1D_periodic::Lattice1D_periodic(const char* filename, const FactoryCell& f)
  : Lattice1D(filename, f) {
}

Lattice1D_periodic::~Lattice1D_periodic(){ }

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Cell& Lattice1D_periodic::getCell(const Position& position){
  if(position[0] < 0) {
    return *this->lattice[this->size - 1];
  }
  if(position[0] >= this->size) {
    return *this->lattice[0];
  }
  return *this->lattice[position[0]];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Cell& Lattice1D_periodic::getCell(const Position& position) const{
  if(position[0] < 0) {
    return *this->lattice[this->size - 1];
  }
  if(position[0] >= this->size) {
    return *this->lattice[0];
  }
  return *this->lattice[position[0]];
}