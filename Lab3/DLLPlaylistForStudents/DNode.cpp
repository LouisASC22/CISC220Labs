//
// Created by luigi on 3/12/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "DNode.hpp"
using namespace std;

DNode::DNode(std::string s, std::string a, int lenmin, int lensec) {
    string name = s;
    string artist = a;
    int durationMin = lenmin;
    int durationSec = lensec;
    next = nullptr;
    prev = nullptr;
};