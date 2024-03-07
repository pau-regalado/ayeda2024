#ifndef __LATTICE_2D__ 
#define __LATTICE_2D__

#include "lattice.h"
#include "cell.h"

class Lattice2D : public Lattice {
  protected:
    int row, col; 
    std::vector<std::vector<Cell>> lattice;

  public:
    Lattice2D(const char* filename, const FactoryCell& f);
    ~Lattice2D();

    void buildLattice(std::ifstream& file);
    
    std::string getName(void) { return "Lattice 2D"; }
    int getRow(void){ return row;}
    int getCol(void){ return col;}

    std::string printSize() { return std::to_string(row) + " x " + std::to_string(col); }
    std::string printLattice();

    void calculateNextGeneration(void);
    void saveLatticeDataIntoAFile(std::ofstream& f);
    std::size_t getPopulation() const;
};

#endif