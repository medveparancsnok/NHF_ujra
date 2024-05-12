//
// Created by Otthon on 2024. 04. 16..
//

#include "../headerek/Mezo.h"


Mezo::Mezo(sf::Sprite &m_flag, sf::RectangleShape &m_alap, MezoAllapot kezdo): m_allapot(kezdo),
                                                                               m_flag(m_flag), m_alap(m_alap){}

void Mezo::esemeny_kezel(sf::Event& esemeny) {
    if(esemeny.mouseButton.button == sf::Mouse::Right){
        jobb_klikk();
    }
    else if(esemeny.mouseButton.button == sf::Mouse::Left){
        bal_klikk();
    }
}


void Mezo::bal_klikk(){
    if(m_allapot == felfedetlen){
        m_allapot = felfedett;
        ramleptel();
    }
    else{
        return;
    }
}


void Mezo::jobb_klikk(){
    if(m_allapot == flagged){
        m_allapot = felfedetlen;
    }
    else if(m_allapot == felfedetlen){
        m_allapot = flagged;
    }
    else{
        return;
    }
}

MezoAllapot Mezo::getAllapot() const{
    return m_allapot;
}

void Mezo::megjelenit(sf::RenderWindow& target) const{
    if(m_allapot == flagged){
        target.draw(m_alap);
        target.draw(m_flag);
    }
    if(m_allapot == felfedetlen){
        target.draw(m_alap);
    }
}