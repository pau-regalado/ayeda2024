#include "../include/cellACE.h"
#include "../include/state.h"
#include "../include/lattice1D.h"
#include <chrono>
#include <thread>

Lattice1D::Lattice1D(int size){
  this->size = size;
  this->lattice = new CellACE[size];
  for (int i = 0; i < size; i++) {   
    Position position(i);
    State state(0);  
    lattice[i] = CellACE(position, state);      
  } 
  Position middle(size/2);
  State iniState(1);
  lattice[size/2] = CellACE(middle, iniState);
}


Lattice1D::Lattice1D(std::vector<int> data){ 
  for(int i = 0; i <= data.size(); i++) {
    if (data[i] == 0) {
      Position position(i);     
      State state(0);  
      lattice[i] = CellACE(position, state);
    } else {
      Position position(i);
      State state(1);  
      lattice[i] = CellACE(position, state);
    }
  }
}

void Lattice1D::setCellACE(Position& position, CellACE& CellACE) {
  lattice[position.getPosition()] = CellACE;
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Lattice1D::~Lattice1D() {
  delete[] lattice;
  std::cout << "Destruccion base" << std::endl;
}

void Lattice1D::startGeneration(void) {
  bool quit = false;
  this->print();
  
  for(int i = 0; i <= 25; i++) {
    this->nextGeneration();
    print();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

void Lattice1D::nextGeneration(void) {
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].nextState(*this);  
  }
 
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].updateState();
  }
  
}

void Lattice1D::print() {
  std::cout << "|"; 
  int v = 0, m = 0;
  for (int i = 0; i < this->size; i++) { 
    /*
    if (this->lattice[i].getStateValue() == 1){
        v++;	
      }else if (this->lattice[i].getStateValue() == 0) {
        m++;
	    }  
    */
    std::cout << this->lattice[i];
  }
  std::cout << "|" << std::endl;
  //std::cout << "Vivas: " << v << " Muertas: " << m << std::endl;
}