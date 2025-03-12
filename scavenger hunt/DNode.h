//
// Created by luigi on 3/11/2025.
//

#ifndef DNODE_H
#define DNODE_H
#include <stdlib.h>
using namespace std;

class DNode {
  char data;
  DNode* prev;
  DNode* next;
  public:
    DNode();
    DNode(char g, char d, DNode* p, DNode* n);
};



#endif //DNODE_H
