//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_MEZO_H
#define NHF_UJRA_MEZO_H
#include "MezoAllapot.h"
#include <SFML/Graphics.hpp>


class Mezo {
    MezoAllapot m_state{felfedetlen};
    bool bomba;
    sf::Sprite m_flag;
    sf::Sprite m_bomba;
    sf::RectangleShape m_alap;
public:
    void esemeny_kezel(sf::Event event) {
        // ...
    }

    virtual void megjelenit(sf::RenderTarget *target) {
        target->draw(m_alap);
        if (m_state == flagged) {
            target->draw(m_flag);
        }
    }

protected:
    bool felfedett_e() const {
        return m_state == felfedett;
    }

};


#endif //NHF_UJRA_MEZO_H
