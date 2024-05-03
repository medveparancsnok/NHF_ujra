cmake_minimum_required(VERSION 3.24)
project(NHF)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(NHF
        src/Menuk/FoMenu.cpp
        src/onallo_logikai/matematikai_fuggvenyek.h
        src/Segedosztalyok/Grafikai/Felirat.cpp
        src/Alkalmazas/Alkalmazas.cpp
        src/Mezok/Bomba.cpp
        src/Menuk/Jatek.cpp
        src/onallo_logikai/grafikai_fuggvenyek.cpp
        src/Menuk/Menu.cpp
        src/Mezok/Mezo.cpp
        src/Palya/Palya.cpp
        src/Mezok/Ures.cpp
        src/Palya/Random/palya_feltoltes/Random.cpp
        src/onallo_logikai/matematikai_fuggvenyek.cpp
        src/test/jatek_test.cpp
        src/Segedosztalyok/Grafikai/MenuFelirat.cpp


)


target_compile_options(NHF
        PRIVATE
        -Werror -Wall -Wextra -Wpedantic -Wconversion
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(NHF sfml-system sfml-window sfml-graphics sfml-audio)

target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
)

target_compile_definitions(NHF PRIVATE
)
