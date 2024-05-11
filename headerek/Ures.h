//
// Created by Otthon on 2024. 04. 18..
//

#ifndef NHF_URES_H
#define NHF_URES_H

#include "Mezo.h"
#include "Felirat.h"
#include <array>



/// @brief Osztály, mely a játékban a bomba nélküli, úgymond üres mezőket reprezentálja
class Ures: public Mezo {
    std::array<std::array<Mezo*, 14>, 14>& mezok;
    int& ures_mezok;
    size_t bomba_szomszedok;
    unsigned long long sor;
    unsigned long long oszlop;
    Felirat szomszedok;

public:
    /// @brief Konstruktor
    /// \param mezok - a játék mezőinek mátrixa
    /// \param ures_mezok - a játék üres mezőinek a száma
    /// \param sor - A mezők mátrixában hanyadik sorban helyezkedik el az adott mező
    /// \param oszlop - A mezők mátrixában hanyadik oszlopban helyezkedik el az adott mező
    /// \param m_flag - A flag-elt üres mező megjelenítéséhez szükséges
    /// \param m_alap - a felfedetlen/felfedett üres mező megjelenítéséhez szükséges
    /// \param font - a szomszédok számának megjelenítéséhez szükséges
    /// \param kezdo - a mező kiindulási állapota
    Ures(std::array<std::array<Mezo*, 14>, 14>& mezok, int& ures_mezok,size_t sor,size_t oszlop, sf::Sprite& m_flag,  sf::RectangleShape& m_alap, sf::Font& font, MezoAllapot kezdo = felfedetlen);

    /// @brief Beállítja a mező bombaszomszédainak számát a paraméterül kapott pointertömb alapján, a működése annyi a függvénynek,
    /// @brief hogy minden egyes szomszédjára az adott mezőnek (szomszédok indexeit a saját indexéből határozom meg) megvizsgálja, hogy az
    /// @brief adott szomszédra mutató pointer az benne van-e a bombakra mutató pointertömbben, ha igen, akkor növeli bomba_szomszedok-nak
    ///@brief a számát, különben nem. Ahhoz hogy benne van-e az adott Mezo objektumra mutató pointer a bombak tömbjében
    ///@brief egy segédfüggvényt használok (bool Eleme(const std::vector<Mezo*>& bombak, const Mezo* vizsgalando))
    /// \param bombak - a pályán lévő bombákra mutató pointerek tömbje
    void setSzomszedok(const std::vector<Mezo*>& bombak);

    /// @brief Kezeli, ha a játékos rálép egy üres mezőre, ures_mezok számláló referenciáját eggyel csökkenti, és meghívja a
    ///@brief felderito_BFS() függvényt
    void ramleptel() override;

    /// @brief Ha a játékos olyan üres mezőre lép, melynek nincsenek bombaszomszédai, akkor neki minden szomszédja felfedetté válik
    ///@brief ez a függvény a hagyományos értelemben véve nem rekurzív, de mégis az, mivel azáltal, hogy a szomszédok felfedetté válnak
    ///@brief meghívódik mindegyiküknek a ramleptel() függvénye, ez pedig meghívhatja ismét a felderito_BFS() függvényt
    void felderito_BFS();

    /// Az üres mező megjelenítését végzi, annak megfelelően rajzolódik ki, hogy éppen milyen állapotban van
    /// \param target - erre történik a kirajzolás
    void megjelenit(sf::RenderWindow& target) const override ;

    /// @brief Ha az üres mező felfedetté válik, akkor a megjelnítését ő állítja át, hogy a háttere fehér legyen és ha vannak
    /// @brief bomba szomszédai, akkor az is megjelenik rajta feketével, hogy mennyi
    void megjelenit_atallit();

    /// @breif Visszaadja az adott üres mező bombaszomszédainak a számát
    /// \return A szomszédok száma
    size_t getBomba_szomszedok() const;

    /// @brief Teszteléshez szükséges
    /// @return Mindig hamis értékkel tér vissza
    bool IsBomb() const override;

};

/// @brief Megvizsgálja, hogy az adott mező bomba-e
/// \param bombak - A bomba mezőkre mutató pointerek tömbje
/// \param vizsgalando - A vizsgálandó mezőre mutató pointer
/// \return Vagy benne van (true), vagy nincs benne (false)
bool Eleme(const std::vector<Mezo*>& bombak, const Mezo* vizsgalando);


#endif //NHF_URES_H
