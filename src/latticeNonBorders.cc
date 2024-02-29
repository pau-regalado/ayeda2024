#include "../include/latticeNonBorders.h"
#include "../include/stateDead.h"

LatticeNonBorders::LatticeNonBorders(int row, int col) : Lattice(row, col) {
    this->resetExpansionStatus();
    this->border = Cell(new Position(0, 0), new StateDead());
}

LatticeNonBorders::LatticeNonBorders(std::string filename) : Lattice(filename) {
    this->resetExpansionStatus();
    this->border = Cell(new Position(0, 0), new StateDead());
}

void LatticeNonBorders::resetExpansionStatus() {
    this->expandedNorth = false;
    this->expandedSouth = false;
    this->expandedWest = false;
    this->expandedEast = false;
}

LatticeNonBorders::~LatticeNonBorders(){}

void LatticeNonBorders::nextGenerationSpecific(void) {
    std::cout << "LIMPIA" << std::endl;
    this->resetExpansionStatus();
}

Cell& LatticeNonBorders::getCell(Position* p){
    std::cout << "GETCELL" << std::endl;
    int x = p->getX();
    int y = p->getY();
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return this->border;
    }
    if (x == 0 || x == row - 1|| y == 0 || y == col - 1) {
        if (lattice[x][y].getStateInt() == 1) {
            this->expandBorders(p);
        }
    }
    return lattice[x][y];
}

void LatticeNonBorders::expandBorders(Position* p) {
    if (!this->expandedNorth && p->getX() == 0) {
        this->expandNorth();
        this->expandedNorth = true;
    }
    if (!this->expandedSouth && p->getX() == this->row - 1) {
        this->expandSouth();
        this->expandedSouth = true;
    }
    if (!this->expandedWest && p->getY() == 0) {
        this->expandWest();
        this->expandedWest = true;
    }
    if (!this->expandedEast && p->getY() == this->col - 1) {
        this->expandEast();
        this->expandedEast = true;
    }
    std::cout << "SALGO" << std::endl;
}

void LatticeNonBorders::expandNorth() {
    std::cout << "EXPAND NORTH" << std::endl;
    this->lattice.insert(this->lattice.begin(), std::vector<Cell>(this->col));
    this->row++;
    this->updatePositions();
    std::cout << "EXPAND NORTH CHECK" << std::endl;
    //this->updateNorth();
}

void LatticeNonBorders::expandSouth() {
    std::cout << "EXPAND SOUTH" << std::endl;
    this->lattice.insert(this->lattice.end(), std::vector<Cell>(this->col));
    //this->updateSouth();
    this->row++;
    this->updatePositions();
    std::cout << "EXPAND SOUTH CHECK" << std::endl;
}

void LatticeNonBorders::expandWest() {
    std::cout << "EXPAND WEST" << std::endl;
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].begin(), Cell());
    }
    //this->updateWest();
    this->col++;
    this->updatePositions();
    std::cout << "EXPAND WEST CHECK" << std::endl;
}

void LatticeNonBorders::expandEast() {
    std::cout << "EXPAND EAST" << std::endl;
    for(int i = 0; i < this->row; i++) {
        this->lattice[i].insert(this->lattice[i].end(), Cell());
    }
    //this->updateWest();
    this->col++;
    this->updatePositions();
    std::cout << "EXPAND EAST CHECK" << std::endl;
}

void LatticeNonBorders::updatePositions() {
    for(int i = 0; i < this->row; i++) {
        for(int j = 0; j < this->col; j++) {
            (*this)[new Position(i, j)].setPosition(new Position(i, j));
        }
    }
}
