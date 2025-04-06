//
// Created by Deb on 3/30/2025.
//

#include "TNode.h"
#include <iostream>
using namespace std;

TNode::TNode() {
    left = NULL;
    right = NULL;
    parent = NULL;
    height = 0;
}
TNode::TNode(const string l, const string f, const string m, const string joke) {
    person = new Person(l, f, m, joke);  // create a new person
    left = NULL;
    right = NULL;
    parent = NULL;
    height = 1;  // initial height 1
}
TNode::~TNode() {
    delete person;
}
void TNode::printNode() {
    cout << height << ": ";
    person->printPerson();
}


