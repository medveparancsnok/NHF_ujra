

#include "Alkalmazas.h"


void App::Init() {
    jatekmenet.init();

}

void App::Run(){
    Init();

    sf::Event esemeny;

    while(ablak.isOpen()){
        while(ablak.pollEvent(esemeny)){
            if(esemeny.type == sf::Event::Closed){
                ablak.close();
            }
            if(esemeny.type == sf::Event::MouseButtonPressed){
                jatekmenet.esemenylekezel(esemeny);
            }
        }
        jatekmenet_grafika.megjelenit(ablak);
    }
}