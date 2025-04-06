

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;


class Person {
    friend class TNode;
    friend class BSTJokes;
    string last;
    string first;
    string mi;
    string joke;
public:
    Person();  // normal constructor
    Person(string l, string f, string m, string j);  // parameter constructor
    ~Person();
    void printPerson();
};



#endif //PERSON_H
