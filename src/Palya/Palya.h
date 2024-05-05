//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_PALYA_H
#define NHF_UJRA_PALYA_H

#include "../Mezok/Bomba.h"
#include "../Mezok/Mezo.h"
#include "../Mezok/Ures.h"
#include <array>
#include "../Segedosztalyok/Enumok/Nehezseg.h"
#include "../Segedosztalyok/Enumok/Jatekallapot.h"
#include "Random/palya_feltoltes/Random.h"
#include "../Segedosztalyok/Enumok/Jatekallapot.h"
#include "../onallo_logikai/matematikai_fuggvenyek.h"
#include <iostream>

class Mezo;


/// @brief Osztály, amiben a mezők vannak eltárolva heterogén kollekcióban
class Palya {
    std::array<std::array<Mezo*, 14>, 14> mezok;
    std::vector<Mezo*> bombak;
    std::vector<std::pair<size_t, size_t>> szomszed_nelkuliek;
    int ures_mezok;
    bool felrobbant;
    sf::Sprite flagSprite;
    sf::Texture flagTextura;
    sf::Sprite bombaSprite;
    sf::Texture bombaTextura;
    sf::RectangleShape mezo_alap;
    sf::Font font;

public:
    /// @brief Konstruktor, ami a pályán határozza meg véletlenszerűen, hogy mely mezők legyenek bombák és melyek üresek
    /// \param nehezseg - ennek megfelelő nehézségű pálya generálódik
    Palya(Nehezseg nehezseg);

    /// @brief A bombákat helyezi le a pályára, ahova nem kerül bomba, az egyelőre NULL pointer lesz
    /// @param nehezseg - ennek megfelelő számú bomba generálódik
    /// @param bombak - ebben tárolja el a függvény a Bomba mezőkre mutató pointereket, ami később, az üres mezők inicializálásakor kelleni fog
    void bomba_init(const Nehezseg& nehezseg);

    /// @brief Az ures mezőket inicializálja,
    /// @param bombak - ez alapján kerül beállításra az adott ures mező bombaszomszédainak száma
    void ures_init();

    /// @brief A játék legelején felfed egy kis részletet a játéból
    void kezdes();

    /// @brief A bejövő eseményt a megfelelő mezőnek kidelegálja
    /// @param event
    /// @return A visszatérési értékében jelzi a Jatek osztálynak, hogy az adott esemény után a játékállapot mi lett
    JatekAllapot esemeny_kezel(sf::Event& event);

    /// @brief A pálya megjelenítését végzi a paraméterül kapott ablakra
    /// @param target - Erre rajzol
    void megjelenit(sf::RenderWindow& target);

    /// @brief A tesztelést segítő getter
    /// @return A mezők heterogén kollekcióját adja vissza
    const std::array<std::array<Mezo*, 14>, 14>& getPalya() const{
        return mezok;
    }
    /// @brief A tesztelést segítő getter
    /// @return A mezők heterogén kollekcióját adja vissza
    std::array<std::array<Mezo*, 14>, 14>& getPalya(){
        return mezok;
    }

    /// @brief Getter a teszteléshez
    /// \return Mennyi a még fel nem fedett üres mezők száma
    int getUres() const{
        return ures_mezok;
    }

    /// @brief Getter a teszteléshez
    /// @return Bomba mező lett-e felfedve
    bool getFelrobbant() const{
        return felrobbant;
    }

    /// @brief Destruktor, egyesével végigmegy a tömbön és a mezőket felszabadítja
    ~Palya();
};




#endif //NHF_UJRA_PALYA_H
