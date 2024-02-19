#include "../include/latticePeriodicBorder.h"

LatticePeriodicBorder::LatticePeriodicBorder(int tam): Lattice(tam){}

// Libera la memoria reservada para la rejilla.
LatticePeriodicBorder::~LatticePeriodicBorder(){
  std::cout << "Destruccion PeriodicBorder" << std::endl;
  for (int i = 0; i < ntam_ + 2; i++){
    delete[] rejilla_[i]; // Libera la memoria de cada vector
  }
  delete rejilla_;        // Libera la memoria reservada para el vertor principal
}

// Devuelve la celula en la posicion indicada.
// Si una coordenada toca el borde, se le asigna la posicion del lado opuesto,
// dando efecto de rejilla circular.
Celula& LatticePeriodicBorder::getCelula(int tam){
  if (tam == 0) {
    tam = ntam_;
  }else if (tam == ntam_ + 1) {
    tam = 0;
  }
  return rejilla_[tam];
}

// Getter constante, se usa en la mayoria del codigo
// Devuelve la celula en la posicion indicada.
// Si una coordenada toca el borde, se le asigna la posicion del lado opuesto,
// dando efecto de rejilla circular.
const Celula& LatticePeriodicBorder::getCelula(int tam) const{
  if (tam == 0) {
    tam = ntam_;
  }else if (tam == ntam_ + 1) {
    tam = 1;
  }
  return rejilla_[tam];
}

// Imprime la rejilla por pantalla sin mostrar los bordes reservados para
// evitar el desbordamiento
void LatticePeriodicBorder::print(void){
  std::cout << std::endl << "TURNO PERIODIC: " << turno_ << std::endl;
  std::cout << std::endl;

  for (int i = 1; i < ntam_ + 1; i++) {
      std::cout << rejilla_[i];
  }

  std::cout << std::endl << std::endl;
  contEstados();
}