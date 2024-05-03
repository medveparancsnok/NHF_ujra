

#ifndef NHF_UJRA_FOMENU_H
#define NHF_UJRA_FOMENU_H

#include "Menu.h"
#include <stack>
#include <SFML/Graphics.hpp>
#include "../Segedosztalyok/Grafikai/MenuFelirat.h"
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
    /// @brief Konstruktor
    /// \param stack - stack-es menükezeléshez szükséges, Menu objektumok heterogén kollekciója
    /// \param font - betűtípus a megjelenítéshez
    explicit FoMenu(std::stack<Menu *> &stack, sf::Font& font) : m_stack(stack),
    cim(font, "Valaszd ki a nehezseget", 40, sf::Color::Black, sf::Vector2<float>(175,10), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color(192, 192, 192)),
    konnyu_text(font, "KONNYU", 40, sf::Color::Black, sf::Vector2f(313.5,154.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color::Green),
    kozepes_text(font, "KOZEPES", 40, sf::Color::Black, sf::Vector2f(303.5,283.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 270), sf::Color(255,152,0)),
    nehez_text(font, "NEHEZ", 40, sf::Color::Black, sf::Vector2f(328,413), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 400), sf::Color::Red), font(font){}

    /// @brief Az eseménykezelést végzi
    /// @param esemeny - Ezt kezeli
    void esemeny_kezel(sf::Event& esemeny) override;


    /// @brief A főmenüt jeleníti meg
    /// @param target - ezen történik a megjelenítés
    void megjelenit(sf::RenderWindow& target) override;

};


#endif //NHF_UJRA_FOMENU_H
