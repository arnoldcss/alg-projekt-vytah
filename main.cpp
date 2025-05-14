/**
 * @file main.cpp
 * @brief Hlavní soubor pro simulaci výtahového systému
 */

#include "ElevatorSystem.h"
#include <iostream>
#include <string>

/**
 * @brief Hlavní funkce programu
 * 
 * @param argc Počet argumentů příkazové řádky
 * @param argv Pole argumentů příkazové řádky
 * @return int Návratový kód programu
 */
int main(int argc, char* argv[]) {
    // Kontrola argumentů příkazové řádky
    if (argc != 2) {
        std::cerr << "Použití: " << argv[0] << " <vstupní_soubor>" << std::endl;
        return 1;
    }
    
    std::string inputFile = argv[1];
    
    // Vytvoření instance třídy ElevatorSystem
    ElevatorSystem elevator;
    
    // Načtení součástek ze vstupního souboru
    if (!elevator.loadComponentsFromFile(inputFile)) {
        std::cerr << "Chyba při načítání součástek ze souboru." << std::endl;
        return 1;
    }
    
    // Spuštění triviální simulace
    int trivialTime = elevator.runTrivialSimulation();
    
    // Spuštění optimalizované simulace
    int optimizedTime = elevator.runOptimizedSimulation();
    
    // Zobrazení výsledků
    elevator.displayResults(trivialTime, optimizedTime);
    
    return 0;
}
