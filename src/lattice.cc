#include "../include/cell.h"
#include "../include/state.h"
#include "../include/lattice.h"

Lattice::Lattice(int size){
  this->size = size;
  this->lattice = new Cell[size];
  for (int i = 0; i < size; i++) {   
    Position position(i);
    State state(0);  
    lattice[i] = Cell(position, state);      
  } 
  Position middle(size/2);
  State iniState(1);
  lattice[size/2] = Cell(middle, iniState);
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Lattice::~Lattice() {
  delete[] lattice;
  std::cout << "Destruccion base" << std::endl;
}
/*
// Bucle para insertar celulas dentro de la rejilla
void Lattice::insert(void){

  int opt;
  bool quit = false;

  while (!quit) {
    std::cout << "Lattice actual:" << std::endl;
    //print();
    std::cout << "1) Introducir celula viva" << std::endl;
    std::cout << "2) Terminar" << std::endl;
    std::cout << "opt> ";

    std::cin >> opt;

    std::cout << std::endl;

    switch (opt){
    case 1: {
      int x;
      char e;
      std::cout << "x: ";
      std::cin >> x;

      if (x < this->size + 1){
        std::cout << "En que estado? (D | A) : ";
        std::cin >> e;
        switch (e){
        case 'D':
            this->lattice[x].setState(" ");
          break;
        case 'A':
            this->lattice[x].setState(new StateAlive(&this->lattice[x]));
          break;        
        default:
          std::cout << "Error. Estado desconocido" << std::endl;
          break;
        }
      } else
        std::cout << "Posicion invalida";
        std::cout << std::endl;
        break;
    }
    case 2: 
      quit = true;
    }
  }
}
*/

// Lleva la rejilla a la siguiente generacion
// Recorre la matriz una primera vez para que cada celula actualice sus
// vecinas y una segunda vez para transitar a los estados correspondientes
// Vemos que solo se actualizan las celulas de dentro, las que no estan en
// el borde
void Lattice::nextGeneration(void){
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].nextState(*this);
  }
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].updateState();
  }
  print();
}

void Lattice::print() {
  for (int i = 0; i < this->size; i++) {   
    std::cout << this->lattice[i];
  }
  std::cout << std::endl;
}

/*
// --------- MODIFICACION -----------

void Lattice::contEstados(void){
  int v = 0, m = 0;
  for(int i = 1; i < this->size + 1; i++){
    	if (this->lattice[i].getState()->getState() == A){
	  v++;	
	}else if (this->lattice[i].getState()->getState() == D) {
	  m++;
	}    
  }
  std::cout << "Vivas: " << v << " Muertas: " << m << std::endl;
}

*/


