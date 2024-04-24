

#ifndef NHF_UJRA_JATEK_H
#define NHF_UJRA_JATEK_H

#include "Menu.h"
#include "../Palya/Palya.h"
#include <stack>
#include "../Segedosztalyok/Grafikai/Enumok/Nehezseg.h"
#include <SFML/Graphics.hpp>
#include "../Segedosztalyok/Grafikai/Enumok/Jatekallapot.h"
#include "../Grafikus_segedosztalyok/JatekFelirat.h"
#include "../onallo_logikai/matematikai_fuggvenyek.h"


class Jatek: public Menu{
    std::stack<Menu *> &m_stack;
    JatekAllapot jatekallapot;
    Palya palya;
    JatekFelirat vissza;
    JatekFelirat vege;
    sf::Font& font;
public:
    Jatek(std::stack<Menu *>& m_stack, Nehezseg nehezseg, sf::Font& f);

    void esemeny_kezel(sf::Event& esemeny) override;

    void megjelenit(sf::RenderWindow& target) override;

    void jatek_vege_megjelenit(sf::RenderWindow& target);
};


#endif //NHF_UJRA_JATEK_H
