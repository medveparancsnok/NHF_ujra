//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_MEZO_H
#define NHF_UJRA_MEZO_H
#include "MezoAllapot.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include "Palya.h"

class Palya;

class Mezo {
protected:
    MezoAllapot m_allapot;
    sf::Sprite m_flag;
    sf::RectangleShape m_alap;
    Palya& palya;

public:
    Mezo(Palya& palya,const sf::Sprite& m_flag, const sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen): m_allapot(kezdo), palya(palya),
    m_flag(m_flag), m_alap(m_alap){}

    virtual void ramleptel() = 0;

    void esemeny_kezel(sf::Event event) {
        if(event.mouseButton.button == sf::Mouse::Right){
            jobb_klikk();
        }
        else if(event.mouseButton.button == sf::Mouse::Left){
            bal_klikk();
        }
    }

    void bal_klikk(){
        if(m_allapot == felfedetlen){
            m_allapot = felfedett;
        }
        ramleptel();
    }

    void jobb_klikk(){
        if(m_allapot == flagged){
            m_allapot = felfedetlen;
        }
        else if(m_allapot == felfedetlen){
            m_allapot = flagged;
        }
    }

    virtual void megjelenit(sf::RenderTarget *target) {
        target->draw(m_alap);
        if (m_allapot == flagged) {
            target->draw(m_flag);
        }
    }



};


#endif //NHF_UJRA_MEZO_H
