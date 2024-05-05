
#include "../Palya/palya.h"
#include "../Palya/Random/palya_feltoltes/Random.h"
#include "SFML/Graphics.hpp"


#include <gtest/gtest.h>




/// 4db Bomba van a pályán, a következő koordinátákkal rendelkeznek: (5,2) ; (4,3) ; (4,4) ; (5,4)

TEST(PalyaInicializalas, felfedetlenseg) {
    Palya palya(teszt);
    for(size_t i = 0; i< 14; i++){
        for(size_t j = 0; j < 14; j++){
            EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedetlen);
        }
    }
}

TEST(PalyaInicializalas, bomba_init){
    Palya palya(teszt);
    EXPECT_TRUE(palya.getPalya()[5][2]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[4][3]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[4][4]->IsBomb());
    EXPECT_TRUE(palya.getPalya()[5][4]->IsBomb());


}

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

// meg kell nézni
TEST(Jatek_palya_esemenykezeles, palyan_kivul_kattintas){
    Palya palya(teszt);
    sf::Event bal_kattintas, jobb_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    jobb_kattintas.type = sf::Event::MouseButtonPressed;
    jobb_kattintas.mouseButton.button = sf::Mouse::Right;
    for(int i = 0; i < 800; i++){
        jobb_kattintas.mouseButton.x = i;
        bal_kattintas.mouseButton.x = i;
        for(int j = 0; j< 20; j++){
            jobb_kattintas.mouseButton.y = j;
            bal_kattintas.mouseButton.y = j;
            EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
            EXPECT_EQ(palya.esemeny_kezel(jobb_kattintas), jatek);
        }
        for(int j = 581; j < 600; j++){
            jobb_kattintas.mouseButton.y = j;
            bal_kattintas.mouseButton.y = j;
            EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
            EXPECT_EQ(palya.esemeny_kezel(jobb_kattintas), jatek);
        }
    }
    for(int j = 20; j < 581; j++){
        jobb_kattintas.mouseButton.y = j;
        bal_kattintas.mouseButton.y = j;
        for(int i = 0; i < 120; i++) {
            jobb_kattintas.mouseButton.x = i;
            bal_kattintas.mouseButton.x = i;
            EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
            EXPECT_EQ(palya.esemeny_kezel(jobb_kattintas), jatek);
        }
        for(int i = 681; i < 801; i++){
            jobb_kattintas.mouseButton.x = i;
            bal_kattintas.mouseButton.x = i;
            EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), jatek);
            EXPECT_EQ(palya.esemeny_kezel(jobb_kattintas), jatek);
        }

    }
}

TEST(Jatek_mezo_esemenykezeles, flageles_visszaflageles){
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

/// üres mezők előbbre

TEST(Jatek, bombara_lepes_palya_szemszogebol_1){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    bal_kattintas.mouseButton.x = 120 + 20 + 40*2;
    bal_kattintas.mouseButton.y = 20 + 20 + 5*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

TEST(Jatek, bombara_lepes_palya_szemszogebol_2){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    bal_kattintas.mouseButton.x = 120 + 20 + 40*3;
    bal_kattintas.mouseButton.y = 20 + 20 + 4*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

TEST(Jatek, bombara_lepes_palya_szemszogebol_3){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    bal_kattintas.mouseButton.x = 120 + 20 + 40*4;
    bal_kattintas.mouseButton.y = 20 + 20 + 4*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

TEST(Jatek, bombara_lepes_palya_szemszogebol_4){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    bal_kattintas.mouseButton.x = 120 + 20 + 40*4;
    bal_kattintas.mouseButton.y = 20 + 20 + 5*40;
    EXPECT_EQ(palya.esemeny_kezel(bal_kattintas), vereseg);
}

TEST(Jatek, bombara_lepes_mezo_szempontjabol_1){
    Palya palya(teszt);
    sf::Event bal_kattintas;
    bal_kattintas.type = sf::Event::MouseButtonPressed;
    bal_kattintas.mouseButton.button = sf::Mouse::Left;
    palya.getPalya()[5][2]->esemeny_kezel(bal_kattintas);
}

//TEST(Jatek, bombaval_szomszedosra_lepek){}
/*
TEST(Jatek, bombaszomszed_nelkulire_lepek){
    sf::Event eger;
    eger.type = sf::Event::MouseButtonPressed;
    eger.mouseButton.button = sf::Mouse::Left;


}*/


