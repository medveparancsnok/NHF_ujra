
#include "Alkalmazas.h"

Alkalmazas::Alkalmazas():ablak(sf::VideoMode(800,600), "Aknakereso", sf::Style::Default) {
    font.loadFromFile("arial.ttf");
    FoMenu fomenu(stack, font);
    stack.push(&fomenu);
}

void Alkalmazas::Run(){

    while(ablak.isOpen()){
        sf::Event esemeny;
        while(ablak.pollEvent(esemeny)){
            if(esemeny.type == sf::Event::Closed){
                while(!stack.empty()){
                    stack.pop();
                }
                ablak.close();
            }
            else{
                stack.top()->esemeny_kezel(esemeny);
            }
        }
    }
    ablak.clear(sf::Color(192, 192, 192));

    stack.top()->megjelenit(ablak);

    ablak.display();
}