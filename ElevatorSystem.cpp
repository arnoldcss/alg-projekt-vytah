/**
 * @file ElevatorSystem.cpp
 * @brief Implementace třídy ElevatorSystem
 */

#include "ElevatorSystem.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

bool ElevatorSystem::loadComponentsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Chyba: Nelze otevřít soubor " << filename << std::endl;
        return false;
    }
    
    int totalComponents;
    file >> totalComponents;
    
    components.clear();
    components.reserve(totalComponents);
    
    int floor;
    while (file >> floor && components.size() < static_cast<size_t>(totalComponents)) {
        if (floor >= 1 && floor <= 8) {
            components.push_back(floor);
        } else {
            std::cerr << "Varování: Ignoruji neplatné patro " << floor << std::endl;
        }
    }
    
    if (components.size() != static_cast<size_t>(totalComponents)) {
        std::cerr << "Varování: Počet načtených součástek (" << components.size() 
                  << ") se neshoduje s očekávaným počtem (" << totalComponents << ")" << std::endl;
    }
    
    return !components.empty();
}

int ElevatorSystem::runTrivialSimulation() {
    int totalTime = 0;
    storage.clear();
    
    // Inicializace odkládacího prostoru prvními součástkami
    size_t nextComponentIndex = 0;
    while (storage.size() < static_cast<size_t>(maxStorageCapacity) && nextComponentIndex < components.size()) {
        storage.push_back(components[nextComponentIndex++]);
    }
    
    // Simulace triviálního přístupu - jedna součástka najednou
    while (!storage.empty()) {
        int floor = storage.front();
        storage.pop_front();
        
        // Čas cesty = 2 * patro (tam a zpět)
        totalTime += 2 * floor;
        
        // Doplnění odkládacího prostoru, pokud jsou k dispozici další součástky
        if (nextComponentIndex < components.size()) {
            storage.push_back(components[nextComponentIndex++]);
        }
    }
    
    return totalTime;
}

int ElevatorSystem::runOptimizedSimulation() {
    int totalTime = 0;
    storage.clear();
    
    // Inicializace odkládacího prostoru prvními součástkami
    size_t nextComponentIndex = 0;
    while (storage.size() < static_cast<size_t>(maxStorageCapacity) && nextComponentIndex < components.size()) {
        storage.push_back(components[nextComponentIndex++]);
    }
    
    // Simulace optimalizovaného přístupu
    while (!storage.empty()) {
        // Počítání součástek pro každé patro v odkládacím prostoru
        std::map<int, int> floorCounts;
        for (int floor : storage) {
            floorCounts[floor]++;
        }
        
        // Najít patro s nejvíce součástkami
        int targetFloor = 0;
        int maxCount = 0;
        for (const auto& pair : floorCounts) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                targetFloor = pair.first;
            }
        }
        
        // Naložit až 3 součástky pro cílové patro
        int loadedCount = 0;
        auto it = storage.begin();
        while (it != storage.end() && loadedCount < maxElevatorCapacity) {
            if (*it == targetFloor) {
                it = storage.erase(it);
                loadedCount++;
            } else {
                ++it;
            }
        }
        
        // Čas cesty = 2 * patro (tam a zpět)
        totalTime += 2 * targetFloor;
        
        // Doplnění odkládacího prostoru
        while (storage.size() < static_cast<size_t>(maxStorageCapacity) && nextComponentIndex < components.size()) {
            storage.push_back(components[nextComponentIndex++]);
        }
    }
    
    return totalTime;
}

void ElevatorSystem::displayResults(int trivialTime, int optimizedTime) const {
    std::cout << "Výsledky simulace:" << std::endl;
    std::cout << "Triviální přístup: " << trivialTime << " časových jednotek" << std::endl;
    std::cout << "Optimalizovaný přístup: " << optimizedTime << " časových jednotek" << std::endl;
    
    int timeSaved = trivialTime - optimizedTime;
    double percentImprovement = (static_cast<double>(timeSaved) / trivialTime) * 100.0;
    
    std::cout << "Úspora času: " << timeSaved << " časových jednotek (" 
              << percentImprovement << "%)" << std::endl;
}
