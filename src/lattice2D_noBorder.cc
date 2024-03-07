#include "../include/lattice2D_noBorder.h"
#include "../include/stateAlive.h"

Lattice2D_noBorder::Lattice2D_noBorder(const char* filename, const FactoryCell& f)
  : Lattice2D(filename, f) {
  this->resetExpansionStatus();
  this->border = f.createCell(*(new PositionDim<1>(1, 0)), *(new StateDead()));
}

Lattice2D_noBorder::~Lattice2D_noBorder(){ }

void Lattice2D_noBorder::resetExpansionStatus() {
  this->expandedNorth = false;
  this->expandedSouth = false;
  this->expandedWest = false;
  this->expandedEast = false;
}

void Lattice2D_noBorder::nextGenerationSpecific(void) {
  if (this->expandedNorth || this->expandedSouth || this->expandedWest || this->expandedEast) {
    this->updatePositions();
  }
  this->resetExpansionStatus();
}

Cell& Lattice2D_noBorder::getCell(const Position& p){
  int x = p[0];
  int y = p[1];
  if (x < 0 || x >= row || y < 0 || y >= col) {
    return *this->border;
  }
  if (x == 0 || x == row - 1|| y == 0 || y == col - 1) {
    if (this->lattice[x][y]->getStateInt() == 1) {
      this->expandBorders(p);
    }
  }
  return *this->lattice[x][y];
}

// Deprecated
const Cell& Lattice2D_noBorder::getCell(const Position& p) const {
  return *this->border;
}

void Lattice2D_noBorder::expandBorders(const Position& p) {
  if (!this->expandedNorth && p[0] == 0) {
      this->expandNorth();
      this->expandedNorth = true;
  }
  if (!this->expandedSouth && p[0] == this->row - 1) {
      this->expandSouth();
      this->expandedSouth = true;
  }
  if (!this->expandedWest && p[1] == 0) {
      this->expandWest();
      this->expandedWest = true;
  }
  if (!this->expandedEast && p[1] == this->col - 1) {
      this->expandEast();
      this->expandedEast = true;
  }
}

void Lattice2D_noBorder::expandNorth() {
  this->lattice.insert(this->lattice.begin(), std::vector<Cell*>(
    this->col, 
    this->cellFactory->createCell(*(new PositionDim<2>(2, 0, 0)), *(new StateDead()))
  ));
  this->row++;
}

void Lattice2D_noBorder::expandSouth() {
  this->lattice.insert(this->lattice.end(), std::vector<Cell*>(
    this->col, 
    this->cellFactory->createCell(*(new PositionDim<2>(2, 0, 0)), *(new StateDead()))
  ));
  this->row++;
}

void Lattice2D_noBorder::expandWest() {
  for(int i = 0; i < this->row; i++) {
      this->lattice[i].insert(
        this->lattice[i].begin(),
        this->cellFactory->createCell(*(new PositionDim<2>(2, 0, 0)), *(new StateDead()))
      );
  }
  this->col++;
}

void Lattice2D_noBorder::expandEast() {
  for(int i = 0; i < this->row; i++) {
    this->lattice[i].insert(
      this->lattice[i].end(),
      this->cellFactory->createCell(*(new PositionDim<2>(2, 0, 0)), *(new StateDead()))
    );
  }
  this->col++;
}

void Lattice2D_noBorder::updatePositions() {
  for(int i = 0; i < this->row; i++) {
    for(int j = 0; j < this->col; j++) {
      if (i == 0 || i == row - 1|| j == 0 || j == col - 1) {
        this->lattice[i][j] = this->cellFactory->createCell(*(new PositionDim<2>(2, i, j)), *(new StateDead()));
      }
      this->getCell(PositionDim<2>(2, i, j)).setPosition(*(new PositionDim<2>(2, i, j)));
    }
  }
}