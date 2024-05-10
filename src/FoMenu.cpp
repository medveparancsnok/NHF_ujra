//
// Created by Otthon on 2024. 04. 15..
//

#include "../headerek/FoMenu.h"
#include "../headerek/matematikai_fuggvenyek.h"
#include "../headerek/Jatek.h"

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

