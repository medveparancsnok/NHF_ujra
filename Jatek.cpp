//
// Created by Otthon on 2024. 04. 16..
//

#include "Jatek.h"

Jatek::Jatek(std::stack<Menu *>& m_stack, Nehezseg nehezseg, sf::Font& f) : m_stack(m_stack), palya(nehezseg), vissza(f, "VISSZA", 25,sf::Color::Black, sf::Vector2f(5,565), sf::Text::Style::Underlined),
vege(f, "GYOZTEL", 70, sf::Color::Red, sf::Vector2f(200, 200), sf::Text::Bold), font(f){
    jatekallapot = jatek;
}

void Jatek::esemeny_kezel(sf::Event& esemeny) {
    if (jatekallapot == jatek) {
        jatekallapot = palya.esemeny_kezel(esemeny);
    }
    if(jatekallapot == gyozelem || jatekallapot == vereseg){
        if(vissza_lep(esemeny)){
            delete m_stack.top();
            m_stack.pop();
        }
    }
}
void Jatek::jatek_vege_megjelenit(sf::RenderWindow &target) {
    vissza.megjelenit(target);
    if(jatekallapot == vereseg){
        vege.setString("BOMBARA LEPTEL");
        vege.setPosition(50,100);
    }
    vege.megjelenit(target);
}

void Jatek::megjelenit(sf::RenderWindow &target) {
    palya.megjelenit(target);
    if(jatekallapot != jatek){
        jatek_vege_megjelenit(target);
    }

}
