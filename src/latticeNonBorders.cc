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
    
    this->checkNorth = false;
    this->checkSouth = false;
    this->checkWest = false;
    this->checkEast = false;
}

LatticeNonBorders::~LatticeNonBorders(){}

void LatticeNonBorders::nextGenerationSpecific(void) {
    this->expandBorders();
    this->resetExpansionStatus();
}

Cell& LatticeNonBorders::getCell(Position* p){
    int x = p->getX();
    int y = p->getY();
    
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return this->border;
    }

    if (x == 0 || x == row - 1|| y == 0 || y == col - 1) {
        if (lattice[x][y].getStateInt() == 1) {
            this->checkExpandBorders(p);
        }
    }
    return lattice[x][y];
}

void LatticeNonBorders::expandBorders() {
    if (this->checkNorth) {
        this->expandNorth();
    }
    if (this->checkSouth) {
        this->expandSouth();
    }
    if (this->checkWest) {
        this->expandWest();
    }
    if (this->checkEast) {
        this->expandEast();
    }
}

void LatticeNonBorders::checkExpandBorders(Position* p) {
    if (p->getX() == 0) {
        this->checkNorth = true;
    }
    if (p->getX() == this->row - 1) {
        this->checkSouth = true;
    }
    if (p->getY() == 0) {
        this->checkWest = true;
    }
    if (p->getY() == this->col - 1) {
        this->checkEast = true;
    }
}

void LatticeNonBorders::expandNorth() {
    this->lattice.insert(this->lattice.begin(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
}

void LatticeNonBorders::expandSouth() {
    this->lattice.insert(this->lattice.end(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
}

void LatticeNonBorders::expandWest() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].begin(), Cell());
    }
    this->col++;
    this->updatePositions();
}

void LatticeNonBorders::expandEast() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].end(), Cell());
    }
    this->col++;
    this->updatePositions();
}

void LatticeNonBorders::updatePositions() {
    for(int i = 0; i < this->row; i++) {
        for(int j = 0; j < this->col; j++) {
            (*this)[new Position(i, j)].setPosition(new Position(i, j));
        }
    }
}
