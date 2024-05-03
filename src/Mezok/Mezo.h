

#ifndef NHF_UJRA_MEZO_H
#define NHF_UJRA_MEZO_H
#include "../Segedosztalyok/Enumok/MezoAllapot.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include "../onallo_logikai/matematikai_fuggvenyek.h"

/// @brief Osztály, pálya ilyen mezők heterogén kollekcióját tartalmazza, alaposztálya a bombának és az üres mezőnek

class Mezo {
protected:
    MezoAllapot m_allapot;
    sf::Sprite m_flag;
    sf::RectangleShape m_alap;

public:

    /// @brief Konstruktor
    /// @param m_flag - A flag-elés megjelnítéséhez szükséges Sprite
    /// @param m_alap - A felfedetlen/felfedett mező megjelenítéséhez szükséges Háttér
    /// @param kezdo - A mezo  kezdeti állapota (mindig felfedetlen kezdetben)
    Mezo(sf::Sprite& m_flag,  sf::RectangleShape& m_alap, MezoAllapot kezdo = felfedetlen): m_allapot(kezdo),
    m_flag(m_flag), m_alap(m_alap){}

    /// @brief Mező típusától függően lekezeli, hogy mi történik, ha a mező felfedetté válik
    virtual void ramleptel() = 0;

    /// @brief A mezőre vonatkozó kattintásokat keezeli
    /// @param event - Az esemény, amit le kell kezelni
    void esemeny_kezel(sf::Event& event) {
        if(event.mouseButton.button == sf::Mouse::Right){
            jobb_klikk();
        }
        else if(event.mouseButton.button == sf::Mouse::Left){
            bal_klikk();
        }
    }

    /// @brief Ha balkattintás történt a mezőre
    void bal_klikk(){
        if(m_allapot == felfedetlen){
            m_allapot = felfedett;
            ramleptel();
        }
    }

    /// @brief Ha jobb kattintás történt a mezőre
    void jobb_klikk(){
        if(m_allapot == flagged){
            m_allapot = felfedetlen;
        }
        else if(m_allapot == felfedetlen){
            m_allapot = flagged;
        }
    }

    /// @brief Teszteléshez szükséges getter
    /// @return A mező aktuális állapotát adja vissza
    MezoAllapot getAllapot() const{
        return m_allapot;
    }

    /// @brief A mezőt jeleníti meg (függetlenül a specifikálktabb típusától), ha flagged, vagy felfedetlen
    /// @param Az ablak, amire a megjelenítés történik
    virtual void megjelenit(sf::RenderWindow& target) const{
        if(m_allapot == flagged){
            target.draw(m_alap);
            target.draw(m_flag);
        }
        if(m_allapot == felfedetlen){
            target.draw(m_alap);
        }
    }


    /// brief Destruktor
    virtual ~Mezo(){}
};


#endif //NHF_UJRA_MEZO_H
