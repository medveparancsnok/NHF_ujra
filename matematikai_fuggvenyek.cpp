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

bool palyan_belul(int x, int y){
    return x >= 120 && x <= 680 && y >= 20 && y <= 580;
}

size_t eger_lekepezes(size_t mit, size_t eltolas, size_t mennyivel){
    return ((mit-eltolas) / mennyivel);
}

bool valid_idx(int idx){
    return idx <= 13 && idx >= 0;
}