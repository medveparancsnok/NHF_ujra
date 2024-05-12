cmake_minimum_required(VERSION 3.24)
project(NHF)

set(CMAKE_CXX_STANDARD 11)
set(BUILD_SHARED_LIBS OFF)



find_package(SFML COMPONENTS system window graphics REQUIRED)

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
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target}
                PRIVATE
                -fsanitize=address
                -fno-omit-frame-pointer
        )
        target_link_options(${target}
                PRIVATE
                -fsanitize=address
        )
    endif()
endfunction()



add_library(${PROJECT_NAME}_lib STATIC)
add_compile_options(${PROJECT_NAME}_lib)
target_sources(${PROJECT_NAME}_lib PUBLIC
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
target_include_directories(${PROJECT_NAME}_lib PUBLIC
        headerek
)
target_link_libraries(${PROJECT_NAME}_lib PUBLIC
        sfml-graphics
)

add_executable(${PROJECT_NAME})
add_compile_options(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${PROJECT_NAME}_lib
)

enable_testing()

add_executable(${PROJECT_NAME}_test)
add_compile_options(${PROJECT_NAME})
target_sources(${PROJECT_NAME}_test PRIVATE
        test/jatek_test.cpp
)
target_link_libraries(${PROJECT_NAME}_test PRIVATE
        ${PROJECT_NAME}_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
