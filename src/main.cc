#include <iostream>
#include <fstream> // Para trabajar con archivos
#include <vector>
#include <stdexcept> // Para manejar excepciones
#include <cstring>
#include "../include/latticePeriodicBorder.h"
#include "../include/latticeOpenBorder.h"
#include "../include/latticeReflectiveBorder.h"
#include "../include/cell.h"

Lattice* createLatticeFromFile(const std::string& filename, char borderType) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error al abrir el archivo.");
    }
    int size;
    file >> size; // Leer el tamaño del vector

    std::vector<int> data(size, 0);
    for (int i = 0; i < size; ++i) {
        char c;
        file >> c;
        if (c == '0' || c == '1') {
            data[i] = c - '0'; // Convertir el carácter a entero
            std::cout << data[i] << std::endl;
        } else {
            throw std::runtime_error("El archivo contiene datos no válidos.");
        }
    }
    return new LatticePeriodicBorder(borderType);
}


int main(int argc, char* argv[]) {
    int size = 20; // Valor por defecto
    char borderType = 'P'; // Valor por defecto
    int borderValue = 0; // Valor por defecto
    int openBorder = 0;
    char* initFile = nullptr; // Valor por defecto

    // Analizar los argumentos de línea de comandos
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-size") == 0 && i + 1 < argc) {
            size = std::stoi(argv[++i]);
        } else if (strcmp(argv[i], "-border") == 0 && i + 1 < argc) {
            borderType = argv[++i][0];
            openBorder = argv[++i][1];
            
        } else if (strcmp(argv[i], "-init") == 0 && i + 1 < argc) {
            initFile = argv[++i];
        }
    }

    Lattice* g;
    if (initFile != nullptr) {
        try {
            g = createLatticeFromFile(initFile, borderType);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    } else {
        // Si no se proporciona un archivo de inicialización, crear un Lattice con el valor por defecto
        switch (borderType) {
            case 'O':
                g = new LatticeOpenBorder(size);
                if (openBorder == 1) {
                  Position auxPosition(0);
                  State state(1);
                  Cell border = Cell(auxPosition, state);
                  g = new LatticeOpenBorder(size);
                } else {
                  Position auxPosition(0);
                  State state(0);
                  Cell border = Cell(auxPosition, state);
                  g = new LatticeOpenBorder(size);
                }
                break;
            case 'P':
                g = new LatticePeriodicBorder(size);
                break;
            case 'R':
                g = new LatticeReflectiveBorder(size);
                break;
            default:
                std::cerr << "Tipo de borde no válido. Usando borde periódico por defecto." << std::endl;
                g = new LatticePeriodicBorder(size);
                break;
        }
    }
    delete g;
    return 0;
}
