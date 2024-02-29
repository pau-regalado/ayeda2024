#include "../include/cell.h"
#include "../include/stateAlive.h"
#include "../include/stateDead.h"
#include "../include/lattice.h"
#include <chrono>
#include <thread>
#include <fstream>

Lattice::Lattice(int row, int col){
  this->buildLattice(row, col);
  this->defaultCell();
}

Lattice::Lattice(std::string filename) {
  std::ifstream file("dataFile/" + filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error al abrir el archivo.");
  }

  int row;
  file >> row;
  int col;
  file >> col;

  this->buildLattice(row, col);

  for (int i = 0; i < row; ++i) {
    std::string line;
    file >> line;
    for (int j = 0; j < col; ++j) {
      State* state;
      if (line[j] == '0') {
        state = new StateDead();
      } else if (line[j] == '1') {
        state = new StateAlive(); 
      } else {
        state = new StateDead();
      }
      Cell cell(new Position(i, j), state);
      this->setCell(new Position(i, j), cell);
    }
  }
}
void Lattice::buildLattice(int row, int col) {
  this->onlyPopulationMode = false;
  this->currentIteration = 0;
  this->row = row;
  this->col = col;
  this->lattice.resize(this->row);
  for (int i = 0; i < this->row; i++) {
    this->lattice[i].resize(this->col);
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j].setPosition(new Position(i, j));
    }
  }
}

void Lattice::defaultCell(void){
  /*
  insertAlive(new Position(4, 4));
  insertAlive(Position(4, 3));
  insertAlive(Position(3, 4));
  insertAlive(Position(5, 5));
  insertAlive(Position(3, 5));
  insertAlive(Position(5, 3));
  insertAlive(Position(0, 0));
  insertAlive(Position(0, 1));
  */
}

void Lattice::insertAlive(Position* p) {
  lattice[p->getX()][p->getY()] = Cell(p, new StateAlive());
}

void Lattice::setCell(const Position* p, Cell& cell) {
  lattice[p->getX()][p->getY()] = cell;
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Cell& Lattice::operator[](const Position* p) {
  return lattice[p->getX()][p->getY()];
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
  this->currentIteration++;
  this->calculateNextGeneration();
  this->nextGenerationSpecific();
  this->print();
}

void Lattice::calculateNextGeneration(void) {
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

void Lattice::nextFiveGenerations(void) {
  for (int i = 0; i < 5; i++) {
    this->nextGeneration();
  }
}

void Lattice::switchOnlyPopulationMode() {
  this->onlyPopulationMode = !this->onlyPopulationMode;
}

void Lattice::saveIntoAFile() {
  std::cout << "Saved lattice into a file!" << std::endl;
}

void Lattice::print() {
  std::cout << "Iteration: " << this->currentIteration << std::endl;
  std::cout << "Population: ";
  std::cout << this->population() << std::endl;
  if (!this->onlyPopulationMode) {
    this->printLattice();
  }
}

int Lattice::population() {
  std::cout << "size: " << this->row << " " << this->row <<std::endl;
  int population = 0;
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      population += this->lattice[i][j].getStateInt();
    }
  }
  return population;
}

void Lattice::printLattice() {
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