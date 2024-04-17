//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_PALYA_H
#define NHF_UJRA_PALYA_H

#include "Bomba.h"
#include "Mezo.h"
#include <array>
#include "Nehezseg.h"


class Palya {
    const static int size = 14;
    sf::Sprite flagSprite;
    sf::Sprite bombaSprite;
    std::array<std::array<Mezo*, size>, size> mezok;
public:
    Palya(Nehezseg nehezseg);
    void esemeny_kezel(sf::Event event) {

    }

    void megjelenit(sf::RenderTarget *target) {

    }

    bool jatek_vege() const;

};


#endif //NHF_UJRA_PALYA_H
