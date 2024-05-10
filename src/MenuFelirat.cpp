//
// Created by Otthon on 2024. 05. 03..
//

#include "../headerek/MenuFelirat.h"

MenuFelirat::MenuFelirat(const sf::Font& font, const std::string& cimke , const unsigned int& CharSize , const sf::Color& c,
            const sf::Vector2<float>& szoveg_pos , const sf::Text::Style& stil, sf::Vector2f size, sf::Vector2f hatter_pos,
            sf::Color c_fill, sf::Color o_fill, float thickness):
            Felirat(font, cimke, CharSize, c, szoveg_pos, stil){
    hatter.setSize(size);
    hatter.setPosition(hatter_pos);
    hatter.setFillColor(c_fill);
    hatter.setOutlineColor(o_fill);
    hatter.setOutlineThickness(thickness);
}

bool MenuFelirat::belul(const sf::Vector2f& pos){
    return pos.x >= hatter.getPosition().x && pos.x <= (hatter.getPosition().x + hatter.getSize().x) &&
           pos.y >= hatter.getPosition().y && pos.y <= (hatter.getPosition().y + hatter.getSize().y);
}

void MenuFelirat::megjelenit(sf::RenderWindow& target) const{
    target.draw(hatter);
    Felirat::megjelenit(target);
}