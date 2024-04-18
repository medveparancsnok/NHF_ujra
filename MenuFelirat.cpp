//
// Created by Otthon on 2024. 04. 15..
//

#include "MenuFelirat.h"

 MenuFelirat::MenuFelirat(const sf::Font &f, const std::string &cimke, const unsigned int &CharSize,
                          const sf::Color &c, const sf::Vector2<float> &szoveg_pos, const sf::Text::Style &stil,
                          sf::Vector2f size, sf::Vector2f hatter_pos, sf::Color c_fill, sf::Color o_fill,
                          float thickness) {
    szoveg.setFont(f);
    szoveg.setString(cimke);
    szoveg.setCharacterSize(CharSize);
    szoveg.setFillColor(c);
    szoveg.setPosition(szoveg_pos);
    szoveg.setStyle(stil);

    hatter.setSize(size);
    hatter.setPosition(hatter_pos);
    hatter.setFillColor(c_fill);
    hatter.setOutlineColor(o_fill);
    hatter.setOutlineThickness(thickness);;
}

void MenuFelirat::megjelenit(sf::RenderWindow& target){
    target.draw(hatter);
    target.draw(szoveg);
}
