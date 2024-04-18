//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_BOMBA_H
#define NHF_UJRA_BOMBA_H
#include "Mezo.h"


class Bomba: public Mezo {
    sf::Sprite bomba_sprite;
public:
    Bomba(Palya& palya, const sf::Sprite& m_flag, const sf::RectangleShape& m_alap, const sf::Sprite& bomba_sprite, MezoAllapot kezdo = felfedetlen) : Mezo(palya, m_flag, m_alap, kezdo), bomba_sprite(bomba_sprite){}

    void megjelenit(sf::RenderTarget *target) override;

    void ramleptel() override;
};


#endif //NHF_UJRA_BOMBA_H
