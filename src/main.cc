//#include "../include/latticePeriodicBorder.h"
#include "../include/latticeOpenBorder.h"
#include "../include/cell.h"

int main (void){ 
  
  Lattice* g = new LatticeOpenBorder(20);
  int opt;
  char type;
  bool quit = false;

  while (!quit) {
    //std::cout << "Lattice actual: " << g->getName() << " Size: " << g->getPosition() << std::endl;
    g->print();
    std::cout << "1) Introducir celulas vivas" << std::endl;
    std::cout << "2) Seleccionar Grid" << std::endl;
    std::cout << "3) NextGeneration" << std::endl;
    std::cout << "4) Rellenar con celulas" << std::endl;
    std::cout << "0) Salir" << std::endl;
    std::cout << "opt> ";

    std::cin >> opt;

    std::cout << std::endl;

    switch (opt){
    case 1: {
      //g->insert();
      break;
    }
    case 2: {
      int tam;
      delete g;
      std::cout << "Introduzca su nuevo tamaño: " << std::endl;
      std::cin >> tam;


      std::cout << "Nuevo tipo: ([O]pen | [P]eriodic | [R]eflective)" << std::endl;
      std::cout << "opt> ";

      std::cin >> type;

      std::cout << std::endl;

      switch (type){
      case 'O': {
        g = new LatticeOpenBorder(tam);
        break;
      }
      /*case 'P': {
        g = new LatticePeriodicBorder(tam);
        break;
      }
      case 'R': {
        g = new LatticeReflectiveBorder(tam);
        break;
      }
      */
      default:
        g = new LatticeOpenBorder(tam);
        break;
      }

      break;
    }
    case 3: {
      g->nextGeneration();
      break;
    }
    case 4: {
        //g->defecto();
      break;
    }
    case 0:
      quit = true;
      break;
    }
  }
    if (g != nullptr){
      delete g;
    }
    return 0;
}


