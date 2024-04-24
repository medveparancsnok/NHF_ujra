


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

    std::vector<Mezo*> vektor;
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
                        vektor.push_back(mezok[i][j]);
                        ures_mezok--;
                    }
                    else {
                        mezok[i][j] = NULL;
                    }
                }
                break;
                case kozepes:{
                    if(random(0,6) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        vektor.push_back(mezok[i][j]);
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = NULL;
                    }
                }
                break;
                case nehez:{
                    if(random(0,4) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        vektor.push_back(mezok[i][j]);
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = NULL;
                    }
                }
                break;
                default:{
                }
            }
        }
    }
    for(unsigned long long i = 0; i < 14; i++) {
        for (unsigned long long j = 0; j < 14; j++) {
            if(mezok[i][j] == NULL){
                mezok[i][j] = new Ures(ures_mezok, flagSprite, mezo_alap,font);
                Ures* ures = static_cast<Ures*>(mezok[i][j]);
                ures->setSzomszedok(vektor, mezok);
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



