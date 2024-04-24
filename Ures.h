//
// Created by Otthon on 2024. 04. 18..
//

#ifndef NHF_URES_H
#define NHF_URES_H

#include "Mezo.h"
#include "JatekFelirat.h"



class Ures: public Mezo {
    int& ures_mezok;
    sf::Font& font;
    JatekFelirat szomszedok;
    size_t bomba_szomszedok;

public:
    Ures(int& ures_mezok, sf::Sprite& m_flag,  sf::RectangleShape& m_alap, sf::Font& font, MezoAllapot kezdo = felfedetlen);

    void setSzomszedok(std::vector<Mezo*>& vektor, std::array<std::array<Mezo*, 14>, 14>& mezok);

    void ramleptel() override;

    void megjelenit(sf::RenderWindow& target) const override ;

    void megjelenit_atallit();
};

bool Eleme(const std::vector<Mezo*>& vektor, const Mezo* vizsgalando);


#endif //NHF_URES_H
