#ifndef _LATTICE1D_NOBORDER_ 
#define _LATTICE1D_NOBORDER_

#include <iostream>
#include "lattice1D.h"

class Lattice1D_noBorder: public Lattice1D {
  public:
    Lattice1D_noBorder(const char* filename, const FactoryCell& f);
    ~Lattice1D_noBorder();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "Open";}
    void nextGenerationSpecific(void);

    void resetExpansionStatus();

    void expandBorders(const Position& p);
    void expandWest();
    void expandEast();

    void updatePositions();

    private:
      bool expandedWest, expandedEast;
      Cell* border;
};

#endif