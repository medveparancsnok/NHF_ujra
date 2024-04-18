//
// Created by Otthon on 2024. 04. 15..
//

#include "FoMenu.h"
#include "matematikai_fuggvenyek.h"
#include "Jatek.h"

void FoMenu::esemeny_kezel(sf::Event& esemeny){
    if (esemeny.mouseButton.button == sf::Mouse::Left) {
        if (konnyun_belul(esemeny.mouseButton.x,esemeny.mouseButton.y)) {
            m_stack.push(new Jatek(m_stack, konnyu, font));
        }
        if (kozepesen_belul(esemeny.mouseButton.x,esemeny.mouseButton.y)) {
            m_stack.push(new Jatek(kozepes));
        }
        if (nehezen_belul(esemeny.mouseButton.x,esemeny.mouseButton.y)) {
            m_stack.push(new Jatek(nehez));
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

