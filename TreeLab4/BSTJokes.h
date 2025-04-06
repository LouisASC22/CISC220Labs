//
// Created by Deb on 3/30/2025.
//

#ifndef BSTJOKES_H
#define BSTJOKES_H
#include <iostream>
#include "TNode.h"
using namespace std;

class BSTJokes {
    friend class JokeArchive;
    TNode *root;
public:
    BSTJokes();
    BSTJokes(string l, string f, string m, string j);
    bool add(string l, string f, string m, string j);
    TNode *find(string l, string f, string m);
    void printTreeIO();
    void printTreeIO(TNode *n);
    void printTreePre();
    void printTreePre(TNode *n);
    void printTreePost();
    void printTreePost(TNode *n);
    void setHeight(TNode *n);
    void removeNoKids(TNode *tmp);
    void remove(string l, string f, string m);
    void removeOneKid(TNode *tmp);
    TNode *findReplacement(TNode *tr);
    void removeTwoKids(TNode *tr);
    ~BSTJokes();
    void clearTree(TNode *tmp);



/*

    int getBalance(TNode *n);
    */




};



#endif //BSTJOKES_H
