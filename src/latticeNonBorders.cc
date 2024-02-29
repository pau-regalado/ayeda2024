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

void LatticeNonBorders::nextGenerationSpecific(void) {
    std::cout << "LIMPIA" << std::endl;
    this->resetExpansionStatus();
}

Cell& LatticeNonBorders::getCell(Position* p){
    std::cout << "GETCELL" << std::endl;
    int x = p->getX();
    int y = p->getY();
    if (x < 0 || x >= row || y < 0 || y >= col) {
        (x < 0) ? x++ : x;
        (x >= row) ? x = row : x;
        (y < 0) ? y++ : y;
        (y >= col) ? y = col : y;
        this->expandBorders(p);
        Position* pos = new Position(x, y);
        Cell c(pos, new StateDead());
        return c;
    }
    return lattice[x][y];
}

void LatticeNonBorders::expandBorders(Position* p) {
    if (!this->expandedWest && p->getX() < 0) {
        this->expandWest();
        this->expandedWest = true;
    }
    if (!this->expandedEast && p->getX() >= this->col) {
        this->expandEast();
        this->expandedEast = true;
    }
    if (!this->expandedNorth && p->getY() < 0) {
        this->expandNorth();
        this->expandedNorth = true;
    }
    if (!this->expandedSouth && p->getY() >= this->row) {
        this->expandSouth();
        this->expandedSouth = true;
    }
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
