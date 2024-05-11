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

set(TESZT ON)

add_executable(NHF
)
target_sources( NHF PRIVATE
        src/FoMenu.cpp
        src/Felirat.cpp
        src/Alkalmazas.cpp
        src/Bomba.cpp
        src/Jatek.cpp
        src/grafikai_fuggvenyek.cpp
        src/Menu.cpp
        src/Mezo.cpp
        src/Palya.cpp
        src/Ures.cpp
        src/Random.cpp
        src/matematikai_fuggvenyek.cpp
        src/MenuFelirat.cpp
)

if(TESZT)
    target_sources(NHF PRIVATE
            test/jatek_test.cpp
    )

else()
    target_sources(NHF PRIVATE
            src/main.cpp
    )

endif()
target_compile_options(NHF
        PRIVATE
       -Wall -Wextra -Wpedantic -Wconversion

)



set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(NHF sfml-system sfml-window sfml-graphics sfml-audio)

target_link_libraries(NHF
        GTest::gtest_main
)







