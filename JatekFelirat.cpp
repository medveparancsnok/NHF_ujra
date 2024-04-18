//
// Created by Otthon on 2024. 04. 18..
//

#include "JatekFelirat.h"

JatekFelirat::JatekFelirat(const sf::Font &font, const std::string &cimke, const unsigned int &CharSize,
                           const sf::Color &c, const sf::Vector2<float> &szoveg_pos, const sf::Text::Style &stil) {
    felirat.setFont(font);
    felirat.setString(cimke);
    felirat.setCharacterSize(CharSize);
    felirat.setColor(c);
    felirat.setPosition(szoveg_pos);
    felirat.setStyle(stil);
}

void JatekFelirat::megjelenit(sf::RenderWindow &target) const{
    target.draw(felirat);
}

void JatekFelirat::setString(std::string cimke) {
    felirat.setString(cimke);
}

void JatekFelirat::setPosition(const float& x, const float& y) {
    felirat.setPosition(x, y);
}