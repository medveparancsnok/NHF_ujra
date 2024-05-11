
#include <SFML/Graphics.hpp>

/// @brief Egy kattintást leképez indexxé a pályán
/// \param mit - a kattintás
/// \param eltolas - az ablakon belül honnantól kezdődik a pálya
/// \param mennyivel - milyen hosszú egy cella
/// \return - az index, 0 és 13 közötti egész
size_t eger_lekepezes(int mit, int eltolas, int mennyivel);

///  @brief Egy adoitt indexről leellenőrzi, hogy helyese (0 és 13 között van-e)
/// \param idx - maga, amit ellenőrizni szeretnénk
/// \return Valós-e (true) vagy sem (false)
bool valid_idx(int idx);

/// @brief Az előző függvény overload-olása
bool valid_idx(size_t idx);
