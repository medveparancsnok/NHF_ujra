
#include "Alkalmazas.h"
#include <iostream>

Alkalmazas::Alkalmazas():ablak(sf::VideoMode(800,600), "Aknakereso", sf::Style::Default) {
    ablak.setFramerateLimit(60);
    font.loadFromFile("arial.ttf");
    FoMenu *fomenu = new FoMenu(stack, font);
    stack.push(fomenu);
}

void Alkalmazas::Run(){


    while(ablak.isOpen()){
        sf::Event esemeny;
        while(ablak.pollEvent(esemeny)){
            switch (esemeny.type) {
                case sf::Event::Closed:{
                    while(!stack.empty()){
                        stack.pop();
                    }
                    ablak.close();
                }
                break;
                case sf::Event::MouseButtonPressed:{
                    stack.top()->esemeny_kezel(esemeny);
                }
                break;
                default:{}
                break;
            }
        }

        ablak.clear(sf::Color(192, 192, 192));

        if(!stack.empty()) {
            stack.top()->megjelenit(ablak);
        }

        ablak.display();


    }


}