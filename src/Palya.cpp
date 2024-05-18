


#include "../headerek/Palya.h"
#include "../headerek/grafikai_fuggvenyek.h"


Palya::Palya(Nehezseg nehezseg): ures_mezok(1){
    felrobbant = false;

    grafika_init();

    bomba_init(nehezseg);

    ures_init();

    if(nehezseg != teszt) {
        kezdes();
    }
}

void Palya::grafika_init(){

    if(!flagTextura.loadFromFile("resource/Flag.png")){
        throw "Texturat nem sikerult betolteni";
    }
    flagSprite.setTexture(flagTextura);
    flagSprite.setTextureRect(sf::IntRect(0,0, 40, 40));

    if(!bombaTextura.loadFromFile("resource/Bomba.png")){
        throw "Texturat nem sikerult betolteni";
    }
    bombaSprite.setTexture(bombaTextura);
    bombaSprite.setTextureRect(sf::IntRect(0,0, 40, 40));

    mezo_alap = mezo_alap_betolt();
}

void Palya::bomba_init(const Nehezseg& nehezseg) {
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j< 14; j++){
            flagSprite.setPosition((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1));
            bombaSprite.setPosition((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1));
            mezo_alap.setPosition(sf::Vector2f((float)(120 + j * 40 + 1), (float)(20 + i * 40 + 1)));

            switch(nehezseg){
                case teszt:{
                    if((i == 5 && j == 2) || (i == 4 && j == 3) || (i == 5 && j == 4) || (i == 4 && j == 4)){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        bombak.push_back(mezok[i][j]);
                    }
                    else {
                        mezok[i][j] = NULL;
                    }
                }
                break;
                case konnyu:{
                    if(random(0,9) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        bombak.push_back(mezok[i][j]);
                    }
                    else {
                        mezok[i][j] = NULL;
                    }
                }
                    break;
                case kozepes:{
                    if(random(0,6) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        bombak.push_back(mezok[i][j]);
                    }
                    else{
                        mezok[i][j] = NULL;
                    }
                }
                    break;
                case nehez:{
                    if(random(0,4) == 0){
                        mezok[i][j] = new Bomba(felrobbant, bombaSprite, flagSprite, mezo_alap);
                        bombak.push_back(mezok[i][j]);
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
}


void Palya::ures_init() {
    if(!font.loadFromFile("resource/arial.ttf")){
        throw "Nem sikerult Font-ot betolteni";
    }
    for(size_t i = 0; i < 14; i++) {
        for (size_t j = 0; j < 14; j++) {
            if(mezok[i][j] == NULL){
                ures_mezok += 1;
                flagSprite.setPosition((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1));
                mezo_alap.setPosition(sf::Vector2f((float)(120 + j* 40 + 1), (float)(20 + i* 40 + 1)));
                Ures* ures = new Ures(mezok, ures_mezok,i , j, flagSprite, mezo_alap, font);
                ures->setSzomszedok(bombak);
                if(ures->getBomba_szomszedok() == 0){
                    szomszed_nelkuliek.push_back({i,j});
                }
                mezok[i][j] = ures;
            }
        }
    }
}

void Palya::kezdes() {
    size_t kivalasztott_mezo = random(0, szomszed_nelkuliek.size());
    size_t sor = szomszed_nelkuliek[kivalasztott_mezo].first;
    size_t oszlop = szomszed_nelkuliek[kivalasztott_mezo].second;
    mezok[sor][oszlop]->ramleptel();
}



void Palya::megjelenit(sf::RenderWindow &target) {
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            mezok[i][j]->megjelenit(target);
        }
    }
}

JatekAllapot Palya::esemeny_kezel(sf::Event &esemeny) {
    size_t i = eger_lekepezes(esemeny.mouseButton.y, 10, 40);
    size_t j = eger_lekepezes(esemeny.mouseButton.x, 120, 40);
    if(valid_idx(i) && valid_idx(j)) {
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


std::array<std::array<Mezo*, 14>, 14>& Palya::getPalya(){
    return mezok;
}

int Palya::getUres() const{
    return ures_mezok;
}


bool Palya::getFelrobbant() const{
    return felrobbant;
}

Palya::~Palya(){
    for(size_t i = 0; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            delete mezok[i][j];
        }
    }
}