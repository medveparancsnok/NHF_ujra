

#ifndef NHF_UJRA_FOMENU_H
#define NHF_UJRA_FOMENU_H

#include "Menu.h"
#include <stack>
#include <SFML/Graphics.hpp>
#include "SajatFelirat.h"
#include "Jatek.h"


class FoMenu : public Menu{
    SajatFelirat cim;
    SajatFelirat konnyu_text;
    SajatFelirat kozepes_text;
    SajatFelirat nehez_text;
    std::stack<Menu *> &m_stack;
    sf::Font font;
public:
    explicit FoMenu(std::stack<Menu *> &stack,const sf::Font& font) : m_stack(stack), font(font),
    cim(font ,"Valaszd ki a nehezseget", 40, sf::Color::Black, sf::Vector2<float>(175,10), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color(192, 192, 192));

    //...
    void esemeny_kezel(sf::Event& esemeny) override {
        if (esemeny.mouseButton.button == sf::Mouse::Left) {
            if (is_inside(esemeny)) {
                m_stack.push(new Jatek(konnyu));
            }
        }
    }

    void megjelenit(sf::RenderWindow& target) override {
        cim.megjelenit(target);
        konnyu_text.megjelenit(target);
        kozepes_text.megjelenit(target);
        nehez_text.megjelenit(target);

    }


};


#endif //NHF_UJRA_FOMENU_H
