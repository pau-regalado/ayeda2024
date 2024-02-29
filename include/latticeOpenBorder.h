#ifndef __LATTICEOPENBORDER__ 
#define __LATTICEOPENBORDER__

#include "../include/lattice.h"
#include "../include/cell.h"

class LatticeOpenBorder: public Lattice{
  public:
    LatticeOpenBorder(int row, int col, int initialCellState = 0);
    LatticeOpenBorder(std::string filename, int initialCellState = 0);
    ~LatticeOpenBorder();

    Cell& getCell(Position*);
    const Cell& getCell(Position*) const;
    std::string getName(void){return "Open";}

    void nextGenerationSpecific(void) {}

    private:
      Cell* border;
};

#endif