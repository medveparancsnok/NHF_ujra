#include <SFML/Graphics.hpp>
#include <iostream>


/// EZEKET KELLENE A PALYA KONSTRUKTORNAK HASZNÁLNI


/// @brief Megjelenítéshez szükséges Sprite betöltését végzi
/// @param sprite - ahova be kell tölteni
/// @param nev - textúra neve, ami a Sprite-ra kerül
void sprite_betolt(sf::Sprite& sprite, const std::string& nev);

/// @brief
/// \param textura
/// \param nev
void textura_betolt(sf::Texture& textura, const std::string& nev);


/// @brief Egy felfedetlen mező megjelenítéséhez szükséges paramétereket állítja be
/// \return A beállított megjelenítési forma
sf::RectangleShape mezo_alap_betolt();

