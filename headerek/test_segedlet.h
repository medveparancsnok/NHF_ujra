//
// Created by Otthon on 2024. 05. 05..
//

#ifndef NHF_TEST_SEGEDLET_H
#define NHF_TEST_SEGEDLET_H

#include <iostream>
#include <vector>

inline void bombak_init(std::vector<std::pair<int,int>>& bombak){
    bombak.push_back({5,2});
    bombak.push_back({4,3});
    bombak.push_back({4,4});
    bombak.push_back({5,4});

}

inline void szomszedos_init(std::vector<std::pair<size_t ,size_t>>& szomszedos){
    for(int j = 2; j < 6; j++){
        szomszedos.push_back({3,j});
    }
    for(int j = 1; j < 6; j++){
        szomszedos.push_back({6,j});
    }
    szomszedos.push_back({4,1});
    szomszedos.push_back({5,1});
    szomszedos.push_back({4,2});
    szomszedos.push_back({4,5});
    szomszedos.push_back({5,3});
    szomszedos.push_back({5,5});


}

inline void szomszed_nelkuli_init(std::vector<std::pair<int,int>>& szomszed_nelkuliek){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }
    szomszed_nelkuliek.push_back({3,0});
    szomszed_nelkuliek.push_back({3,1});
    szomszed_nelkuliek.push_back({4,0});
    szomszed_nelkuliek.push_back({5,0});
    szomszed_nelkuliek.push_back({6,0});

    for(int i = 3; i < 7; i++){
        for(int j = 6; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }

    for(int i = 7; i < 14; i++){
        for(int j = 0; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }
}

inline void szomszed_nelkuli_init(std::vector<std::pair<size_t ,size_t>>& szomszed_nelkuliek){
    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }
    szomszed_nelkuliek.push_back({3,0});
    szomszed_nelkuliek.push_back({3,1});
    szomszed_nelkuliek.push_back({4,0});
    szomszed_nelkuliek.push_back({5,0});
    szomszed_nelkuliek.push_back({6,0});

    for(size_t i = 3; i < 7; i++){
        for(size_t j = 6; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }

    for(size_t i = 7; i < 14; i++){
        for(size_t j = 0; j < 14; j++){
            szomszed_nelkuliek.push_back({i,j});
        }
    }

}


#endif //NHF_TEST_SEGEDLET_H
