

#include "../headerek/Bomba.h"


Bomba::Bomba(bool& felrobbant, sf::Sprite& bomba_sprite, sf::Sprite& m_flag, sf::RectangleShape& m_alap, MezoAllapot kezdo): Mezo(m_flag, m_alap, kezdo), bomba_sprite(bomba_sprite), felrobbant(felrobbant){}


void Bomba::megjelenit(sf::RenderWindow& target) const{
    Mezo::megjelenit(target);
    if(m_allapot == felfedett){
        target.draw(m_alap);
        target.draw(bomba_sprite);
    }
}

void Bomba::ramleptel() {
    felrobbant = true;
}

bool Bomba::IsBomb() const{
    return true;
}