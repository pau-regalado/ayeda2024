#include "../include/lattice2D_periodic.h"
#include "../include/stateAlive.h"

Lattice2D_periodic::Lattice2D_periodic(const char* filename, const FactoryCell& f)
  : Lattice2D(filename, f) {
}

Lattice2D_periodic::~Lattice2D_periodic(){ }

// Devuelve la celula en la posicion indicada. periodicBorder no calcula nada
Cell& Lattice2D_periodic::getCell(const Position& position){
  int x = position[0];
  int y = position[1];
  if (x < 0) {
    x = this->row - 1;
  }else if (x >= this->row) {
    x = 0;
  }
  if (y < 0) {
    y = this->col - 1;
  }else if (y >= this->col) {
    y = 0;
  }

  return *this->lattice[x][y];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. periodicBorder no calcula nada
const Cell& Lattice2D_periodic::getCell(const Position& position) const{
  int x = position[0];
  int y = position[1];
  if (x < 0) {
    x = this->row - 1;
  }else if (x >= this->row) {
    x = 0;
  }
  if (y < 0) {
    y = this->col - 1;
  }else if (y >= this->col) {
    y = 0;
  }

  return *this->lattice[x][y];
}