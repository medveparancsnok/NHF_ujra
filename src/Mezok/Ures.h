//
// Created by Otthon on 2024. 04. 18..
//

#ifndef NHF_URES_H
#define NHF_URES_H

#include "Mezo.h"
#include "../Segedosztalyok/Grafikai/JatekFelirat.h"
#include <array>



class Ures: public Mezo {
    std::array<std::array<Mezo*, 14>, 14>& mezok;
    int& ures_mezok;
    size_t bomba_szomszedok;
    unsigned long long sor;
    unsigned long long oszlop;
    sf::Font& font;
    JatekFelirat szomszedok;

public:
    Ures(std::array<std::array<Mezo*, 14>, 14>& mezok, int& ures_mezok,unsigned long long sor,unsigned long long oszlop, sf::Sprite& m_flag,  sf::RectangleShape& m_alap, sf::Font& font, MezoAllapot kezdo = felfedetlen);

    void setSzomszedok(std::vector<Mezo*>& vektor);

    void ramleptel() override;

    void felderito_BFS();

    void megjelenit(sf::RenderWindow& target) const override ;

    void megjelenit_atallit();
};

bool Eleme(const std::vector<Mezo*>& vektor, const Mezo* vizsgalando);


#endif //NHF_URES_H
