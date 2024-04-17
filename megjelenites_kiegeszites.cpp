#include <SFML/Graphics.hpp>


void felirat_letrehoz(sf::Text szoveg, const sf::Font &f, const std::string &cimke, const unsigned int &CharSize, const sf::Color &c,
                           const sf::Vector2<float> &pos, const sf::Text::Style &stil){
    szoveg.setFont(f);
    szoveg.setString(cimke);
    szoveg.setCharacterSize(CharSize);
    szoveg.setFillColor(c);
    szoveg.setPosition(pos);
    szoveg.setStyle(stil);
}
