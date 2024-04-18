//
// Created by Otthon on 2024. 04. 15..
//

#ifndef NHF_UJRA_MENU_H
#define NHF_UJRA_MENU_H

#include <SFML/Graphics.hpp>

class Menu{
public:
    virtual void esemeny_kezel(sf::Event& esmemeny) = 0;

    virtual void megjelenit(sf::RenderWindow& target) = 0;

    virtual ~Menu(){}

};

#endif //NHF_UJRA_MENU_H
