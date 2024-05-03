#include "matematikai_fuggvenyek.h"


bool vissza_lep(sf::Event& e){
    return e.mouseButton.x >= 0 && e.mouseButton.x <=90 &&e.mouseButton.y >= 570 && e.mouseButton.y <= 600;
}


unsigned long long eger_lekepezes(int mit, int eltolas, int mennyivel){
    return (unsigned long long)((mit-eltolas) / mennyivel);
}

bool valid_idx(int idx){
    return idx <= 13 && idx >= 0;
}

bool valid_idx(size_t idx){
    return idx <= 13;
}