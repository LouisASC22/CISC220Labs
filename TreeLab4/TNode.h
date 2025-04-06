//
// Created by Deb on 3/30/2025.
//

#ifndef TNODE_H
#define TNODE_H

#include <iostream>
#include "Person.h"
using namespace std;

class TNode {
  friend class BSTJokes;
  Person *person;
  TNode *left;
  TNode *right;
  TNode *parent;
  int height;
public:
  TNode();
  TNode(string l, string f, string m, string j);
  void printNode();
  ~TNode();
};



#endif //TNODE_H
