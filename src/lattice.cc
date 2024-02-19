#include "../include/cell.h"
#include "../include/state.h"
#include "../include/lattice.h"

Lattice::Lattice(int size){
  this->size = size;
  // Reserva de memoria dinamica de (nrows_ + 2) vectores de celulas y cada
  // uno de ellos realiza lo mismo con (ncols_ + 2), para inicializar toda la
  // matriz a muerta y ademas tener un borde contra desbordamientos
  this->lattice = new Cell[size + 2];
  for (int i = 0; i < size + 2; i++) {   
    lattice[i] = new State(new Position(i));
    latti
  } 
}

// Muestra por pantalla la rejilla, de esta forma podemos implementar el 
// polimorfismo con el operador de insercion
std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

// --------- MODIFICACION -----------

void Lattice::contEstados(void){
  int v = 0, m = 0;
  for(int i = 1; i < ntam_ + 1; i++){
    	if (rejilla_[i].getState()->getState() == A){
	  v++;	
	}else if (rejilla_[i].getState()->getState() == D) {
	  m++;
	}
    
  }
  std::cout << "Vivas: " << v << " Muertas: " << m << std::endl;
}


Lattice::~Lattice(){std::cout << "Destruccion base" << std::endl;}

// Bateria para cargar celulas vivas directamente para probar el codigo
void Lattice::defecto(void){
    rejilla_[1].setState(new StateAlive(&rejilla_[1]));  
}

// Bucle para insertar celulas dentro de la rejilla
void Lattice::insert(void){

  int opt;
  bool quit = false;

  while (!quit) {
    std::cout << "Lattice actual:" << std::endl;
    print();
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

      if (x < ntam_ + 1){
        std::cout << "En que estado? (D | A) : ";
        std::cin >> e;
        switch (e){
        case 'D':
            rejilla_[x].setState(new StateDead(&rejilla_[x]));
          break;
        case 'A':
            rejilla_[x].setState(new StateAlive(&rejilla_[x]));
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

// Lleva la rejilla a la siguiente generacion
// Recorre la matriz una primera vez para que cada celula actualice sus
// vecinas y una segunda vez para transitar a los estados correspondientes
// Vemos que solo se actualizan las celulas de dentro, las que no estan en
// el borde
void Lattice::nextGeneration(void){

  // Actualizamos vecinas vivas
  for (int i = 1; i < ntam_ + 1; i++) {
      rejilla_[i].neighbors(*this);
  }
  for (int i = 1; i < ntam_ + 1; i++) {
      rejilla_[i].updateState();
  }
  turno_++;
  print();
}


