

#include "../headerek/Bomba.h"



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