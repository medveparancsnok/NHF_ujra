//
// Created by Otthon on 2024. 04. 18..
//

#include "Ures.h"

Ures::Ures(int& ures_mezok,  sf::Sprite &m_flag, sf::RectangleShape &m_alap, sf::Font &font,
           MezoAllapot kezdo): Mezo(m_flag, m_alap, kezdo), ures_mezok(ures_mezok), font(font), szomszedok(font, "0",20, sf::Color::Black, sf::Vector2f(0,0), sf::Text::Bold){}


void Ures::ramleptel() {
    megjelenit_atallit();
    ures_mezok--;
}

void Ures::megjelenit_atallit() {
    m_alap.setFillColor(sf::Color::White);
    //szomszedok.setPosition(m_alap.getPosition());
    //std::string buffer;
    //buffer += (char)('0' + getSzomszedok());
    //szomszedok.setString(buffer);
}


void Ures::megjelenit(sf::RenderWindow& target) const{
    Mezo::megjelenit(target);
    if(m_allapot == felfedett){
        target.draw(m_alap);
        //if(szomszedok.getString() != "0") {
        //    szomszedok.megjelenit(target);
        //}
    }
}

/*int Ures::getSzomszedok() {
    int bombak_szama = 0;

    int x = eger_lekepezes((int)m_alap.getPosition().x, 10, 40);
    int y = eger_lekepezes((int)m_alap.getPosition().y, 120, 40);

    if (valid_idx(x - 1) && valid_idx(y - 1) && eloszlas[(x- 1)][y - 1]) {
        bombak_szama++;
    }

    if (valid_idx(x - 1) && valid_idx(y) && eloszlas[x-1][y]) {
        bombak_szama++;

    }
    if (valid_idx(x - 1) && valid_idx(y + 1) && eloszlas[x-1][y+1]) {
        bombak_szama++;

    }
    if (valid_idx(x) && valid_idx(y - 1) && eloszlas[x][y-1]) {
        bombak_szama++;

    }
    if (valid_idx(x) && valid_idx(y + 1) && eloszlas[x][y + 1]) {
        bombak_szama++;

    }
    if (valid_idx(x + 1) && valid_idx(y - 1) && eloszlas[x+1][y-1]) {
        bombak_szama++;

    }
    if (valid_idx(x + 1) && valid_idx(y ) && eloszlas[x+1][y]) {
        bombak_szama++;

    }
    if (valid_idx(x + 1) && valid_idx(y + 1) && eloszlas[x+1][y+1]) {
        bombak_szama++;

    }
    return bombak_szama;
}*/