//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_JATEK_H
#define NHF_UJRA_JATEK_H

#include "Menu.h"
#include "Palya.h"
#include <stack>
#include "Nehezseg.h"
#include <SFML/Graphics.hpp>


class Jatek: public Menu{
private:
    bool jatek_vege;
    Palya palya;
    std::stack<Menu *> &m_stack;
    sf::Font font;
public:
    explicit Jatek(Nehezseg nehezseg);

    void esemeny_kezel(sf::Event esemeny) override {
        jatek_vege = palya.jatek_vege();
        if (!jatek_vege) {
            //...
        }
    }

    void megjelenit(sf::RenderTarget *target, const sf::Font font) override;


};


#endif //NHF_UJRA_JATEK_H
