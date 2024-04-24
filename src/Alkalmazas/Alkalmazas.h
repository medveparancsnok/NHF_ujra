

#ifndef NHF_UJRA_ALKALMAZAS_H
#define NHF_UJRA_ALKALMAZAS_H
#include "../Menuk/FoMenu.h"



class Alkalmazas {
    sf::RenderWindow ablak;
    std::stack<Menu *> stack;
    sf::Font font;
public:
    Alkalmazas();

    void Run();
};


#endif //NHF_UJRA_ALKALMAZAS_H
