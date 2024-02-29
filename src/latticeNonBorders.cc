#include "../include/latticeNonBorders.h"
#include "../include/stateDead.h"

LatticeNonBorders::LatticeNonBorders(int row, int col) : Lattice(row, col) {
    this->resetExpansionStatus();
}

LatticeNonBorders::LatticeNonBorders(std::string filename) : Lattice(filename) {
    this->resetExpansionStatus();
}

void LatticeNonBorders::resetExpansionStatus() {
    this->expandedNorth = false;
    this->expandedSouth = false;
    this->expandedWest = false;
    this->expandedEast = false;
}

LatticeNonBorders::~LatticeNonBorders(){}

void LatticeNonBorders::nextGeneration(void) {
  this->currentIteration++;
  this->calculateNextGeneration();
  this->resetExpansionStatus();
  this->print();
}

Cell& LatticeNonBorders::getCell(Position p){
    int x = p.getX();
    int y = p.getY();
    if (x < 0 || x >= row || y < 0 || y >= col) {
        (x < 0) ? x++ : x;
        (x >= row) ? x = row : x;
        (y < 0) ? y++ : y;
        (y >= col) ? y = col : y;
        this->expandBorders(p);
        Position pos(x, y);
        Cell c(pos, new StateDead());
        return c;
    }
    return lattice[x][y];
}

void LatticeNonBorders::expandBorders(Position p) {
    if (!this->expandedWest && p.getX() < 0) {
        this->expandWest();
    }
    if (!this->expandedEast && p.getX() >= this->col) {
        this->expandEast();
    }
    if (!this->expandedNorth && p.getY() < 0) {
        this->expandNorth();
    }
    if (!this->expandedSouth && p.getY() >= this->row) {
        this->expandSouth();
    }
}

void LatticeNonBorders::expandNorth() {
    this->lattice.insert(this->lattice.begin(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
    //this->updateNorth();
}

void LatticeNonBorders::expandSouth() {
    this->lattice.insert(this->lattice.end(), std::vector<Cell>(this->col));
    //this->updateSouth();
    this->row++;
    this->updatePositions();
}

void LatticeNonBorders::expandWest() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].begin(), Cell());
    }
    //this->updateWest();
    this->col++;
    this->updatePositions();
}

void LatticeNonBorders::expandEast() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].end(), Cell());
    }
    //this->updateWest();
    this->col++;
    this->updatePositions();
}

void LatticeNonBorders::updatePositions() {
    for(int i = 0; i < this->row; i++) {
        for(int j = 0; j < this->col; j++) {
            (*this)[Position(i, j)].setPosition(Position(i, j));
        }
    }
}

const Cell& LatticeNonBorders::getCell(Position position) const{
    int x = p.getX();
    int y = p.getY();
    if (x < 0 || x >= row || y < 0 || y >= col) {
        (x < 0) ? x++ : x;
        (x >= row) ? x = row : x;
        (y < 0) ? y++ : y;
        (y >= col) ? y = col : y;
        this->expandBorders(p);
        Position pos(x, y);
        Cell c(pos, new StateDead());
        return c;
    }
    return lattice[x][y];
}