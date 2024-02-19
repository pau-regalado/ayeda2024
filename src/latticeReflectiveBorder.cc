#include "../include/latticeReflectiveBorder.h"

LatticeReflectiveBorder::LatticeReflectiveBorder(int tam): Lattice(tam){}

// Libera la memoria reservada para la rejilla.
LatticeReflectiveBorder::~LatticeReflectiveBorder(){
  std::cout << "Destruccion ReflectiveBorder" << std::endl;
  for (int i = 0; i < ntam_ + 2; i++){
    delete[] rejilla_[i]; // Libera la memoria de cada vector
  }
  delete rejilla_;        // Libera la memoria reservada para el vertor principal
}

// Devuelve la celula en la posicion indicada.
// Las coordenadas que se encuentran en los bordes, esto es, si alguna o ambas
// de sus coordenadas lo estan, se calcula la posicion de la celula que la esta
// investigando y se devuelve la posicion de esta ultima.
Celula& LatticeReflectiveBorder::getCelula(int tam){
  if (tam == 0){
    tam = 1;
    if (tam == 0) {
      tam = 1;
    } else if (tam == ntam_ + 1) {

    }
  }

  if (y == nctam_ + 1){
    y = ncols_;
    if (x == 0) {
      x = 1;
    } else if (x == nrows_ + 1) {
      x = nrows_;
    }
  }
  return rejilla_[x][y];
}

// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada.
// Las coordenadas que se encuentran en los bordes, esto es, si alguna o ambas
// de sus coordenadas lo estan, se calcula la posicion de la celula que la esta
// investigando y se devuelve la posicion de esta ultima.
const Celula& LatticeReflectiveBorder::getCelula(int tam) const{
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
  return rejilla_[x][y];
}

// Imprime la rejilla por pantalla sin mostrar los bordes reservados para
// evitar el desbordamiento
void LatticeReflectiveBorder::print(void){
  std::cout << std::endl << "TURNO Reflective: " << turno_ << std::endl;
  std::cout << std::endl;

  for (int i = 1; i < ntam_ + 1; i++) {
      std::cout << rejilla_[i];
  }
  std::cout << std::endl << std::endl;
  contEstados();
}