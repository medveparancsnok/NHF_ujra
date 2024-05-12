//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_BOMBA_H
#define NHF_UJRA_BOMBA_H
#include "Mezo.h"


/// @brief Osztály, mely a játékban az olyan mezőket reprezentálja, melyek bombák
class Bomba: public Mezo {
    sf::Sprite bomba_sprite;
    bool& felrobbant;
public:
    /// @brief Konstruktor
    /// \param felrobbant - a pályának, mely őt tartalmazza, egy adatmezője, játék végének jelzésére szolgál
    /// \param bomba_sprite - felfedett (bomba) mező megjelenítéséhez szükséges
    /// \param m_flag - flag-elt mező megjelenítéséhez szükséges
    /// \param m_alap - felfedetlen mező megjelnítéséhez szükséges
    /// \param kezdo - a mező kiinduló állapota
    Bomba(bool& felrobbant, sf::Sprite& bomba_sprite, sf::Sprite& m_flag, sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen);

    /// @brief A bomba mező megjelenítését végzi, annyiban különbözik a Mezo megjelenítésétől ,hogy ha fel van fedve, akkor
    /// kirajzolódik egy bomba_sprite a képernyőre
    /// \param target - erre történik a mező kirajzolása
    void megjelenit(sf::RenderWindow& target) const override;

    /// @brief Kezeli, hogy mi történik, ha a játékos rálép egy Bomba mezőre, ekkor az az adattagja, mely tárolja a Palya
    /// objektum felrobbant adattagjának referenciáját igazzá válik
    void ramleptel() override;

    /// @brief Teszteléshez szükséges
    /// @return Mindig igaz értékkel tér vissza
    bool IsBomb() const override;
};


#endif //NHF_UJRA_BOMBA_H
