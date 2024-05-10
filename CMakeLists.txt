cmake_minimum_required(VERSION 3.23)
project(jatek VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest QUIET)
if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif ()

function(add_compile_options target)
    target_compile_options(${target}
            PRIVATE
            -Werror
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
    )

endfunction()

add_library(${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_lib
        PUBLIC
        include
)
target_sources(${PROJECT_NAME}_lib
        PRIVATE
        src/Alkalmazas.cpp
        src/Bomba.cpp
        src/Felirat.cpp
        src/FoMenu.cpp
        src/grafikai_fuggvenyek.cpp
        src/Jatek.cpp
        src/matematikai_fuggvenyek.cpp
        src/Menu.cpp
        src/MenuFelirat.cpp
        src/Mezo.cpp
        src/Palya.cpp
        src/Random.cpp
        src/Ures.cpp
)
add_compile_options(${PROJECT_NAME}_lib)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
        PRIVATE
        src/main.cpp
)
add_compile_options(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAME}_lib
)

enable_testing()

add_executable(${PROJECT_NAME}_test)
target_sources(${PROJECT_NAME}_test
        PRIVATE
        test/jatek_test.cpp
)
add_compile_options(${PROJECT_NAME}_test)
target_link_libraries(${PROJECT_NAME}_test
        PRIVATE
        ${PROJECT_NAME}_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)

set(BUILD_SHARED_LIBS OFF)
set(SFML_DIR D:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(${PROJECT_NAME}_lib PUBLIC sfml-system sfml-window sfml-graphics sfml-audio)