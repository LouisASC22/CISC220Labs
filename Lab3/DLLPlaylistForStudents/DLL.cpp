
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}
	void DLL::push(string t, string a, int m, int s) {  // does what you'd think
		DNode *n = new DNode (t,a,m,s);

        if (first == NULL) {
          first = n;
        }

        DNode *last = first;
        while(last->next != NULL) {
          last = last->next;
        }

        last->next = n;

        numSongs++;
	}
	// Song *DLL::pop() { //does what you'd think
	// }

	void DLL::printList() {
	}

	void DLL::moveUp(string s) {
	}

	void DLL::listDuration(int *tm, int *ts) {
			}
	void DLL::moveDown(string s) {
			}
	void DLL::makeRandom() {
		}


int DLL::remove(std::string songName) {					// remove() code taken from DLL slides
		if (first == nullptr) {
			std::cout << "List is empty!" << std::endl;
			return -1; // Return -1 if the list is empty
		}

		DNode* current = first;							// creates a new node at the beginning of the list
		int nindex = 0;									// Track index of node

		while (current->next != nullptr) {
			if (current->song->title == songName) {
				if (current->prev) {
					current->prev->next = current->next;
				} else {
					first = current->next;
				}

				if (current->next) {
					current->next->prev = current->prev;
				} else {
					last = current->prev;
				}

				delete current;							// delete the node
				return nindex;							// Return the index of the deleted node
			}

			current = current->next;
			nindex++;									// iteration in a while loop
		}
		return -1;										// Return -1 if the song wasn't found
	}
// note that the int returned is the index - this is standard for a remove, but we won't be using it.



DLL::~DLL() {									// destructor code taken from DLL slides
		DNode* current = first;					// sets a pointer to the beginning of the list
		while (current->next != nullptr) {		// iterates through the list and deletes each node
			DNode* tmp = current;				// current is being used as a tmp2 equivalent
			current = current->next;
			delete tmp;							// this is preferred to doing everything with one tmp
		}
		first = nullptr; // clears the head and tail assignment
		last = nullptr;
	}
