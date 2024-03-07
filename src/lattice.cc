#include "../include/cell.h"
#include "../include/stateAlive.h"
#include "../include/stateDead.h"
#include "../include/lattice.h"
#include <chrono>
#include <thread>
#include <fstream>


Lattice::Lattice(const char* filename, const FactoryCell& f) {
  std::string fl(filename);
  std::ifstream file("dataFile/" + fl);
  if (!file.is_open()) {
    throw std::runtime_error("Error al abrir el archivo.");
  }
  this->filename = fl;
  this->cellFactory = &f;
}


const Cell& Lattice::operator[](const Position& p) const {
  return this->getCell(p);
}

Cell& Lattice::operator[](const Position& p) {
  return this->getCell(p);
}

void Lattice::setCell(const Position& p, Cell& cell) {
  this->getCell(p) = cell;
}

std::ostream& operator<<(std::ostream& os, Lattice &g) {
  g.print();
  return os;
}

Lattice::~Lattice() {
  delete this->cellFactory;
  std::cout << "See you soon!" << std::endl;
}

void Lattice::nextGeneration(void) {
  this->currentIteration++;
  this->calculateNextGeneration();
  this->nextGenerationSpecific();
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
  std::string filename;
  std::cout << "Enter filename> ";
  std::cin >> filename;

  std::ofstream file("saved-simulations/" + filename + ".txt", std::ios::out);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file");
  }

  this->saveLatticeDataIntoAFile(file);
  std::cout << "Saved in: saved-simulations/" + filename + ".txt" << std::endl;
}

void Lattice::print() {
  std::cout <<  "| Iteration: \t" << this->currentIteration;
  std::cout << " | Population: \t" << this->getPopulation();
  std::cout << " | Size: \t" << this->printSize() << " |" << std::endl;

  if (!this->onlyPopulationMode) {
    this->printLattice();
  }
}