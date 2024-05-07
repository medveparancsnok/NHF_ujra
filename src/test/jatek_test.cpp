
#include "../Palya/Palya.h"
#include "SFML/Graphics.hpp"
#include "test_segedlet.h"


#include <gtest/gtest.h>






/// 4db Bomba van a pályán, a következő koordinátákkal rendelkeznek: (5,2) ; (4,3) ; (4,4) ; (5,4)


/// @brief A pálya mezői mind helyesen felfedetlenné válnak-e a kezdetén
TEST(PalyaInicializalas, felfedetlenseg) {
    Palya palya(teszt);
    for(size_t i = 0; i< 14; i++){
        for(size_t j = 0; j < 14; j++){
            EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedetlen);
        }
    }
}

/// @brief A megfelelő cellák bombának inicializálódnak
TEST(PalyaInicializalas, bomba_init){
    Palya palya(teszt);
    EXPECT_TRUE(palya.getPalya()[5][2]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[4][3]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[4][4]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[5][4]->IsBomb());


}

/// @brief A megfelelő cellák üresnek lettek-e generálva
TEST(PalyaInicializalas, ures_init){
    Palya palya(teszt);
    for(size_t i = 0; i< 13; i++){
        for(size_t j = 0; j < 13; j++){
            if((!(i == 5 && (j == 2 || j == 4)) && !(i == 4 && (j == 3 || j == 4)))){
                EXPECT_FALSE(palya.getPalya()[i][j]->IsBomb());
            }
        }
    }

}
/// @brief Üres mezők szomszédjainak generálását teszteli
TEST(PalyaInicializalas, ures_szomszedok){
    Palya palya(teszt);
    for(size_t i =0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            if(!palya.getPalya()[i][j]->IsBomb()){
                Ures *vizsgalando = dynamic_cast<Ures*>(palya.getPalya()[i][j]);
                if(((j == 1 && (i == 4 || i == 5 || i == 6))) ||
                        (j == 2 && (i == 3 || i == 6)) ||
                        (j == 4 && i == 6) ||
                        (j == 5 && (i == 3 || i == 6))){
                    EXPECT_EQ(vizsgalando->getBomba_szomszedok(), 1u);
                }
                else if((j == 2 && i == 4) || (j == 3 && (i == 3 || i == 6)) || (j == 4 && i == 3) ||
                        (j == 5 && (i == 4 || i == 5))){
                    EXPECT_EQ(vizsgalando->getBomba_szomszedok(), 2u);
                }
                else if (j == 3 && i == 5){
                    EXPECT_EQ(vizsgalando->getBomba_szomszedok(), 4u);
                }
                else{
                    EXPECT_EQ(vizsgalando->getBomba_szomszedok(), 0u);
                }
            }
        }
    }
}


/// @brief A mező esemeny_kezel függvényét teszteli
/// Először felfedek minden mezőt, megvizsgálom, hogy ezt követően semmire nem reagálnak már a mezők (nem lehet hibát generálni)
TEST(Mezo_esemenykezel, felfedes){
    Palya palya(teszt);
    sf::Event kattintas;
    kattintas.type = sf::Event::MouseButtonPressed;
    kattintas.mouseButton.button = sf::Mouse::Left;
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            Mezo* vizsgalando = palya.getPalya()[i][j];
            vizsgalando->esemeny_kezel(kattintas);
            EXPECT_EQ(vizsgalando->getAllapot(), felfedett);
        }
    }
}

