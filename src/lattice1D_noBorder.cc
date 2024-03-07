#include "../include/lattice1D_noBorder.h"
#include "../include/stateAlive.h"

Lattice1D_noBorder::Lattice1D_noBorder(const char* filename, const FactoryCell& f)
  : Lattice1D(filename, f) {
  this->border = f.createCell(*(new PositionDim<1>(1, 0)), *(new StateDead()));
  this->resetExpansionStatus();
}

Lattice1D_noBorder::~Lattice1D_noBorder(){ }

void Lattice1D_noBorder::resetExpansionStatus() {
  this->expandedWest = false;
  this->expandedEast = false;
}

void Lattice1D_noBorder::nextGenerationSpecific(void) {
  this->resetExpansionStatus();
  this->updatePositions();
}

Cell& Lattice1D_noBorder::getCell(const Position& position) {
  int x = position[0];
  if (x < 0 || x >= this->size) {
      return *this->border;
  }
  if (x == 0 || x == this->size - 1) {
    if (this->lattice[x]->getStateInt() == 1) {
      this->expandBorders(position);
    }
  }
  return *this->lattice[x];
}

const Cell& Lattice1D_noBorder::getCell(const Position& position) const {
  return *this->border;
}

void Lattice1D_noBorder::expandBorders(const Position& p) {
  if (!this->expandedWest && p[0] == 0) {
      this->expandWest();
      this->expandedWest = true;
  }
  if (!this->expandedEast && p[0] == this->size - 1) {
      this->expandEast();
      this->expandedEast = true;
  }
}

void Lattice1D_noBorder::expandWest() {
  PositionDim<1> p(1, 0);
  StateDead s;
  this->lattice.insert(this->lattice.begin(), this->cellFactory->createCell(p, s));
  this->size++;
  this->updatePositions();
}

void Lattice1D_noBorder::expandEast() {
  PositionDim<1> p(1, this->size);
  StateDead s;
  this->lattice.insert(this->lattice.end(), this->cellFactory->createCell(p, s));
  this->size++;
  this->updatePositions();
}

void Lattice1D_noBorder::updatePositions() {
  for(int i = 0; i < this->size; i++) {
    this->getCell(PositionDim<1>(1, i)).setPosition(*(new PositionDim<1>(1, i)));
  }
}