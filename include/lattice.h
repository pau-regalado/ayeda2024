#ifndef __LATTICE__ 
#define __LATTICE__

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

#include "position.h"
#include "factoryCell.h"

class Cell;
class Lattice{
  protected:

    bool onlyPopulationMode;
    int currentIteration;

  public:
    Lattice(const char* filename, const FactoryCell& f);
    virtual ~Lattice();

    virtual void buildLattice(std::ifstream& file) = 0;

    //virtual void insertAlive(const Position&) = 0;

    void setCell(const Position& p, Cell& cell);
    // void askToInsertCell();

    void print();
    virtual std::string printLattice() = 0;
    virtual std::string printSize() = 0;

    Cell& operator[](const Position&);
    const Cell& operator[](const Position&) const;

    // virtual std::ostream& display(std::ostream&) = 0;

    void nextGeneration();
    void nextFiveGenerations(void);
    void switchOnlyPopulationMode();
    void saveIntoAFile();

    friend std::ostream& operator<<(std::ostream& os, Lattice &g);

    virtual std::size_t getPopulation() const = 0;
    virtual void nextGenerationSpecific(void) = 0;
    virtual void calculateNextGeneration(void) = 0;
    virtual Cell& getCell(const Position& p) = 0;
    virtual const Cell& getCell(const Position& p) const = 0;
    virtual std::string getName(void) = 0;
    virtual void saveLatticeDataIntoAFile(std::ofstream& f) = 0;
};

#endif