/// @brief Flagelést vizsgálja
TEST(Mezo_esemenykezel, flageles_visszaflageles){
    Palya palya(teszt);
    sf::Event jobb_kattintas;
    jobb_kattintas.type = sf::Event::MouseButtonPressed;
    jobb_kattintas.mouseButton.button = sf::Mouse::Right;
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            Mezo* vizsgalando = palya.getPalya()[i][j];
            vizsgalando->esemeny_kezel(jobb_kattintas);
            EXPECT_EQ(vizsgalando->getAllapot(), flagged);
            vizsgalando->esemeny_kezel(jobb_kattintas);
            EXPECT_EQ(vizsgalando->getAllapot(), felfedetlen);
        }
    }
}
/// @brief Azt teszteli, hogy, ha rálépek egy olyan mezőre, ami bombával szomszédos, akkor
/// csak ő fedődik fel és az üres mezők száma eggyel csökken,
TEST(Ures_esemenykezel, szomszedos_ramleptel){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    std::vector<std::pair<size_t , size_t>> szomszedos;
    szomszedos_init(szomszedos);
    size_t mezo = random(0,szomszedos.size());
    palya.getPalya()[(szomszedos[mezo].first)][(szomszedos[mezo].second)]->esemeny_kezel(bal_kattintas);
    EXPECT_EQ(palya.getPalya()[(szomszedos[mezo].first)][(szomszedos[mezo].second)]->getAllapot(), felfedett);
    /// Mivel 4db bomba van, illetve egy szomszédos akit felfedtem
    EXPECT_EQ(palya.getUres(), 14 * 14 - 5);
    for(size_t i = 0; i < 14;i++){
        for(size_t j = 0; j < 14; j++){
            if(i != szomszedos[mezo].first && j != szomszedos[mezo].second){
                EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedetlen);
            }
        }
    }
}

/// @brief Azt vizsgálja ha olyan mezőre lépek, ami nem szomszédos bombával, akkor a ramleptel() függvény helyesen meghívja-es a
/// felderito_BFS() függvényt, a név pedig azért esemenykezel, mivel ebbe
/// a tesztcsaládba szerveztem
TEST(Ures_esemenykezel, szomszed_nelkuli_ramleptel){
    Palya palya(teszt);
    /// segédtömb, ami eltárolja az összes koordinátapárt ami olyan mezőt takar, ami nem szomszédos bombával
    std::vector<std::pair<size_t , size_t>> szomszed_nelkuliek;
    szomszed_nelkuli_init(szomszed_nelkuliek);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// random kivlasztok egyet, amjd felfedem
    size_t mezo = random(0, szomszed_nelkuliek.size());
    palya.getPalya()[szomszed_nelkuliek[mezo].first][szomszed_nelkuliek[mezo].second]->esemeny_kezel(bal_kattintas);
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            if((i == 4 && (j == 3 || j == 4)) || (i == 5 && (j == 2 || j== 3 || j == 4))){
                EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedetlen);
            }
            else{
                EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedett);
            }
        }
    }
}

/// @brief Bomba ramleptel() függvénye tesztelődik, azaz megfelelően állítja-e be a Pálya felrobbant adattagját
TEST(Bomba_esemenykezel, bomba_1_ramleptel){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// Az (5, 2) koordinátán lévő bomba
    palya.getPalya()[5][2]->esemeny_kezel(bal_kattintas);
    EXPECT_TRUE(palya.getFelrobbant());
    EXPECT_EQ(palya.getPalya()[5][2]->getAllapot(), felfedett);
}

/// @brief Bomba ramleptel() függvénye tesztelődik, azaz megfelelően állítja-e be a Pálya felrobbant adattagját
TEST(Bomba_esemenykezel, bomba_2_ramleptel){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// Az (5, 2) koordinátán lévő bomba
    palya.getPalya()[4][3]->esemeny_kezel(bal_kattintas);
    EXPECT_TRUE(palya.getFelrobbant());
    EXPECT_EQ(palya.getPalya()[4][3]->getAllapot(), felfedett);
}

/// @brief Bomba ramleptel() függvénye tesztelődik, azaz megfelelően állítja-e be a Pálya felrobbant adattagját
TEST(Bomba_esemenykezel, bomba_3_ramleptel){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// Az (4, 4) koordinátán lévő bomba
    palya.getPalya()[4][4]->esemeny_kezel(bal_kattintas);
    EXPECT_TRUE(palya.getFelrobbant());
    EXPECT_EQ(palya.getPalya()[4][4]->getAllapot(), felfedett);
}

/// @brief Bomba ramleptel() függvénye tesztelődik, azaz megfelelően állítja-e be a Pálya felrobbant adattagját
TEST(Bomba_esemenykezel, bomba_4_ramleptel){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// Az (5, 4) koordinátán lévő bomba
    palya.getPalya()[5][4]->esemeny_kezel(bal_kattintas);
    EXPECT_TRUE(palya.getFelrobbant());
    EXPECT_EQ(palya.getPalya()[5][4]->getAllapot(), felfedett);
}

