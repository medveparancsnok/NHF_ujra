//
// Created by bened on 2024. 04. 05..
//

#include "../headerek/Random.h"


size_t random(size_t a, size_t b){
    static std::random_device eszkoz;
    std::uniform_int_distribution<size_t> eloszlas(a,b);
    return eloszlas(eszkoz);
}


