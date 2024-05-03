//
// Created by Otthon on 2024. 04. 29..
//

#ifndef NHF_SAJATNEGYSZOG_H
#define NHF_SAJATNEGYSZOG_H
#include "SFML/Graphics.hpp"


class SajatNegyszog {
    sf::RectangleShape negyszog;
public:
    SajatNegyszog();

    void setPosition(const sf::Vector2f& uj_pos);

    sf::Vector2f getPosition();
};


#endif //NHF_SAJATNEGYSZOG_H
