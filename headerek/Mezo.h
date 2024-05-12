

#ifndef NHF_UJRA_MEZO_H
#define NHF_UJRA_MEZO_H

#include "MezoAllapot.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include "matematikai_fuggvenyek.h"


/// @brief Osztály, pálya ilyen mezők heterogén kollekcióját tartalmazza, alaposztálya a bombának és az üres mezőnek

class Mezo {
protected:
    MezoAllapot m_allapot;
    sf::Sprite m_flag;
    sf::RectangleShape m_alap;

public:

    /// @brief Konstruktor, megjelenítéshez szükséges adattagokat állítja be a paraméterek alpaján, illetve a mező kezdőállapotát
    /// @param m_flag - A flag-elés megjelnítéséhez szükséges Sprite
    /// @param m_alap - A felfedetlen/felfedett mező megjelenítéséhez szükséges Háttér
    /// @param kezdo - A mezo  kezdeti állapota (mindig felfedetlen kezdetben)
    Mezo(sf::Sprite& m_flag,  sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen);

    /// @brief Mező típusától függően lekezeli, hogy mi történik, ha a mező felfedetté válik
    virtual void ramleptel() = 0;

    /// @brief A mezőre vonatkozó kattintásokat kezeli, amennyiben bal kattintás történt a mezőre, akkor a bal_klikk() függvény
    /// hívódik meg, amennyiben pedig jobb kattintás történt a mezőre, akkor a jobb_klikk() függvényt hívja meg
    /// @param event - Az esemény, amit le kell kezelni
    void esemeny_kezel(sf::Event& esemeny);

    /// @brief Ha bal kattintás történt a mezőre, és a mező eddig felfedetlen volt, akkor felfedetté válik és meghívja az adott
    /// mező ramleptel() függvényét, egyébként figgyelmen kívül hagyja
    void bal_klikk();

    /// @brief Ha jobb kattintás történt a mezőre és a mező állapota felfedetlen volt, akkor az állapot flagged lesz, ha pedig
    /// flagged volt az állapot, akkor felfedetlen lesz, különben figyelmen kívül hagyja a kattintást
    void jobb_klikk();

    /// @brief Teszteléshez szükséges getter
    /// @return A mező aktuális állapotát adja vissza
    MezoAllapot getAllapot() const;

    /// @brief Teszteléshez szükséges
    /// @return Visszaadja, hogy a mező bomba-e (true), vagy sem (false)
    virtual bool IsBomb() const = 0;

    /// @brief A mezőt jeleníti meg (függetlenül a specifikálktabb típusától), ha flagged, vagy felfedetlen
    /// @param Az ablak, amire a megjelenítés történik
    virtual void megjelenit(sf::RenderWindow& target) const;


    /// brief Destruktor
    virtual ~Mezo(){}
};


#endif //NHF_UJRA_MEZO_H
