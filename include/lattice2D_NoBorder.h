#ifndef _LATTICE2D_NOBORDER_ 
#define _LATTICE2D_NOBORDER_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_NoBorder: public Lattice2D {
  public:
    Lattice2D_NoBorder(int row, int col): Lattice2D(){}
    ~Lattice2D_NoBorder(){}
    Lattice2D_NoBorder(std::string filename);

    Cell& getCell(Position*);
    const Cell& getCell(Position*) const;
    std::string getName(void){return "Non borders";}

    void nextGenerationSpecific(void);

    void resetExpansionStatus();
    void checkExpandBorders(Position* p);
    void expandBorders();
    void expandNorth();
    void expandSouth();
    void expandWest();
    void expandEast();

    void updatePositions();

    private:
      bool expandedNorth, expandedSouth, expandedWest, expandedEast; 
      bool checkNorth, checkSouth, checkWest, checkEast;
      //Cell border;
};

#endif