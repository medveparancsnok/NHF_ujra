

#include "Ures.h"

Ures::Ures(int& ures_mezok,  sf::Sprite &m_flag, sf::RectangleShape &m_alap, sf::Font &font,
           MezoAllapot kezdo): Mezo(m_flag, m_alap, kezdo), ures_mezok(ures_mezok), font(font), szomszedok(font, "0",20, sf::Color::Black, sf::Vector2f(0,0), sf::Text::Bold){}


void Ures::ramleptel() {
    megjelenit_atallit();
    ures_mezok--;
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

void Ures::setSzomszedok(std::vector<Mezo*>& vektor, std::array<std::array<Mezo*, 14>, 14>& mezok) {
    bomba_szomszedok = 0;

    int x = (int)eger_lekepezes((size_t)m_alap.getPosition().x, 10, 40);
    int y = (int)eger_lekepezes((size_t)m_alap.getPosition().y, 120, 40);

    if (valid_idx(x - 1) && valid_idx(y - 1) && Eleme(vektor, mezok[x-1][y-1])) {
        bomba_szomszedok++;
    }

    if (valid_idx(x - 1) && valid_idx(y) && Eleme(vektor, mezok[x-1][y])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x - 1) && valid_idx(y + 1) && Eleme(vektor, mezok[x-1][y+1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x) && valid_idx(y - 1) && Eleme(vektor, mezok[x][y-1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x) && valid_idx(y + 1) && Eleme(vektor, mezok[x][y+1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x + 1) && valid_idx(y - 1) && Eleme(vektor, mezok[x+1][y-1])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x + 1) && valid_idx(y) && Eleme(vektor, mezok[x+1][y])) {
        bomba_szomszedok++;

    }
    if (valid_idx(x + 1) && valid_idx(y + 1) && Eleme(vektor, mezok[x+1][y+1])) {
        bomba_szomszedok++;

    }
}

bool Eleme(const std::vector<Mezo*>& vektor, const Mezo* vizsgalando){
    for(size_t i = 0; i< vektor.size(); i++){
        if(vizsgalando == vektor[i]){
            return true;
        }
    }
    return false;
}