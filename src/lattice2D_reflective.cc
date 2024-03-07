#include "../include/lattice2D_reflective.h"
#include "../include/stateAlive.h"

Lattice2D_reflective::Lattice2D_reflective(const char* filename, const FactoryCell& f)
  : Lattice2D(filename, f) {
}

Lattice2D_reflective::~Lattice2D_reflective(){
  std::cout << "Destruyo Lattice2D_reflective" << std::endl; 
}

// Devuelve la celula en la posicion indicada. reflectiveBorder no calcula nada
Cell& Lattice2D_reflective::getCell(const Position& position){
  int x = position[0];
  int y = position[1];

  if (x < 0){
    x = 0;
    if (y < 0) {
      y = 0;
    } else if (y >= this->col) {
      y = this->col - 1;
    }
  }
  if (x >= this->row){
    x = this->row - 1;
    if (y < 0) {
      y = 0;
    } else if (y == this->col) {
      y = this->col - 1;
    }
  }
  if (y < 0){
    y = 0;
    if (x < 0) {
      x = 0;
    } else if (x == this->row) {
      x = this->row - 1;
    }
  }
  if (y >= this->col){
    y = this->col - 1;
    if (x < 0) {
      x = 0;
    } else if (x == this->row ) {
      x = this->row - 1;
    }
  }

  return *this->lattice[x][y];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. reflectiveBorder no calcula nada
const Cell& Lattice2D_reflective::getCell(const Position& position) const{
  int x = position[0];
  int y = position[1];

  if (x < 0){
    x = 0;
    if (y < 0) {
      y = 0;
    } else if (y >= this->col) {
      y = this->col - 1;
    }
  }
  if (x >= this->row){
    x = this->row - 1;
    if (y < 0) {
      y = 0;
    } else if (y == this->col) {
      y = this->col - 1;
    }
  }
  if (y < 0){
    y = 0;
    if (x < 0) {
      x = 0;
    } else if (x == this->row) {
      x = this->row - 1;
    }
  }
  if (y >= this->col){
    y = this->col - 1;
    if (x < 0) {
      x = 0;
    } else if (x == this->row ) {
      x = this->row - 1;
    }
  }

  return *this->lattice[x][y];
}