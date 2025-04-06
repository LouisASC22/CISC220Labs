//
// Created by Deb on 3/30/2025.
//

#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    last = "";
    first = "";
    mi = "";
    joke = "";
}
Person::Person(string l, string f, string m, string j) {
    last = l;
    first = f;
    mi = m;
    joke = j;
}

void Person::printPerson() {
    cout << last << ", " << first << ", " << mi << ": " << joke;
    cout << endl;

}
Person::~Person() {
    cout <<"Deleting: ";
    printPerson();
}