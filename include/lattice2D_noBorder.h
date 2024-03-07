#ifndef _LATTICE2D_NOBORDER_ 
#define _LATTICE2D_NOBORDER_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_noBorder: public Lattice2D {
  public:
    Lattice2D_noBorder(const char* filename, const FactoryCell& f);
    ~Lattice2D_noBorder();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "noBorder";}
    void nextGenerationSpecific(void);
    void resetExpansionStatus();

    void expandBorders(const Position& p);
    void expandNorth();
    void expandSouth();
    void expandWest();
    void expandEast();

    void updatePositions();

    private:
      bool expandedNorth, expandedSouth, expandedWest, expandedEast;
      Cell* border;
};

#endif