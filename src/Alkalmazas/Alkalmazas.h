

#ifndef NHF_UJRA_ALKALMAZAS_H
#define NHF_UJRA_ALKALMAZAS_H
#include "../Menuk/FoMenu.h"


/// @brief Osztály, ami a játék grafikus megjelenítésért felelős és a játék, illetve menü közötti váltást teszi lehetővé

class Alkalmazas {
    sf::RenderWindow ablak;
    std::stack<Menu *> stack;
    sf::Font font;
public:

    /// @brief Konstruktor, ami egy új alkalmazás objektumot hoz létre, betölti a fontot és a főmenüt a stack-ben létrehozzas
    Alkalmazas();

    /// @brief Futtatja az applikációt, eseményeket fogad és megjelnít a stack alapján
    void Run();
};


#endif //NHF_UJRA_ALKALMAZAS_H
