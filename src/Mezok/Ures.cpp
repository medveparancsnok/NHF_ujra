

#include "Ures.h"

Ures::Ures(std::array<std::array<Mezo*, 14>, 14>& mezok, int& ures_mezok,size_t sor, size_t oszlop, sf::Sprite &m_flag, sf::RectangleShape &m_alap,
           sf::Font& font, MezoAllapot kezdo): Mezo(m_flag, m_alap, kezdo), mezok(mezok), ures_mezok(ures_mezok),sor(sor), oszlop(oszlop) , szomszedok(font, "0",20, sf::Color::Black, sf::Vector2f(0,0), sf::Text::Bold){}


void Ures::ramleptel() {
    megjelenit_atallit();
    ures_mezok--;
    if(bomba_szomszedok == 0){
        felderito_BFS();
    }
}

void Ures::felderito_BFS() {
    int i = (int) sor;
    int j = (int) oszlop;
    if(valid_idx(i-1) && valid_idx(j-1)){
        mezok[sor-1][oszlop-1]->bal_klikk();
    }
    if(valid_idx(i-1) && valid_idx(j)){
        mezok[sor-1][oszlop]->bal_klikk();
    }
    if(valid_idx(i-1) && valid_idx(j+1)){
        mezok[sor-1][oszlop+1]->bal_klikk();
    }
    if(valid_idx(i) && valid_idx(j-1)){
        mezok[sor][oszlop-1]->bal_klikk();
    }
    if(valid_idx(i) && valid_idx(j+1)){
        mezok[sor][oszlop+1]->bal_klikk();
    }
    if(valid_idx(i+1) && valid_idx(j-1)){
        mezok[sor+1][oszlop-1]->bal_klikk();
    }
    if(valid_idx(i+1) && valid_idx(j)){
        mezok[sor+1][oszlop]->bal_klikk();
    }
    if(valid_idx(i+1) && valid_idx(j+1)){
        mezok[sor+1][oszlop+1]->bal_klikk();
    }
}

void Ures::megjelenit_atallit() {
    m_alap.setFillColor(sf::Color::White);
    szomszedok.setPosition(m_alap.getPosition());
    std::string buffer;
    buffer += (char)('0' + bomba_szomszedok);
    szomszedok.setString(buffer);
}


void Ures::megjelenit(sf::RenderWindow& target) const{
    Mezo::megjelenit(target);
    if(m_allapot == felfedett){
        target.draw(m_alap);
        if(szomszedok.getString() != "0") {
            szomszedok.megjelenit(target);
        }
    }
}

void Ures::setSzomszedok(const std::vector<Mezo*>& bombak) {
    bomba_szomszedok = 0;

    int uj_x = (int)sor;
    int uj_y = (int)oszlop;

    if (valid_idx(uj_x - 1) && valid_idx(uj_y - 1) && Eleme(bombak,  mezok[sor - 1][oszlop - 1])) {
        bomba_szomszedok++;
    }

    if (valid_idx(uj_x - 1) && valid_idx(uj_y) && Eleme(bombak, mezok[sor-1][oszlop])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x - 1) && valid_idx(uj_y + 1) && Eleme(bombak, mezok[sor-1][oszlop+1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x) && valid_idx(uj_y - 1) && Eleme(bombak, mezok[sor][oszlop-1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x) && valid_idx(uj_y + 1) && Eleme(bombak, mezok[sor][oszlop+1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x + 1) && valid_idx(uj_y - 1) && Eleme(bombak, mezok[sor+1][oszlop-1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x + 1) && valid_idx(uj_y) && Eleme(bombak, mezok[sor+1][oszlop])) {
        bomba_szomszedok++;

    }
    if (valid_idx(uj_x + 1) && valid_idx(uj_y + 1) && Eleme(bombak, mezok[sor+1][oszlop+1])) {
        bomba_szomszedok++;
    }
}

bool Eleme(const std::vector<Mezo*>& bombak, const Mezo* vizsgalando){
    for(size_t i = 0; i< bombak.size(); i++){
        if(vizsgalando == bombak[i]){
            return true;
        }
    }
    return false;
}

