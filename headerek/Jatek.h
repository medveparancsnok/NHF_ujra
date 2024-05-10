

#ifndef NHF_UJRA_JATEK_H
#define NHF_UJRA_JATEK_H

#include "Menu.h"
#include "Palya.h"
#include <stack>
#include "Nehezseg.h"
#include <SFML/Graphics.hpp>
#include "Jatekallapot.h"
#include "MenuFelirat.h"
#include "matematikai_fuggvenyek.h"


/// @brief Osztály, amely tartalmazza magát a játékot
class Jatek: public Menu{
    std::stack<Menu *> &m_stack;
    JatekAllapot jatekallapot;
    Palya palya;
    MenuFelirat vissza;
    Felirat vege;
public:
    /// @brief Konstruktor, megfelelő nehézségű pályát hoz létre, illetve beállítja a jatekallapot adattagot jatek értékűre
    /// @param m_stack - Menu objektumok heterogén kollekciója
    /// @param nehezseg - Ennek megfelelő pálya generálódik
    /// @param font - megjelnítéshez szükséges betűtípus
    Jatek(std::stack<Menu *>& m_stack, Nehezseg nehezseg, sf::Font& font);

    /// @brief Esemény kezelését végzi, amennyiben egy kattintás érkezik és a játék állapota játék, akkor a pálya
    /// eseménykezelő függvénye megkapja az adott eseményt, a pedig a játék állapota vereség, vagy győzelem és bal
    /// kattintás történt a vissza "gombra", akkor leveszi magát a stackről
    /// @param esemeny - ennek a kezelése történik
    void esemeny_kezel(sf::Event& esemeny) override;

    /// @brief A játék megjelenítését végzi, ha a játék állapota játék, akkor csak a pálya megjelíntó függvényét hívja,
    /// viszont, ha a játék állapota vereség vagy győzelem, akkor meghívja a jatek_vege_megjelenit függvényt
    /// @param target - Erre rajzolja ki a játékállást
    void megjelenit(sf::RenderWindow& target) override;

    /// @brief Ha véget ér a játék, ő jeleníti meg azt, méghozzá annak megfelelően, hogy győzelem, vagy vereség történt,
    /// továbba a vissza gomb is ekkor jelenik meg
    /// \param target - Erre rajzolja a játék végét
    void jatek_vege_megjelenit(sf::RenderWindow& target);
};


#endif //NHF_UJRA_JATEK_H
