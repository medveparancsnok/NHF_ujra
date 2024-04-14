

#ifndef NHF_UJRA_APP_H
#define NHF_UJRA_APP_H
#include <SFML/Graphics.hpp>
#include "Jatekmenet.h"
#include "Ablak.h"
#include "Jatekmenet_grafika.h"


class App {
    Jatekmenet jatekmenet;
    Jatekmenet_grafika jatekmenet_grafika;
    sf::RenderWindow ablak;
public:

    void Init();

    void Run();
};


#endif //NHF_UJRA_APP_H
