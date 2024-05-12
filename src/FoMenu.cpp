

#include "../headerek/FoMenu.h"
#include "../headerek/matematikai_fuggvenyek.h"
#include "../headerek/Jatek.h"


FoMenu::FoMenu(std::stack<Menu *> &stack, sf::Font &font): m_stack(stack),
cim(font, "Valaszd ki a nehezseget", 40, sf::Color::Black, sf::Vector2<float>(175,10), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color(192, 192, 192)),
konnyu_text(font, "KONNYU", 40, sf::Color::Black, sf::Vector2f(313.5,154.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 140), sf::Color::Green),
kozepes_text(font, "KOZEPES", 40, sf::Color::Black, sf::Vector2f(303.5,283.5), sf::Text::Bold,sf::Vector2f(300, 75),sf::Vector2f(250, 270), sf::Color(255,152,0)),
nehez_text(font, "NEHEZ", 40, sf::Color::Black, sf::Vector2f(328,413), sf::Text::Bold, sf::Vector2f(300, 75),sf::Vector2f(250, 400), sf::Color::Red), font(font){}

void FoMenu::esemeny_kezel(sf::Event& esemeny){
    if (esemeny.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f kattintas((float)esemeny.mouseButton.x, (float)esemeny.mouseButton.y);
        if (konnyu_text.belul(kattintas)) {
            m_stack.push(new Jatek(m_stack, konnyu, font));
        }
        if (kozepes_text.belul(kattintas)) {
            m_stack.push(new Jatek(m_stack, kozepes, font));
        }
        if (nehez_text.belul(kattintas)) {
            m_stack.push(new Jatek(m_stack, nehez, font));
        }
    }
    else{
        return;
    }
}
void FoMenu::megjelenit(sf::RenderWindow& target) {
    cim.megjelenit(target);
    konnyu_text.megjelenit(target);
    kozepes_text.megjelenit(target);
    nehez_text.megjelenit(target);

}

