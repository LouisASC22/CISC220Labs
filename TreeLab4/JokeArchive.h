//
// Created by Deb on 3/30/2025.
//

#ifndef JOKEARCHIVE_H
#define JOKEARCHIVE_H

#include <iostream>
#include "BSTJokes.h"
using namespace std;

class JokeArchive {
    string jokefile;
    BSTJokes *tree;
public:
    JokeArchive();
    JokeArchive(const string filename);
    void ReadInFile();
    void Menu();
    void strip(string s, string *j);
};



#endif //JOKEARCHIVE_H
