//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_MEZO_H
#define NHF_UJRA_MEZO_H
#include "../Segedosztalyok/Grafikai/Enumok/MezoAllapot.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include "../onallo_logikai/matematikai_fuggvenyek.h"


class Mezo {
protected:
    MezoAllapot m_allapot;
    sf::Sprite m_flag;
    sf::RectangleShape m_alap;

public:
    Mezo(sf::Sprite& m_flag,  sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen): m_allapot(kezdo),
    m_flag(m_flag), m_alap(m_alap){}

    virtual void ramleptel() = 0;

    void esemeny_kezel(sf::Event& event) {
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
            ramleptel();
        }
    }

    void jobb_klikk(){
        if(m_allapot == flagged){
            m_allapot = felfedetlen;
        }
        else if(m_allapot == felfedetlen){
            m_allapot = flagged;
        }
    }

    MezoAllapot getAllapot() const{
        return m_allapot;
    }

    virtual void megjelenit(sf::RenderWindow& target) const{
        if(m_allapot == flagged){
            target.draw(m_alap);
            target.draw(m_flag);
        }
        if(m_allapot == felfedetlen){
            target.draw(m_alap);
        }
    }

    virtual ~Mezo(){}
};


#endif //NHF_UJRA_MEZO_H
