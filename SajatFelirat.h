//
// Created by Otthon on 2024. 04. 15..
//

#ifndef NHF_UJRA_SAJAT_FELIRAT_H
#define NHF_UJRA_SAJAT_FELIRAT_H
#include <SFML/Graphics.hpp>


class SajatFelirat {
    sf::Text szoveg;
    sf::RectangleShape hatter;
public:
    SajatFelirat(const sf::Font& f, const std::string& cimke , const unsigned int& CharSize ,const sf::Color& c, const sf::Vector2<float>& szoveg_pos ,const sf::Text::Style& stil,sf::Vector2f size, sf::Vector2f hatter_pos, sf::Color c_fill, sf::Color o_fill = sf::Color(192,192,192), float thickness = 0);

    void megjelenit(sf::RenderWindow& target);
};


#endif //NHF_UJRA_SAJAT_FELIRAT_H
