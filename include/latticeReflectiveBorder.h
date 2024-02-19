#include "../include/lattice.h"

class LatticeReflectiveBorder: public Lattice{
  public:
    LatticeReflectiveBorder(int size);
    ~LatticeReflectiveBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Reflective";}

    //std::ostream& operator<<(std::ostream& os);
    virtual void print();
};