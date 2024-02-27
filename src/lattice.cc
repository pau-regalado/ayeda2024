#include "../include/cell.h"
#include "../include/stateAlive.h"
#include "../include/lattice.h"
#include <chrono>
#include <thread>

Lattice::Lattice(int row, int col){
  this->row = row;
  this->col = col;
  this->lattice.resize(this->row);
  for (int i = 0; i < this->row; i++) {
    this->lattice[i].resize(this->col);
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j].setPosition(Position(i, j));
      //std::cout << lattice[i][j].getStateInt() ;
    }
  } 
  this->defaultCell();
}

void Lattice::defaultCell(void){
  insertAlive(Position(4, 4));
  insertAlive(Position(4, 3));
  insertAlive(Position(3, 4));
  insertAlive(Position(5, 5));
  insertAlive(Position(3, 5));
  insertAlive(Position(5, 3));
  insertAlive(Position(0, 0));
  insertAlive(Position(0, 1));
  //insertAlive(Position(1, 0));
  //insertAlive(Position(1, 1));
  //insertAlive(Position(0, 2));
}

void Lattice::insertAlive(Position p) {
  lattice[p.getX()][p.getY()] = Cell(p, new StateAlive());
}

Lattice::Lattice(std::vector<int> data){ 

}

void Lattice::setCell(const Position& p, Cell& cell) {
  lattice[p.getX()][p.getY()] = cell;
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Cell& Lattice::operator[](const Position& p) {
  return lattice[p.getX()][p.getY()];
}

Lattice::~Lattice() {
  std::cout << "Destruccion base" << std::endl;
}

void Lattice::startGeneration(void) {
  bool quit = false;
  this->print();
  
  for(int i = 0; i <= 5; i++) {
    this->nextGeneration();
    print();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void Lattice::nextGeneration(void) {
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j].nextState(*this);  
    }
  }
 
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j].updateState();
    }
  } 
}

void Lattice::print() {
  for (int i = 0; i < this->col + 2; i++){
    std::cout << "⬛";
  }
  std::cout << std::endl;

  for (int i = 0; i < this->row; i++) {
    std::cout << "⬛";
    for (int j = 0; j < this->col; j++) {
      std::cout << this->lattice[i][j];
    }
    std::cout << "⬛" << std::endl;
  }
  
  for (int i = 0; i < this->col + 2; i++){
    std::cout << "⬛";
  }
  std::cout << std::endl << std::endl;
}