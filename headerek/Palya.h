//
// Created by Otthon on 2024. 04. 16..
//

#ifndef NHF_UJRA_PALYA_H
#define NHF_UJRA_PALYA_H

#include "Bomba.h"
#include "Mezo.h"
#include "Ures.h"
#include <array>
#include "Nehezseg.h"
#include "Jatekallapot.h"
#include "Random.h"
#include "Jatekallapot.h"
#include "matematikai_fuggvenyek.h"
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
    /// @brief Konstruktor, ami a pályán határozza meg véletlenszerűen, hogy mely mezők legyenek bombák és melyek üresek, legelőször
    /// a mezők grafikus megjelenítéséhez szükséges adattagokat inicializálja, majd a bombákat a bomba_init függvénnyel
    /// ezt követően az üres mezőket az ures_init() függvénnyel, amjd pedig, amennyiben nem tesztmódban fut a program, akkor
    /// meghívja a kezdes() függvényt
    /// \param nehezseg - ennek megfelelő nehézségű pálya generálódik
    Palya(Nehezseg nehezseg);

    /// @brief A bombákat helyezi le a pályára, ahova nem kerül bomba, az egyelőre NULL pointer lesz, a bombákra mutató pointereket
    /// eltárolja az std::vector<Mezo*> bombak adattagjában, továbbá, ha az adott mező bomba, akkor csökkenti eggyel
    /// az ures_mezok szamlalot eggyel
    /// @param nehezseg - ennek megfelelő számú bomba generálódik
    /// @param bombak - ebben tárolja el a függvény a Bomba mezőkre mutató pointereket, ami később, az üres mezők inicializálásakor kelleni fog
    void bomba_init(const Nehezseg& nehezseg);

    /// @brief A pálya által tartalmazott mezők megjelenítéséhez szükséges eszközöket tölti be
    void grafika_init();

    /// @brief Az ures mezőket inicializálja, úgy, hogy végig megy ismét a pályán és ahol NULL pointer volt, ott foglal egy
    /// új Ures mezőre mutató pointert dinamikusan, megfelelő paraméterezéssel, továbbá az adott mező setSzomszedok függvényét is
    /// meghívja, ha az adott mező nem szomszédos senkivel, akkor a mező indexeit eltárolja a szomszed_nelkuliek
    /// tömbjében
    /// @param bombak - ez alapján kerül beállításra az adott ures mező bombaszomszédainak száma
    void ures_init();

    /// @brief A játék legelején felfed egy kis részletet a játéból, a felfedendő mező random kerül kiválasztásra a
    /// szomszed_nelkuliek tombbol
    void kezdes();

    /// @brief A bejövő eseményt a megfelelő mezőnek kidelegálja, ha a felrobbant adattagja igaz, akkor vereséggel tér vissza, ha
    /// az ures_mezok adattagja egyenlő a nullával, akkor győzelemmel tér vissza, különben játék állapottal tér vissza
    /// @param event
    /// @return A visszatérési értékében jelzi a Jatek osztálynak, hogy az adott esemény után a játékállapot mi lett
    JatekAllapot esemeny_kezel(sf::Event& event);

    /// @brief A pálya megjelenítését végzi a paraméterül kapott ablakra, egy kettős forciklusban minden egyes általa
    /// tartalmazott mezőnek meghívja a megjelenítő függvényét
    /// @param target - Erre rajzol
    void megjelenit(sf::RenderWindow& target);

    /// @brief A tesztelést segítő getter
    /// @return A mezők heterogén kollekcióját adja vissza
    std::array<std::array<Mezo*, 14>, 14>& getPalya();

    /// @brief Getter a teszteléshez
    /// \return Mennyi a még fel nem fedett üres mezők száma
    int getUres() const;

    /// @brief Getter a teszteléshez
    /// @return Bomba mező lett-e felfedve
    bool getFelrobbant() const;

    /// @brief Destruktor, egyesével végigmegy a tömbön és a mezőket felszabadítja
    ~Palya();
};




#endif //NHF_UJRA_PALYA_H
