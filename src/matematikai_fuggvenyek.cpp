#include "../headerek/matematikai_fuggvenyek.h"




size_t eger_lekepezes(int mit, int eltolas, int mennyivel){
    return (size_t)((mit-eltolas) / mennyivel);
}

bool valid_idx(int idx){
    return idx <= 13 && idx >= 0;
}

bool valid_idx(size_t idx){
    return idx <= 13;
}