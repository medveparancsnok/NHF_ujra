
#include "../Palya/palya.h"
#include "../Palya/Random/palya_feltoltes/Random.h"
#include "SFML/Graphics.hpp"


#include <gtest/gtest.h>



TEST(PalyaInicializalas, felfedetlenseg) {
    Palya palya(teszt);
    for(size_t i = 0; i< 14; i++){
        for(size_t j = 0; j < 14; j++){
            EXPECT_EQ(palya.getPalya()[i][j]->getAllapot(), felfedetlen);
        }
    }
}

TEST(PalyaInicializalas, bomba_init){

}

TEST(PalyaInicializalas, ures_init){
    Palya palya(teszt);
    Ures* vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[6][0]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 2u);
    vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[7][6]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 2u);
    vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[0][5]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 1u);
    vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[13][10]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 1u);
    vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[5][12]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 0u);
    vizsgalt = dynamic_cast<Ures*> (palya.getPalya()[12][6]);
    EXPECT_EQ(vizsgalt->getBomba_szomszedok(), 0u);

}

/*TEST(Jatek, ures_felfedezes){
    sf::Event eger;
    eger.type = sf::Event::MouseButtonPressed;
    eger.mouseButton.button = sf::Mouse::Left;


}*/


