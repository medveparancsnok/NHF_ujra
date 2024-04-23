//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_PALYA_H
#define NHF_UJRA_PALYA_H

#include "Bomba.h"
#include "Mezo.h"
#include "Ures.h"
#include <array>
#include "Nehezseg.h"
#include "Jatekallapot.h"
#include "Random.h"
#include "Jatekallapot.h"
#include "matematikai_fuggvenyek.h"
#include <iostream>

class Mezo;


class Palya {
    std::array<std::array<Mezo*, 14>, 14> mezok;
    std::array<std::array<bool, 14>,14> eloszlas;
    int ures_mezok;
    bool felrobbant;
    sf::Sprite flagSprite;
    sf::Texture flagTextura;
    sf::Sprite bombaSprite;
    sf::Texture bombaTextura;
    sf::RectangleShape mezo_alap;
    sf::Font& font;

public:
    Palya(Nehezseg nehezseg, sf::Font& font);

    JatekAllapot esemeny_kezel(sf::Event& event);

    void megjelenit(sf::RenderWindow& target);

    ~Palya();
};


#endif //NHF_UJRA_PALYA_H
