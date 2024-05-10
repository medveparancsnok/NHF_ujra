//
// Created by Otthon on 2024. 04. 15..
//

#ifndef NHF_UJRA_SAJAT_FELIRAT_H
#define NHF_UJRA_SAJAT_FELIRAT_H
#include <SFML/Graphics.hpp>

/// @brief Osztály, saját felirat
class Felirat{
protected:
    sf::Text szoveg;
public:
    /// @breif Konstruktor
    /// \param font - a szöveg betűtípusa
    /// \param cimke - maga a szöveg
    /// \param CharSize - a szöveg karaktermérete
    /// \param c - a szöveg színe
    /// \param szoveg_pos - a szöveg pozíciója
    /// \param stil - a szöveg stílusa
    Felirat(const sf::Font& font, const std::string& cimke , const unsigned int& CharSize , const sf::Color& c, const sf::Vector2<float>& szoveg_pos , const sf::Text::Style& stil);

    /// @brief Beállítja a felirat szövegét
    /// @param cimke - amire be kell állítani
    void setString(const std::string& cimke);

    /// @brief Beállítja a szöveg pozícióját
    /// \param pozicio - ami az új pozíció lesz
    void setPosition(const sf::Vector2f& pozicio);

    /// @brief Visszaadja a felirat szövegét
    /// @return A szöveg
    std::string getString() const;

    /// @brief A szöveg megjelenítését végzi
    /// @param target - erre rajzolja ki a szöveget
    virtual void megjelenit(sf::RenderWindow& target) const;
};


#endif //NHF_UJRA_SAJAT_FELIRAT_H
