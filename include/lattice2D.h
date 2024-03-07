#ifndef __LATTICE__ 
#define __LATTICE__

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "lattice.h"
#include "position.h"

const int DEFAULT_SIZE = 10;

class Cell;

class Lattice2D : public Lattice {
  protected:
    int row, col; 
    std::vector<std::vector<Cell>> lattice;


  public:
    Lattice2D(int row = DEFAULT_SIZE, int col = DEFAULT_SIZE);
    Lattice2D(std::string filename);

    ~Lattice2D();

    void buildLattice(int row, int col);

    void askToInsertCell();
    void insertAlive(Position*);
    virtual Cell& getCell(Position* p) = 0; 
    virtual std::string getName(void) = 0;
    int getRow(void){ return row;}
    int getCol(void){ return col;}

    void setCell(const Position* p, Cell& cell);

    void print();
    void printLattice();
    friend std::ostream& operator<<(std::ostream& os, Lattice2D &g);
    Cell& operator[](const Position*);

    void buildLattice(int row, int col);

    int population();
    void startGeneration(void);
    void nextGeneration(void);
    virtual void nextGenerationSpecific(void) = 0;
    void calculateNextGeneration(void);
    void nextFiveGenerations(void);
    void switchOnlyPopulationMode();
    void saveIntoAFile();
};

#endif