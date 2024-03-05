#ifndef __LATTICE__ 
#define __LATTICE__

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "position.h"
const int DEFAULT_SIZE = 10;

class Cell;
class Lattice{
  protected:
    int row, col; 
    std::vector<std::vector<Cell>> lattice;
    bool onlyPopulationMode;
    int currentIteration;

  public:
    Lattice(int row = DEFAULT_SIZE, int col = DEFAULT_SIZE);
    Lattice(std::string filename);
    ~Lattice();

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
    friend std::ostream& operator<<(std::ostream& os, Lattice &g);
    Cell& operator[](const Position*);

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