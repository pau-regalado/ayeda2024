#include "../include/lattice.h"

class LatticeOpenBorder: public Lattice{
  public:
    LatticeOpenBorder(int size);
    ~LatticeOpenBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Open";}

    //std::ostream& operator<<(std::ostream& os);
    virtual void print();
};