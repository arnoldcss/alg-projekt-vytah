/**
 * @file ElevatorSystem.h
 * @brief Hlavičkový soubor pro třídu ElevatorSystem, která simuluje výtah ve výrobním procesu
 */

#ifndef ELEVATOR_SYSTEM_H
#define ELEVATOR_SYSTEM_H

#include <vector>
#include <deque>
#include <string>

/**
 * @class ElevatorSystem
 * @brief Simuluje systém výtahu ve výrobním procesu
 * 
 * Tato třída simuluje výtah, který přepravuje součástky do různých pater.
 * Výtah může najednou přepravit až 3 součástky a může cestovat pouze z přízemí
 * do cílového patra a zpět bez mezizastávek.
 */
class ElevatorSystem {
private:
    std::vector<int> components;      ///< Seznam všech součástek k přepravě
    std::deque<int> storage;          ///< Odkládací prostor (max 10 součástek)
    const int maxStorageCapacity = 10;    ///< Maximální kapacita odkládacího prostoru
    const int maxElevatorCapacity = 3;    ///< Maximální kapacita výtahu
    
public:
    /**
     * @brief Výchozí konstruktor
     */
    ElevatorSystem() = default;
    
    /**
     * @brief Načte součástky ze vstupního souboru
     * 
     * @param filename Cesta ke vstupnímu souboru
     * @return true pokud byl soubor úspěšně načten, false jinak
     */
    bool loadComponentsFromFile(const std::string& filename);
    
    /**
     * @brief Spustí triviální simulaci - jedna součástka najednou
     * 
     * @return Celkový čas potřebný pro přepravu
     */
    int runTrivialSimulation();
    
    /**
     * @brief Spustí optimalizovanou simulaci
     * 
     * @return Celkový čas potřebný pro přepravu
     */
    int runOptimizedSimulation();
    
    /**
     * @brief Zobrazí výsledky obou simulací
     * 
     * @param trivialTime Čas potřebný pro triviální simulaci
     * @param optimizedTime Čas potřebný pro optimalizovanou simulaci
     */
    void displayResults(int trivialTime, int optimizedTime) const;
};

#endif // ELEVATOR_SYSTEM_H
