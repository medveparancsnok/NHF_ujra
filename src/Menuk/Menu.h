//
// Created by Otthon on 2024. 04. 15..
//

#ifndef NHF_UJRA_MENU_H
#define NHF_UJRA_MENU_H

#include <SFML/Graphics.hpp>


/// @brief Osztály, ami lehetővé teszi a stackes menükezelést
class Menu{
public:
    /// @brief Az események kezelését végzi
    /// \param esmemeny - Maga az esemény, ami kezelésre kerül
    virtual void esemeny_kezel(sf::Event& esmemeny) = 0;

    /// @brief A megjelenítést végzi
    /// @param target - Erre rajzolja ki a menüt (vagy játékot)
    virtual void megjelenit(sf::RenderWindow& target) = 0;

    /// @brief Destruktor, virtuális, hiszen öröklődnek belőle
    virtual ~Menu(){}

};

#endif //NHF_UJRA_MENU_H
