#include "../headerek/grafikai_fuggvenyek.h"



sf::RectangleShape mezo_alap_betolt(){
    sf::RectangleShape betoltendo;

    betoltendo.setSize(sf::Vector2f(40, 40));
    betoltendo.setFillColor(sf::Color(108, 111, 109));
    betoltendo.setOutlineColor(sf::Color::Blue);
    betoltendo.setOutlineThickness(1);

    return betoltendo;
}