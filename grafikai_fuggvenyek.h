#include <SFML/Graphics.hpp>

inline sf::Sprite sprite_betolt(const std::string& nev){
    sf::Sprite betoltendo;

    sf::Texture textura;
    if(!textura.loadFromFile("Flag.png")){
    }
    betoltendo.setTexture(textura);
    betoltendo.setTextureRect(sf::IntRect(0,0, 40, 40));

    return betoltendo;
}
