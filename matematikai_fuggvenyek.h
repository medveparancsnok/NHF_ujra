
inline bool konnyun_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 215 && y >= 140;
}

inline bool kozepesen_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 345 && y >= 270;
}

inline bool nehezen_belul(int x, int y){
    return x <=550 && x >= 250 && y <= 475 && y >= 400;
}

inline bool vissza_lep(sf::Event& e){
    return e.mouseButton.x >= 0 && e.mouseButton.x <=90 &&e.mouseButton.y >= 570 && e.mouseButton.y <= 600;
}