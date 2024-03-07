  #ifndef _LATTICE1D_ 
  #define _LATTICE1D_

  #include <iostream>
  #include <vector>
  #include <string>
  #include <chrono>
  #include <thread>

  #include "position.h"
  #include "lattice.h"

  class Lattice1D : public Lattice {
    protected:
      int size; 
      std::vector<Cell> lattice;

    public:
      Lattice1D(const char* filename, const FactoryCell& f);
      ~Lattice1D();

      void buildLattice(std::ifstream& file);

      // virtual Cell& getCell(int) = 0; 
      // virtual const Cell& getCell(int) const = 0;
      // Hacer template method para mostrar Lattice1D y luego tipo
      // virtual std::string getName(void) = 0;
      // void setCell(Position& position, Cell& cell);
      // virtual void nextGenerationSpecific(void) = 0;
      
      int getSize(void){ return size; }
      std::string printLattice();
      void calculateNextGeneration(void);
      void buildLattice(int size);
      void saveLatticeDataIntoAFile(std::ofstream& f);
      std::size_t getPopulation() const;
  };

  #endif
