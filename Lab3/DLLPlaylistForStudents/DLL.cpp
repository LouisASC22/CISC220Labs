
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
		if (first == nullptr) {
			cout << "Playlist is empty!" << endl;
			return;
		}

		DNode* n = first; // Start from the first node

		while (n->next != nullptr) {							// iterates through the nodes
			if (n->song) {
				std::cout << n->song->title						// prints the song data
						  << ", " << n->song->artist			// Matthew DeMark demonstrated this method of
						  << "................" << n->song->min << ":"	// putting cout on multiple lines
						  << n->song->sec
						  << endl;
			} else {
				cout << "This playlist entry has no song in it" << endl;
			}

			n = n->next; // Move to the next node
		}
	}

	void DLL::moveUp(string s) {
	}

	void DLL::listDuration(int *tm, int *ts) {
			}
	void DLL::moveDown(string s) {
			}
	void DLL::makeRandom() {
		}


int DLL::remove(std::string songName) {					// remove() code modified from code in DLL slides
		if (first == nullptr) {
			std::cout << "List is empty!" << std::endl;
			return -1;									// Return -1 if the list is empty
		}

		DNode* n = first;								// creates a new node at the beginning of the list
		int nindex = 0;									// Track index of node

		while (n->next != nullptr) {
			if (n->song->title == songName) {
				if (n->prev) {
					n->prev->next = n->next;
				} else {
					first = n->next;
				}

				if (n->next) {
					n->next->prev = n->prev;
				} else {
					last = n->prev;
				}

				delete n;								// delete the node
				return nindex;							// Return the index of the deleted node
			}

			n = n->next;
			nindex++;									// iteration in a while loop
		}
		return -1;										// Return -1 if the song wasn't found
	}
// note that the int returned is the index - this is standard for a remove, but we won't be using it.



DLL::~DLL() {									// destructor code modified from code in DLL slides
		DNode* current = first;					// sets a pointer to the beginning of the list
		while (current->next != nullptr) {		// iterates through the list and deletes each node
			DNode* tmp = current;				// current is being used as a tmp2 equivalent
			current = current->next;
			delete tmp;							// this is preferred to doing everything with one tmp
		}
		first = nullptr; // clears the head and tail assignment
		last = nullptr;
	}
