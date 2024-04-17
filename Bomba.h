//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_BOMBA_H
#define NHF_UJRA_BOMBA_H
#include "Mezo.h"


class Bomba: public  {
    sf::Sprite bomba_sprite;
public:
    void megjelenit(sf::RenderTarget *target) override {
        Mezo::megjelenit(target);

        if (felfedett_e()) {
            target->draw(bomba_sprite);
        }
    }

};


#endif //NHF_UJRA_BOMBA_H
