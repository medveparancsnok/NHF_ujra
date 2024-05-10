
#ifndef NHF_MENUFELIRAT_H
#define NHF_MENUFELIRAT_H

#include "Felirat.h"

/// @brief Osztály, saját felirat, amely rendelkezik háttérrel is
class MenuFelirat: public Felirat {
    sf::RectangleShape hatter;

public:
    /// @brief Konstruktor, az alább felsorolt paraméterekkel inicializálja saját adattagjait
    ///  @param font - a szöveg betűtípusa
    ///  @param cimke - maga a szöveg
    ///  @param CharSize - a szöveg karaktermérete
    ///  @param c - a szöveg színe
    ///  @param szoveg_pos - a szöveg pozíciója
    ///  @param stil - a szöveg stílusa
    ///  @param size - a háttér mérete
    ///  @param hatter_pos - a háttér pozíciója
    ///  @param c_fill - a háttér kitöltőszíne
    ///  @param o_fill - a háttér hatarálóv onalának színe
    ///  @param thickness - a háttér határoló vonalának vastagsága
    MenuFelirat(const sf::Font& font, const std::string& cimke , const unsigned int& CharSize , const sf::Color& c, const sf::Vector2<float>& szoveg_pos , const sf::Text::Style& stil, sf::Vector2f size, sf::Vector2f hatter_pos, sf::Color c_fill = sf::Color(192, 192, 192), sf::Color o_fill = sf::Color(192, 192, 192), float thickness = 0);

    /// @brief Megvizsgálja, hogy a paraméterül kapott 2D pont, az a háttéren belül van-e
    /// \return Belül van (true), kívül van (false)
    bool belul(const sf::Vector2f&);

    /// @brief A felirat megjelenítését végzi, mégozzá úgy, hogy először a háttér jelenik meg, majd a felirat rárajzolódik,
    /// különben a háttér eltakarná
    /// @param ablak - erre rajzolja ki magát
    void megjelenit(sf::RenderWindow& ablak) const;
};


#endif //NHF_MENUFELIRAT_H
