#ifndef _LATTICE1D_ 
#define _LATTICE1D_

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "position.h"

const int DEFAULT_SIZE = 10;

class Cell;

class Lattice1D {
  protected:
    int size; 
    Cell* lattice;

  public:
    Lattice1D(int size = DEFAULT_SIZE);
    Lattice1D(std::vector<int> data);
    ~Lattice1D();

    virtual Cell& getCell(int) = 0; 
    virtual const Cell& getCell(int) const = 0;
    virtual std::string getName(void) = 0;
    int getTam(void){ return size;}

    void setCell(Position& position, Cell& cell);

    void print();
    friend std::ostream& operator<<(std::ostream& os, Lattice1D &g);

    void startGeneration(void);
    void nextGeneration(void);

    void contEstados(void);
};

#endif
