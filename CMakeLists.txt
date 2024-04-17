cmake_minimum_required(VERSION 3.24)
project(NHF)

set(CMAKE_CXX_STANDARD 17)

add_executable(NHF main.cpp
        megjelenites_kiegeszites.cpp
        FoMenu.cpp
        main.cpp
)


target_compile_options(NHF
        PRIVATE
        -Werror -Wall -Wextra -Wpedantic -Wconversion
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(NHF sfml-system sfml-window sfml-graphics sfml-audio)
