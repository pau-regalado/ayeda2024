#include "../include/cell.h"
#include "../include/state.h"
#include "../include/lattice.h"
#include <chrono>
#include <thread>

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


Lattice::Lattice(std::vector<int> data){ 
  for(int i = 0; i <= data.size(); i++) {
    if (data[i] == 0) {
      Position position(i);     
      State state(0);  
      lattice[i] = Cell(position, state);
    } else {
      Position position(i);
      State state(1);  
      lattice[i] = Cell(position, state);
    }
  }
}

void Lattice::setCell(Position& position, Cell& cell) {
  lattice[position.getPosition()] = cell;
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Lattice::~Lattice() {
  delete[] lattice;
  std::cout << "Destruccion base" << std::endl;
}

void Lattice::startGeneration(void) {
  bool quit = false;
  this->print();
  
  for(int i = 0; i <= 25; i++) {
    this->nextGeneration();
    print();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

void Lattice::nextGeneration(void) {
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].nextState(*this);  
  }
 
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].updateState();
  }
  
}

void Lattice::print() {
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


