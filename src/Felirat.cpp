//
// Created by Otthon on 2024. 04. 15..
//

#include "../headerek/Felirat.h"


 Felirat::Felirat(const sf::Font& font, const std::string &cimke, const unsigned int &CharSize,
                          const sf::Color &c, const sf::Vector2<float> &szoveg_pos, const sf::Text::Style &stil)
                          {
    szoveg.setFont(font);
    szoveg.setString(cimke);
    szoveg.setCharacterSize(CharSize);
    szoveg.setFillColor(c);
    szoveg.setPosition(szoveg_pos);
    szoveg.setStyle(stil);

}


void Felirat::setString(const std::string& cimke) {
    szoveg.setString(cimke);
}

void Felirat::setPosition(const sf::Vector2f& v) {
    szoveg.setPosition(v);
}

std::string Felirat::getString() const{
    return szoveg.getString();
}

void Felirat::megjelenit(sf::RenderWindow& target) const {
    target.draw(szoveg);
}

