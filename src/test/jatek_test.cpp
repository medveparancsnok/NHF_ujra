
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
            if(((i != 5 && (j != 2 || j != 4)) && (i != 4 && (j != 3 || j != 4)))){
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

/*TEST(Jatek, ures_felfedezes){
    sf::Event eger;
    eger.type = sf::Event::MouseButtonPressed;
    eger.mouseButton.button = sf::Mouse::Left;


}*/


