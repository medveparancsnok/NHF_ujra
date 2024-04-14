cmake_minimum_required(VERSION 3.24)
project(NHF_ujra)

set(CMAKE_CXX_STANDARD 11)

add_executable(NHF_ujra
        App.cpp
        App.h
        Jatek.cpp
        Jatek.h
        Menu.cpp
        Menu.h
        Palya.cpp
        Palya.h
        Mezo.cpp
        Mezo.h
        Jatek_grafika.cpp
        Jatek_grafika.h
        Menu_grafika.cpp
        Menu_grafika.h
        Mezo_grafika.cpp
        Mezo_grafika.h
        Palya_grafika.cpp
        Palya_grafika.h
        Ablak.cpp
        Ablak.h
        Jatekmenet.cpp
        Jatekmenet.h
)



target_compile_options(NHF_ujra
        PRIVATE
        -Werror -Wall -Wextra -Wpedantic -Wconversion
)



set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(NHF_ujra sfml-system sfml-window sfml-graphics sfml-audio)
