

#ifndef NHF_UJRA_APP_H
#define NHF_UJRA_APP_H
#include <SFML/Graphics.hpp>
#include "Jatekmenet.h"
#include "Ablak.h"


class App {
    Jatekmenet jatekmenet;
    Ablak ablak;
public:
    App();

    void Init();

    void Run();
};


#endif //NHF_UJRA_APP_H
