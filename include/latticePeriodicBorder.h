#include "../include/lattice.h"
#include "../include/cell.h"

class LatticePeriodicBorder: public Lattice{
  public:
    LatticePeriodicBorder(int size);
    ~LatticePeriodicBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Periodic";}

};
