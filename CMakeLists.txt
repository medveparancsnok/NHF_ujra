cmake_minimum_required(VERSION 3.24)
project(NHF)

set(CMAKE_CXX_STANDARD 11)

add_executable(NHF src/main.cpp
        src/Menuk/FoMenu.cpp
        src/main.cpp
        src/onallo_logikai/matematikai_fuggvenyek.h
        src/Segedosztalyok/Grafikai/MenuFelirat.cpp
        src/Alkalmazas/Alkalmazas.cpp
        src/Mezok/Bomba.cpp
        src/Segedosztalyok/Grafikai/JatekFelirat.cpp
        src/Menuk/Jatek.cpp
        src/onallo_logikai/grafikai_fuggvenyek.cpp
        src/Menuk/Menu.cpp
        src/Mezok/Mezo.cpp
        src/Palya/Palya.cpp
        src/Mezok/Ures.cpp
        src/Palya/Random/palya_feltoltes/Random.cpp
        src/onallo_logikai/matematikai_fuggvenyek.cpp
)


target_compile_options(NHF
        PRIVATE
        -Werror -Wall -Wextra -Wpedantic -Wconversion
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(NHF sfml-system sfml-window sfml-graphics sfml-audio)
