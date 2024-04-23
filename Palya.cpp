


#include "Palya.h"
#include "grafikai_fuggvenyek.h"

Palya::Palya(Nehezseg nehezseg, sf::Font& font): font(font){
    felrobbant = false;

    if(!flagTextura.loadFromFile("Flag.png")){
        std::cout << "baj van" << std::endl;
    }
    flagSprite.setTexture(flagTextura);
    flagSprite.setTextureRect(sf::IntRect(0,0, 40, 40));

    if(!bombaTextura.loadFromFile("Bomba.png")){
        std::cout << "baj van" << std::endl;
    }
    bombaSprite.setTexture(bombaTextura);
    bombaSprite.setTextureRect(sf::IntRect(0,0, 40, 40));

    mezo_alap = negyzet_betolt();

    ures_mezok = 14 * 14;
    for(unsigned long long i = 0; i < 14; i++){
        for(unsigned long long j = 0; j< 14; j++){
            flagSprite.setPosition((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1));
            bombaSprite.setPosition((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1));
            mezo_alap.setPosition(sf::Vector2f((float)(120 + j * 40), (float)(20 + i * 40)));
            switch(nehezseg){
                case konnyu:{
                    if(random(0,9) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        eloszlas[i][j] = true;
                        ures_mezok--;
                    }
                    else {
                        mezok[i][j] = new Ures(eloszlas, ures_mezok, flagSprite, mezo_alap, font);
                        eloszlas[i][j] = false;
                    }
                }
                break;
                case kozepes:{
                    if(random(0,6) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        eloszlas[i][j] = true;
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = new Ures(eloszlas, ures_mezok, flagSprite, mezo_alap, font);
                        eloszlas[i][j] = false;
                    }
                }
                break;
                case nehez:{
                    if(random(0,4) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        eloszlas[i][j] = true;
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = new Ures(eloszlas, ures_mezok, flagSprite, mezo_alap, font);
                        eloszlas[i][j] = false;
                    }
                }
                break;
                default:{
                }
            }
        }
    }
}


void Palya::megjelenit(sf::RenderWindow &target) {
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            mezok[i][j]->megjelenit(target);
        }
    }
}
JatekAllapot Palya::esemeny_kezel(sf::Event &esemeny) {
    if(palyan_belul(esemeny.mouseButton.x, esemeny.mouseButton.y)){
        size_t i = eger_lekepezes(esemeny.mouseButton.y, 10, 40);
        size_t j = eger_lekepezes(esemeny.mouseButton.x, 120, 40);
        mezok[i][j]->esemeny_kezel(esemeny);
    }
    if(ures_mezok == 0){
        return gyozelem;
    }
    else if(felrobbant){
        return vereseg;
    }
    else{
        return jatek;
    }
}

Palya::~Palya(){
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            delete mezok[i][j];
        }
    }
}



