#include "../include/lattice.h"

class LatticePeriodicBorder: public Lattice{
  public:
    LatticePeriodicBorder(int size);
    ~LatticePeriodicBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Periodic";}

    virtual void print();
};