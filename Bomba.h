//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_BOMBA_H
#define NHF_UJRA_BOMBA_H
#include "Mezo.h"


class Bomba: public Mezo {
    sf::Sprite bomba_sprite;
    bool& felrobbant;
public:
    Bomba(bool& felrobbant, sf::Sprite& bomba_sprite, sf::Sprite& m_flag, sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen) : Mezo(m_flag, m_alap, kezdo), bomba_sprite(bomba_sprite), felrobbant(felrobbant){}

    void megjelenit(sf::RenderWindow& target) const override;

    void ramleptel() override;
};


#endif //NHF_UJRA_BOMBA_H
