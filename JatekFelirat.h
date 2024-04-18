//
// Created by Otthon on 2024. 04. 18..
//

#ifndef NHF_JATEKFELIRAT_H
#define NHF_JATEKFELIRAT_H
#include <SFML/Graphics.hpp>


class JatekFelirat {
    sf::Text felirat;
public:
    JatekFelirat(const sf::Font& font, const std::string& cimke , const unsigned int& CharSize , const sf::Color& c, const sf::Vector2<float>& szoveg_pos , const sf::Text::Style& stil);

    void megjelenit(sf::RenderWindow& target) const;

    void setString(std::string cimke);

    void setPosition(const float& x,const float& y);
};


#endif //NHF_JATEKFELIRAT_H
