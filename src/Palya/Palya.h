//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_PALYA_H
#define NHF_UJRA_PALYA_H

#include "../Mezok/Bomba.h"
#include "../Mezok/Mezo.h"
#include "../Mezok/Ures.h"
#include <array>
#include "../Segedosztalyok/Grafikai/Enumok/Nehezseg.h"
#include "../Segedosztalyok/Grafikai/Enumok/Jatekallapot.h"
#include "Random/palya_feltoltes/Random.h"
#include "../Segedosztalyok/Grafikai/Enumok/Jatekallapot.h"
#include "../onallo_logikai/matematikai_fuggvenyek.h"
#include <iostream>

class Mezo;


class Palya {
    std::array<std::array<Mezo*, 14>, 14> mezok;
    std::vector<Mezo*> vektor;
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
