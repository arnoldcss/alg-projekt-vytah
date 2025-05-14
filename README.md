# Simulace výtahu

Tento projekt simuluje a optimalizuje část výrobního procesu v průmyslové výrobě, konkrétně dopravu součástek pomocí výtahu do různých pater výrobní haly.

## Popis problému

Výrobní linka je rozdělena do několika částí, které jsou umístěny v různých patrech výrobní haly. Dopravu do těchto pater obstarává malý výtah obsluhovaný robotem. Robot vkládá součástky do výtahu v přízemí a součástky následně výtahem putují do jednoho z osmi pater. Každá součástka je označena číslem 1 až 8, které určuje, do kterého patra musí být dopravena.

- Výtah je schopen najednou přepravit maximálně tři součástky.
- Výtah je schopen jet pouze z přízemí do vybraného patra a poté se vrátit, nelze dělat "zastávky".
- Přesun výtahu z jednoho patra do druhého považujeme za jednotku času, bez ohledu na to, kolik součástek veze.
- Robot má k dispozici odkládací prostor, který pojme maximálně 10 součástek.
- Odkládací prostor je, do vyčerpání všech součástek, průběžně doplňován.

## Implementace

Projekt implementuje dvě simulace:

1. **Triviální simulace**: Součástky jsou dopravovány pouze po jedné, v pořadí, v jakém jsou doplňovány do odkládacího prostoru.
2. **Optimalizovaná simulace**: Systém dopravy je zlepšen tak, aby se snížil celkový čas dopravy všech součástek. Optimalizace spočívá v lepším využití kapacity výtahu a v lepší organizaci součástek v odkládacím prostoru.

### Strategie optimalizace

Optimalizovaná simulace používá následující strategii:

1. Počítá, kolik součástek pro každé patro se nachází v odkládacím prostoru.
2. Vybírá patro s nejvíce součástkami.
3. Najednou přepravuje až 3 součástky do stejného patra.
4. Tím minimalizuje počet cest výtahu a celkový čas přepravy.

## Kompilace a spuštění

Pro kompilaci projektu použijte příkaz:

```
make
```

Pro spuštění simulace s ukázkovým vstupním souborem:

```
make run
```

Nebo můžete spustit program přímo s vlastním vstupním souborem:

```
./elevator_simulation cesta/k/souboru.txt
```

## Formát vstupního souboru

Vstupní soubor má následující formát:
- Na prvním řádku je uveden celkový počet součástek k dopravě.
- Na každém následujícím řádku je jedno celé číslo p ∈ ⟨1, 8⟩, které označuje patro, kam je nutné součástku dopravit.

Příklad vstupního souboru:
```
10
3
2
1
7
6
1
4
1
8
7
```

## Generování dokumentace

Pro vygenerování dokumentace pomocí Doxygen použijte příkaz:

```
doxygen
```

Dokumentace bude vygenerována v adresáři `doc/html`.

## Citace

V tomto projektu jsem využil následující zdroje:
- [Doxygen](https://www.doxygen.nl/) pro generování dokumentace.
- [Greedy algoritmus](https://www.geeksforgeeks.org/greedy-algorithms/) pro optimalizaci dopravy součástek.
- [Vector](https://www.geeksforgeeks.org/vector-in-cpp-stl/) pro efektivní správu seznamu součástek.

