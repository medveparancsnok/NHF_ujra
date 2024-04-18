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


class Palya {
    const static int nagysag = 14;
    sf::Sprite flagSprite;
    sf::Sprite bombaSprite;
    sf::RectangleShape mezo_alap;
    std::array<std::array<Mezo*, nagysag>, nagysag> mezok;
    int ures_mezok;
    bool felrobbant;
public:
    Palya(Nehezseg nehezseg);

    void ures_mezo_csokkent();

    void felrobbant_a_jatek();

    JatekAllapot esemeny_kezel(sf::Event& event);

    void megjelenit(sf::RenderWindow& target);

    bool jatek_vege() const;

};


#endif //NHF_UJRA_PALYA_H
