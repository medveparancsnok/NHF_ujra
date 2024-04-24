//
// Created by bened on 2024. 04. 05..
//

#include "Random.h"

int random(int a, int b){
    static std::random_device eszkoz;
    std::uniform_int_distribution<int> eloszlas(a,b);
    return eloszlas(eszkoz);
}


