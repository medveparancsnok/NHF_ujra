

#ifndef NHF_UJRA_FOMENU_H
#define NHF_UJRA_FOMENU_H

#include "Menu.h"
#include <stack>
#include <SFML/Graphics.hpp>
#include "../Grafikus_segedosztalyok/MenuFelirat.h"
#include <iostream>



class FoMenu : public Menu{
    std::stack<Menu *> &m_stack;
    sf::Font& font;
    MenuFelirat cim;
    MenuFelirat konnyu_text;
    MenuFelirat kozepes_text;
    MenuFelirat nehez_text;


public:
    explicit FoMenu(std::stack<Menu *> &stack, sf::Font& font) : m_stack(stack), font(font),
    cim(font ,"Valaszd ki a nehezseget", 40, sf::Color::Black, sf::Vector2<float>(175,10), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color(192, 192, 192)),
    konnyu_text(font, "KONNYU", 40, sf::Color::Black, sf::Vector2f(313.5,154.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color::Green),
    kozepes_text(font, "KOZEPES", 40, sf::Color::Black, sf::Vector2f(303.5,283.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 270), sf::Color(255,152,0)),
    nehez_text(font, "NEHEZ", 40, sf::Color::Black, sf::Vector2f(328,413), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 400), sf::Color::Red){}

    //...
    void esemeny_kezel(sf::Event& esemeny) override;

    void megjelenit(sf::RenderWindow& target) override;

};


#endif //NHF_UJRA_FOMENU_H
