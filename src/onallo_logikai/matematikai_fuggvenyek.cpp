#include "matematikai_fuggvenyek.h"

 bool konnyun_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 215 && y >= 140;
}

bool kozepesen_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 345 && y >= 270;
}

bool nehezen_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 475 && y >= 400;
}

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