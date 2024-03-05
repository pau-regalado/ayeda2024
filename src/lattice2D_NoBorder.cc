#include "../include/lattice2D_NoBorder.h"
#include "../include/stateDead.h"

Lattice2D_NoBorder::Lattice2D_NoBorder(int row, int col) : Lattice(row, col) {
    this->resetExpansionStatus();
}

Lattice2D_NoBorder::Lattice2D_NoBorder(std::string filename) : Lattice(filename) {
    this->resetExpansionStatus();
}

void Lattice2D_NoBorder::resetExpansionStatus() {
    this->expandedNorth = false;
    this->expandedSouth = false;
    this->expandedWest = false;
    this->expandedEast = false;
    
    this->checkNorth = false;
    this->checkSouth = false;
    this->checkWest = false;
    this->checkEast = false;
}

Lattice2D_NoBorder::~LatticeNonBorders(){}

void LatticeNonBorders::nextGenerationSpecific(void) {
    this->expandBorders();
    this->resetExpansionStatus();
}

Cell& Lattice2D_NoBorder::getCell(Position* p){
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

void Lattice2D_NoBorder::expandBorders() {
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

void Lattice2D_NoBorder::checkExpandBorders(Position* p) {
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

void Lattice2D_NoBorder::expandNorth() {
    this->lattice.insert(this->lattice.begin(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
}

void Lattice2D_NoBorder::expandSouth() {
    this->lattice.insert(this->lattice.end(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
}

void Lattice2D_NoBorder::expandWest() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].begin(), Cell());
    }
    this->col++;
    this->updatePositions();
}

void Lattice2D_NoBorder::expandEast() {
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].end(), Cell());
    }
    this->col++;
    this->updatePositions();
}

void Lattice2D_NoBorder::updatePositions() {
    for(int i = 0; i < this->row; i++) {
        for(int j = 0; j < this->col; j++) {
            (*this)[new Position(i, j)].setPosition(new Position(i, j));
        }
    }
}