/// @brief Pálya eseménykezelése megfelelő értékkel tér-e vissza, ha bombára lépek
TEST(Palya_esemenykezel, vereseg_1){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// (5, 2) koordinátás bomba
    bal_kattintas.mouseButton.x = 120 + 20 + 40*2;
    bal_kattintas.mouseButton.y = 20 + 20 + 5*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

/// @brief Pálya eseménykezelése megfelelő értékkel tér-e vissza, ha bombára lépek
TEST(Palya_esemenykezel, vereseg_2){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// (4, 3) koordinátás bomba
    bal_kattintas.mouseButton.x = 120 + 20 + 40*3;
    bal_kattintas.mouseButton.y = 20 + 20 + 4*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

/// @brief Pálya eseménykezelése megfelelő értékkel tér-e vissza, ha bombára lépek
TEST(Palya_esemenykezel, vereseg_3){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// (4, 4) koordinátás bomba
    bal_kattintas.mouseButton.x = 120 + 20 + 40*4;
    bal_kattintas.mouseButton.y = 20 + 20 + 4*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

/// @brief Pálya eseménykezelése megfelelő értékkel tér-e vissza, ha bombára lépek
TEST(Palya_esemenykezel, vereseg_4){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// (5, 4) koordinátás bomba
    bal_kattintas.mouseButton.x = 120 + 20 + 40*4;
    bal_kattintas.mouseButton.y = 20 + 20 + 5*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}



/// @brief mind a Pálya esemenykezel függvényét teszteli, ha olyan mezőre lépek, ami bombával szomszédos
TEST(Palya_esemenykezel, bombaval_szomszedosra_lepek){
    Palya palya(teszt);
    /// segédtömb, ami minden olyan koordinátapárt tartalmaz, ami olyan mezőt takar, ami szomszédos bombával
    std::vector<std::pair<size_t , size_t >> szomszedos;
    szomszedos_init(szomszedos);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// az összes bombával szomszédos mezőt felfedem
    for(size_t i = 0; i < szomszedos.size(); i++){
        bal_kattintas.mouseButton.x = 125 + 40 * (int)szomszedos[i].second;
        bal_kattintas.mouseButton.y = 15 + 40 * (int)szomszedos[i].first;
        EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
    }
}

/// @brief Pálya eseménykezel függvényét teszteli, ha olyan mezőre lépek, ami nem szomszédos bombával
TEST(Palya_esemenykezel, bombaval_nem_szomszedosra_lepek){
    Palya palya(teszt);
    /// segédtömb, ami eltárolja az összes koordinátapárt ami olyan mezőt takar, ami nem szomszédos bombával
    std::vector<std::pair<int, int>> szomszed_nelkuliek;
    szomszed_nelkuli_init(szomszed_nelkuliek);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// random egyet kiválasztok, majd felfedem
    size_t mezo = random(0, szomszed_nelkuliek.size());
    bal_kattintas.mouseButton.x = 125 + 40 * szomszed_nelkuliek[mezo].second;
    bal_kattintas.mouseButton.y = 15 + 40 * szomszed_nelkuliek[mezo].first;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
}

/// @brief Azt teszteli, hogy meg lehet-e nyerni a játékot
TEST(Palya_esemenykezel, gyozelem){
    Palya palya(teszt);
    std::vector<std::pair<int, int>> szomszed_nelkuliek;
    szomszed_nelkuli_init(szomszed_nelkuliek);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    /// egy bombával nem szomszédos mezőre lépek, ez felfed minden nem bombát tartalmazó mezőt, kivéve egyet
    size_t mezo = random(0, szomszed_nelkuliek.size());
    bal_kattintas.mouseButton.x = 125 + 40 * szomszed_nelkuliek[mezo].second;
    bal_kattintas.mouseButton.y = 15 + 40 * szomszed_nelkuliek[mezo].first;
    palya.esemeny_kezel(bal_kattintas);
    /// a maradék egyet itt fedem fel
    bal_kattintas.mouseButton.x = 125 + 40 * 3;
    bal_kattintas.mouseButton.y = 15 + 40 * 5;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), gyozelem);
}


