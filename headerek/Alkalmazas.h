

#ifndef NHF_UJRA_ALKALMAZAS_H
#define NHF_UJRA_ALKALMAZAS_H

#include "FoMenu.h"



/// @brief Osztály, ami a játék grafikus megjelenítésért felelős és a játék, illetve menü közötti váltást teszi lehetővé

class Alkalmazas {
    sf::RenderWindow ablak;
    std::stack<Menu *> stack;
    sf::Font font;
public:

    /// @brief Konstruktor, ami egy új alkalmazás objektumot hoz létre, betölti a feliratokhoz használt fontot,
    /// továbbá az ablakot beállítja, amin a játék megjelenítése történik, illetve létrehoz egy FoMenu objektumot
    /// a stacken
    Alkalmazas();

    /// @brief Futtatja az applikációt, eseményeket fogad, amik az ablak felé irányulnak, ha valaki a bezárást
    /// választja, akkor a stacket kiüríti, majd bezárja az applikációt, egyébként a stack tetején lévő objektum eseménykezelő
    /// függvényét hívja meg, majd ez után frissíti az ablakot és meghívja a stack legtetején lévő objektum megjelenítő függvényét
    void Run();
};


#endif //NHF_UJRA_ALKALMAZAS_H
