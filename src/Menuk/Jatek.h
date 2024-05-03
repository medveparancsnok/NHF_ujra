

#ifndef NHF_UJRA_JATEK_H
#define NHF_UJRA_JATEK_H

#include "Menu.h"
#include "../Palya/Palya.h"
#include <stack>
#include "../Segedosztalyok/Enumok/Nehezseg.h"
#include <SFML/Graphics.hpp>
#include "../Segedosztalyok/Enumok/Jatekallapot.h"
#include "../Segedosztalyok/Grafikai/MenuFelirat.h"
#include "../onallo_logikai/matematikai_fuggvenyek.h"


/// @brief Osztály, amely tartalmazza magát a játékot
class Jatek: public Menu{
    std::stack<Menu *> &m_stack;
    JatekAllapot jatekallapot;
    Palya palya;
    MenuFelirat vissza;
    Felirat vege;
public:
    /// @brief Konstruktor
    /// @param m_stack - Menu objektumok heterogén kollekciója
    /// @param nehezseg - Ennek megfelelő pálya generálódik
    /// @param font - megjelnítéshez szükséges betűtípus
    Jatek(std::stack<Menu *>& m_stack, Nehezseg nehezseg, sf::Font& font);

    /// @brief Esemény kezelését végzi
    /// @param esemeny - ennek a kezelése történik
    void esemeny_kezel(sf::Event& esemeny) override;

    /// @brief A játék megjelenítését végzi
    /// @param target - Erre rajzolja ki a játékállást
    void megjelenit(sf::RenderWindow& target) override;

    /// @brief Ha véget ér a játék, ő jeleníti meg azt
    /// \param target - Erre rajzolja a játék végét
    void jatek_vege_megjelenit(sf::RenderWindow& target);
};


#endif //NHF_UJRA_JATEK_H
