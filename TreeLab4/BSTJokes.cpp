//
// Created by Deb on 3/30/2025.
//

#include "BSTJokes.h"

#include <algorithm>
#include <iostream>
#include <bits/ranges_algo.h>
using namespace std;

BSTJokes::BSTJokes() {
    root = NULL;
}
BSTJokes::BSTJokes(string l, string f, string m, string j) {
    root = new TNode(l,f,m,j);
}
bool BSTJokes::add(string l, string f, string m, string j) {
    // code for adding a node to a binary search tree goes here
    TNode* insertedNode = new TNode(l, f, m, j); // the new node

    int counter = 0;                // debugging

    if (root == NULL) {
        // cout << "This tree has no people in it" << endl;     // debugging
        root = insertedNode;
        // cout << counter << endl;                    // debugging
        // cout << insertedNode->person->last << endl;     //debugging
        return true;
    }

    TNode* n = root;                // the pointer that iterates through the tree
    TNode* parentNode = NULL;           // the parent of n

    while (n != NULL) {             // iterates until end of tree
        counter++;                  // debugging

        parentNode = n;                 // shifts pointer


        Person *berson = n->person;         // the person field of the current node

        if (berson == NULL) {
            // cout << "This node has no person field" << endl;  // debugging
            break;
        }

        // the following is based on code from the slides
        if (l < berson->last ||                                             // checks the last name order alphabetically
            (l == berson->last && f < berson->first) ||                     // then the first name
            (l == berson->last && f == berson->first && m < berson->mi)) {  // then the middle initial
            n = n->left;
            // cout << "left" << endl;     // debugging
        } else {                        // if none of these are less, then the person has a higher index in the order
            n = n->right;
            // cout << "right" << endl;     // debugging
        } // if
    } // while

    // cout << counter << endl;            // debugging

    insertedNode->parent = parentNode;

    if (l < parentNode->person->last ||                                         // checks the first name
        (l == parentNode->person->last && f < parentNode->person->first) ||     // then the last name
        (l == parentNode->person->last && f == parentNode->person->first &&
            m < parentNode->person->mi)) {                                      // then the middle initial
        parentNode->left = insertedNode;
    } else {                        // if none of these are less, then the person has a higher index in the order
        parentNode->right = insertedNode;
    } // if

    // cout << insertedNode->person->last << endl;              // debugging

    setHeight(insertedNode);                // set the height field of the node

    return true;
} // add

TNode *BSTJokes::find(string l, string f, string m){
    // code for finding a node in a binary search tree goes here
    // code for adding a node to a binary search tree goes here
    TNode* foundNode = new TNode(l, f, m, "."); // the new node, with empty joke

    int counter = 0;                // debugging

    if (root == NULL) {
        // cout << "This tree has no people in it" << endl;     // debugging
        root = foundNode;
        // cout << counter << endl;                    // debugging
        // cout << insertedNode->person->last << endl;     //debugging
        return foundNode;
    }

    TNode* n = root;                // the pointer that iterates through the tree
    TNode* parentNode = NULL;           // the parent of n

    while (n != NULL) {             // iterates until end of tree
        counter++;                  // debugging

        parentNode = n;                 // shifts pointer


        Person *berson = n->person;         // the person field of the current node

        if (berson == NULL) {
            // cout << "This node has no person field" << endl;  // debugging
            break;
        }

        if (berson->last == l && f == berson->first && m == berson->mi) {
            foundNode->person->joke = berson->joke;
            return foundNode;
        }

        // the following is based on code from the slides
        if (l < berson->last ||                                             // checks the last name order alphabetically
            (l == berson->last && f < berson->first) ||                     // then the first name
            (l == berson->last && f == berson->first && m < berson->mi)) {  // then the middle initial
            n = n->left;
            // cout << "left" << endl;     // debugging
        } else {                        // if none of these are less, then the person has a higher index in the order
            n = n->right;
            // cout << "right" << endl;     // debugging
        } // if
    } // while

    // cout << counter << endl;            // debugging

    return foundNode;
}

void BSTJokes::printTreeIO() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing In Order:" <<endl;
        printTreeIO(root);
    }
}
void BSTJokes::printTreeIO(TNode *n) {
    // code for printing a tree in order goes here
    if (n == NULL) {
        return;
    }

    printTreeIO(n->left);
    n->printNode();
    printTreeIO(n->right);
}

void BSTJokes::printTreePre() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing PreOrder:" <<endl;
        printTreePre(root);
    }
}
void BSTJokes::printTreePre(TNode *n) {
    //code for printing a tree in pre-order goes here
    if (n == NULL) {
        return;
    }

    n->printNode();
    printTreePre(n->left);
    printTreePre(n->right);
}

void BSTJokes::printTreePost() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        cout << endl<<"Printing Post Order:" <<endl;
        printTreePost(root);
    }
}
void BSTJokes::printTreePost(TNode *n) {
    //code for printing a tree in post-order goes here
    if (n == NULL) {
        return;
    }

    printTreePost(n->left);
    printTreePost(n->right);
    n->printNode();
}

void BSTJokes::setHeight(TNode *n) {
    // code for setting a node's height and then its ancestors' heights goes here

    // cout << "height is being set" << endl;                        // debugging

    if (n != NULL) {
        int heightLeft = 0;
        int heightRight = 0;

        if (n->left != NULL) {
            heightLeft = n->left->height;
        }

        if (n->right != NULL) {
            heightRight = n->right->height;
        }

        n->height = 1 + max(heightLeft, heightRight);     // the height is one more than the height below it
    }

    // cout << "height has been found" << endl;

    TNode* temp = n->parent;
    while (temp != NULL) {                  // iterate upward
        setHeight(temp);
        temp = temp->parent;
    }

    // cout << endl<<"Height is: "<<n->height<<endl;           // debugging
}
void BSTJokes::removeNoKids(TNode *tr) {
    //code for removing a node (tr) with no kids goes here
}
void BSTJokes::removeOneKid(TNode *tr) {
    //code for removing a node (tr) with only one kid goes here)
}

TNode *BSTJokes::findReplacement(TNode *tr) {
    //code for finding a node closest in value to tr (and this will replace tr) goes here
	// note that this method should find the replacement as the leftmost node in the right 
	//subtree
}

void BSTJokes::removeTwoKids(TNode *tr) {
    //code for removing a node (tr) with two kids goes here
}

void BSTJokes::remove(string l, string f, string m) {
    // this method finds the node with l, f, and m as data and then determines whether that
	//node has 0 children, 1 child, or 2 children, and calls the appropriate remove method
}

BSTJokes::~BSTJokes() {
    if (root != NULL) {
        clearTree(root);
    }
    cout << "______________________________________________________"<<endl;
    cout <<"__             Tree Deleted                         __"<<endl;
    cout << "______________________________________________________"<<endl;
}

void BSTJokes::clearTree(TNode *tmp) {
    //This is a post-order traversal to remove all the nodes in a tree//
}

