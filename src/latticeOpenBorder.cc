#include "../include/latticeOpenBorder.h"

LatticeOpenBorder::LatticeOpenBorder(int tam): Lattice(tam){}

// Libera la memoria reservada para la rejilla
LatticeOpenBorder::~LatticeOpenBorder(){
  std::cout << "Destruccion OpenBorder" << std::endl;
  for (int i = 0; i < ntam_ + 2; i++){
    delete[] rejilla_[i]; // Libera la memoria de cada vector
  }
  delete rejilla_;        // Libera la memoria reservada para el vertor principal
}

// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
Celula& LatticeOpenBorder::getCelula(int tam){
    return rejilla_[tam];
}
// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada. OpenBorder no calcula nada
const Celula& LatticeOpenBorder::getCelula(int tam) const{
  return rejilla_[tam];
}

// Imprime la rejilla por pantalla sin mostrar los bordes reservados para
// evitar el desbordamiento
void LatticeOpenBorder::print(void){
  std::cout << std::endl << "TURNO OPEN: " << turno_ << std::endl;
  std::cout << std::endl;

  for (int i = 1; i < ntam_ + 1; i++) {
      std::cout << rejilla_[i];
  }
  std::cout << std::endl << std::endl;
  contEstados();
}