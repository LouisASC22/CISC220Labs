//
// Created by luigi on 3/12/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "DNode.hpp"
using namespace std;

DNode::DNode(string t, string a, int lenmin, int lensec) {
    song = new Song();
    song->title = t;
    song->artist = a;
    song->min = lenmin;
    song->sec = lensec;
    next = NULL;
    prev = NULL;
};