//
// Created by Otthon on 2024. 04. 16..
//


#include "Palya.h"
#include "grafikai_fuggvenyek.h"

Palya::Palya(Nehezseg nehezseg){
    felrobbant = false;

    flagSprite = sprite_betolt("Flag.png");
    bombaSprite = sprite_betolt("Bomba.png");

    ures_mezok = nagysag * nagysag;
    for(unsigned long long i = 0; i < nagysag; i++){
        for(unsigned long long j = 0; j< nagysag; j++){
            flagSprite.setPosition((float)(120 + j* 40 + 2), (float)(20 + i* 40 + 2));
            bombaSprite.setPosition((float)(120 + j* 40 + 2), (float)(20 + i* 40 + 2));
            switch(nehezseg){
                case konnyu:{
                    if(random(0,9) == 0){
                        mezok[i][j] = new Bomba();
                        ures_mezok--;
                    }
                    else {
                        mezok[i][j] = new Mezo();
                    }
                }
                    break;
                case kozepes:{
                    if(random(0,6) == 0){
                        mezok[i][j] = new Mezo(felfedetlen, true);
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = new Mezo();
                    }
                }
                    break;
                case nehez:{
                    if(random(0,4) == 0){
                        mezok[i][j] = new Mezo(felfedetlen, true);
                        ures_mezok--;
                    }
                    else{
                        mezok[i][j] = new Mezo();
                    }
                }
                    break;

                default:{
                    throw "Nehezsegi fok rosszul lett megadva";
                }
            }
        }
    }
}



