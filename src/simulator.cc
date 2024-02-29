#include "../include/simulator.h"

Simulator::Simulator(Lattice* lattice) {
  this->lattice = lattice;
}

Simulator::~Simulator() {
  delete this->lattice;
}

void Simulator::start() {
  char opt;
  char type;
  bool quit = false;

  while (!quit) {
    this->lattice->print();
    switch (this->showMenuAndAskForOption()){
    case 'n': {
      lattice->nextGeneration();
    break;
    }
    case 'L': {
      lattice->nextFiveGenerations();
    break;
    }
    case 'c': {
      lattice->switchOnlyPopulationMode();
    break;
    }
    case 's': {
      lattice->saveIntoAFile();
    break;
    }
    case 'i': {
      lattice->askToInsertCell();
    break;
    }
    case 'x':
      quit = true;
    break;
    }
  }
}

char Simulator::showMenuAndAskForOption() {
  char opt = 0;
  std::cout << "n) [n]ext generation" << std::endl;
  std::cout << "L) Next 5 generations" << std::endl;
  std::cout << "c) Switch only population mode" << std::endl;
  std::cout << "s) Save lattice" << std::endl;
  std::cout << "i) Insert a cell" << std::endl;
  std::cout << "opt> ";

  std::cin >> opt;
  std::cout << std::endl;
  return opt;
}