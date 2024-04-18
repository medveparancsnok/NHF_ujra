

#include "Bomba.h"


void Bomba::megjelenit(sf::RenderTarget *target)    {
    Mezo::megjelenit(target);
    if(felfedett){
        target->draw(bomba_sprite);
    }
}

void Bomba::ramleptel() {

}