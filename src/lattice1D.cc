#include "../include/cellACE.h"
#include "../include/state.h"
#include "../include/lattice1D.h"
#include "../include/positionDim.h"
#include "../include/stateAlive.h"
#include <chrono>
#include <thread>

/*Lattice1D::Lattice1D(int size){
  this->size = size;
  this->lattice = new CellACE[size];
  for (int i = 0; i < size; i++) {   
    PositionDim<1> position(i);
    State state(0);  
    lattice[i] = CellACE(position, state);      
  } 
  PositionDim<1> middle(size/2);
  State iniState(1);
  lattice[size/2] = CellACE(middle, iniState);
}*/

Lattice1D::Lattice1D(const char* filename, const FactoryCell& f){ 
  std::string fl(filename);
  std::ifstream file("dataFile/" + fl);
  if (!file.is_open()) {
    throw std::runtime_error("Error al abrir el archivo.");
  }

  int size;
  file >> size;
  this->buildLattice(size);

  for (int i = 0; i < size; ++i) {
    std::string line;
    file >> line;
    State* state;
    if (line[i] == '0') {
      state = new StateDead();                        
    } else if (line[i] == '1') {
      state = new StateAlive(); 
    }
    CellACE cell(PositionDim<1>(i), *state);

    this->setCell(new PositionDim<1>(i), cell);
  }
}

void Lattice1D::buildLattice(int size) {
  this->onlyPopulationMode = false;
  this->currentIteration = 0;
  this->size = size;
  this->lattice.resize(this->size);
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].setPosition(new PositionDim<1>(i));
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

void Lattice::insertAlive(Position* p) {
  lattice[p] = Cell(p, new StateAlive());
}

void Lattice::askToInsertCell() {
  int pos;
  std::cout << "Enter the position (row column) to insert a live cell: ";
  std::cin >> pos;
  if (pos < 0 || pos >= size) {
    std::cout << "Invalid position." << std::endl;
  } else {
    PositionDim<1> position(pos);
    insertAlive(&position);
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

int Lattice::population() {
  int population = 0;
  for (int i = 0; i < this->size; i++) {
      population += this->lattice[i].getStateInt();
  }
  return population;
}

void Lattice1D::print() {
  std::cout << "|"; 
  int v = 0, m = 0;
  for (int i = 0; i < this->size; i++) { 
    std::cout << this->lattice[i];
  }
  std::cout << "|" << std::endl;
}