

#ifndef NHF_UJRA_FOMENU_H
#define NHF_UJRA_FOMENU_H

#include "Menu.h"
#include <stack>
#include <SFML/Graphics.hpp>
#include "MenuFelirat.h"
#include <iostream>



/// @brief Osztály, ami a játéknehézség kiválasztását kezeli
class FoMenu : public Menu{
    std::stack<Menu *> &m_stack;
    MenuFelirat cim;
    MenuFelirat konnyu_text;
    MenuFelirat kozepes_text;
    MenuFelirat nehez_text;
    sf::Font& font;


public:
    /// @brief Konstruktor, inicializálja a MenuFelirat adattagokat, amik gombként viselkednek
    /// \param stack - stack-es menükezeléshez szükséges, Menu objektumok heterogén kollekciója
    /// \param font - betűtípus a megjelenítéshez
    FoMenu(std::stack<Menu *> &stack, sf::Font& font);
    /// @brief Az eseménykezelést végzi, amennyiben az esemény egy bal egérgomb lenyomás volt, akkor eltárolja a kattintás
    /// koordinátáit és sorban odaadja a megfelelő nehézség "gomboknak", hogy vizsgálják meg rájuk kattintottak-e, ha igen,
    /// akkor annak a nehézségnek megfelelő Jatek objektum kerül a stack tetejére
    /// @param esemeny - Ezt kezeli
    void esemeny_kezel(sf::Event& esemeny) override;


    /// @brief A főmenüt jeleníti meg, a címet, továbbá a 3 nehézségi fajtát kiíró címke is megjelenik
    /// @param target - ezen történik a megjelenítés
    void megjelenit(sf::RenderWindow& target) override;

};


#endif //NHF_UJRA_FOMENU_H
