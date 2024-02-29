#ifndef __LATTICENONBORDERS__ 
#define __LATTICENONBORDERS__

#include "../include/lattice.h"
#include "../include/cell.h"

class LatticeNonBorders: public Lattice {
  public:
    LatticeNonBorders(int row, int col);
    LatticeNonBorders(std::string filename);
    ~LatticeNonBorders();

    Cell& getCell(Position*);
    const Cell& getCell(Position*) const;
    std::string getName(void){return "Non borders";}

    void nextGenerationSpecific(void);

    void resetExpansionStatus();

    void expandBorders(Position* p);
    void expandNorth();
    void expandSouth();
    void expandWest();
    void expandEast();

    void updatePositions();

    private:
      bool expandedNorth, expandedSouth, expandedWest, expandedEast;
      Cell border;
};

#endif