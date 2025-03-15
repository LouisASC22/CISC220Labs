
#include "DNode.hpp"
#include "DNode.cpp"
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
		// cout << "push" << endl;						// debugging
		DNode *n = new DNode (t,a,m,s);

        if (first == NULL) {
          first = n;
        	last = n;
        } else {
	        n->prev = last;
        	last->next = n;
        	last = n;
        }
		// cout << n->song->title << endl;			// debugging

        numSongs++;

		// Debug: Print the entire list after each insertion
		// cout << "Current Playlist: " << endl;
		// DNode* temp = first;
		// while (temp) {
		// 	cout << temp->song->title << " -> ";
		//	temp = temp->next;
		//}
		//cout << "NULL" << endl;
	}

	Song *DLL::pop() { //does what you'd think
		// cout << "Popping song" << endl;				// debugging
		if (last == NULL) {
			return NULL;
		}

		DNode* n = last; // Start from the first node
		last->prev->next = NULL;
		last = last->prev;
		return n->song;
	}

	void DLL::printList() {
		// cout << "printList" << endl;				// debugging
		if (first == NULL) {
			cout << "Playlist is empty!" << endl;
			return;
		}

		DNode* n = first; // Start from the first node

		while (n != NULL) {							// iterates through the nodes
			if (n->song) {
				// cout << "n.song" << endl;			// debugging
				cout << n->song->title						// prints the song data
						  << ", " << n->song->artist			// Matthew DeMark demonstrated this method of
						  << "................" << n->song->min << ":"	// putting cout on multiple lines
						  << n->song->sec
						  << endl;
				// cout << "n.song2" << endl;					// debugging
			} else {
				cout << "This playlist entry has no song in it" << endl;
			}

			n = n->next; // Move to the next node
		}
		cout << endl;
	}

	void DLL::moveUp(string s) {

		// Case 0: Empty list
		if (first == NULL) {
			cout << "List is empty!" << endl;
			return;
		}

		// Case 1: Single element list
		if (first == last) {
			cout << "Song cannot be moved up" << endl;
			return;
		}

		DNode* n = first;								// creates a new node at the beginning of the list
		DNode* tmp = last;								// holds the song that will be exchanged
		int nindex = 0;									// Track index of node

		while (n->next != NULL) {
			if (n->song->title == s) {

				// Case 2: First node
				if (!n->prev) {
					tmp = last;						// the logic for this was written directly on a desk
					n->next->prev = tmp;			// it is unclear how to match the steps to a diagram
					tmp->prev->next = n;			// see case 4 and 5
					n->prev = tmp->prev;
					last->next = n->next;
					n->next = NULL;
					tmp->prev = NULL;
					first = tmp;
					last = n;
					return;
				}

				// Case 3: Second node
				if (n->prev && !n->prev->prev) {
					first->next = n->next;				// this logic was also written on a table
					first->prev = n;
					n->next = first;
					n->prev = nullptr;
					first = n;
					return;
				}

				// Case 4: Last node
				if (n->next == NULL) {
					tmp = n->prev;						// x<->tmp<->n->NULL
					tmp->next = NULL;					// tmp->NULL and x<->tmp<->n
					last = tmp;							// tmp->NULL and x<->tmp<-n
					n->prev = tmp->prev;				// x<-n<-tmp->NULL
					n->next = tmp;						// x<-n->tmp->NULL
					tmp->prev->next = n;				// x<->n->tmp->NULL
					tmp->prev = n;						// x<->n<->tmp->NULL
					return;
				}

				// Case 5: Any other node
				if (n->prev->prev) {
					tmp = n->prev;						// x<->tmp<->n<->z
					tmp->prev->next = n;				// x->n and x<->tmp->n<->z
					n->next->prev = tmp;				// x->n->y<->z and x<->y
					n->prev = tmp->prev;				// x<-n and x<->y->n<->z
					tmp->prev = n;						// x<->n<-y and x<->y->n<-z
					tmp->next = n->next;				// x<->n->y->z and x<->y->z and n<-z
					n->next = tmp;						// x<->n<->y->z and x<-y
					return;								// this case was not written on a desk
				}
			}

			n = n->next;
			nindex++;									// iteration in a while loop
		}
	}

	void DLL::listDuration(int *tm, int *ts) {
		if (!first) {
				std::cout << "Playlist is empty! Total time: 0m 0s" << std::endl;
				*tm = 0;
				*ts = 0;
				return;
		}

		*tm = 0;
		*ts = 0;
		DNode* n = first;

		while (n->next != NULL) {	// iterates through the list
			*tm += n->song->min;
			*ts += n->song->sec;	// running total of minutes and seconds
			n = n->next;
		}

		//roll over seconds into the minute counter
		*tm += *ts / 60;
		*ts = *ts % 60;
	}
	void DLL::moveDown(string s) {
		// Case 0: Empty list
		if (first == NULL) {
			cout << "List is empty!" << endl;
			return;
		}

		// Case 1: Single element list
		if (first == last) {
			cout << "Song cannot be moved up" << endl;
			return;
		}

		DNode* n = first;								// creates a new node at the beginning of the list
		DNode* tmp = last;								// holds the song that will be exchanged
		DNode* panda = last->prev;						// some cases require two temporary variables
		int nindex = 0;									// Track index of node

		while (n->next != NULL) {
			if (n->song->title == s) {

				// Case 2: Last node
				if (n == last) {
					tmp = first;						// NULL<-tmp<->y...x<->n->NULL
					panda = first->next;				// NULL<-tmp<->panda...x<->n->NULL
					n->prev = NULL;						// NULL<-tmp<->panda...x->n->NULL and NULL<-n
					n->next = tmp->next;				// NULL<-tmp<->panda...x->n and NULL<-n->panda
					tmp->next = NULL;					// NULL<-tmp<-panda...x->n and NULL<-n->panda and tmp->NULL
					tmp->prev = last->prev;				// NULL<-tmp<-panda...x->n and NULL<-n->panda and tmp->NULL
					panda->prev = n;
					first = n;
					last = tmp;
					return;
				}

				// Case 3: Second to last node
				if (n->next == last) {
					tmp = last;
					n->prev->next = tmp;
					tmp->prev = n->prev;
					tmp->next = n;
					n->prev = tmp;
					n->next = NULL;
					last = n;
					return;
				}

				// Case 4: First node
				if (n == first) {
					tmp = n->next;
					first = tmp;
					n->next = tmp->next;
					n->prev = tmp;
					tmp->prev = nullptr;
					tmp->next = n;
					n->next->prev = n;
					return;
				}

				// Case 5: Any other node
				if (n->next->next) {
					tmp = n->next;
					n->next = tmp->next;
					tmp->next = n;
					tmp->prev = n->prev;
					n->prev = tmp;
					tmp->prev->next = tmp;  			// x<->n<-y and x<->y->n<-z
					n->next->prev = n;					// x<->n->y->z and x<->y->z and n<-z
					return;								// this case was not written on a desk
				}
			}

			n = n->next;
			nindex++;									// iteration in a while loop
		}
	}
	void DLL::makeRandom() {
		// code modified from this stackoverflow page
		// https://stackoverflow.com/questions/77983967/how-would-you-shuffle-a-doubly-linked-list

		if (!first || !first->next) {
			std::cout << "Playlist has one element! Cannot shuffle" << std::endl;
			return;
		}

		srand(time(NULL));

		int size = 0;
		DNode* tmp = first;

		while (tmp) {
			size++;
			tmp = tmp->next;
		}

		for (int i = 0; i < size; i++) {
			// select two nodes
			int rand1 = rand() % size;
			int rand2 = rand() % size;

			// Find the nodes at positions rand1 and rand2
			DNode* node1 = first;
			DNode* node2 = first;
			for (int j = 0; j < rand1; j++) {
				node1 = node1->next;
			}
			for (int j = 0; j < rand2; j++) {
				node2 = node2->next;
			}

			// use previous moveup and movedown
			if (node1->prev) node1->prev->next = node2;			// nearly exactly what was on stackoverflow
			if (node1->next) node1->next->prev = node2;			// couldn't find a way to improve it
			if (node2->prev) node2->prev->next = node1;
			if (node2->next) node2->next->prev = node1;

			if (node1 == first) first = node2;					// also couldn't find a way to improve on this
			else if (node2 == first) first = node1;				// part of the stackoverflow
			if (node1 == last) last = node2;
			else if (node2 == last) last = node1;
		}

	}


int DLL::remove(std::string songName) {					// remove() code modified from code in DLL slides
		if (first == NULL) {
			cout << "List is empty!" << endl;
			return -1;									// Return -1 if the list is empty
		}

		DNode* n = first;								// creates a new node at the beginning of the list
		int nindex = 0;									// Track index of node

		while (n->next != NULL) {
			if (n->song->title == songName) {
				cout << "Removing:" << n->song->title
										  << ", " << n->song->artist
										  << "................" << n->song->min << ":"
										  << n->song->sec
										  << endl;

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
		while (current->next != NULL) {		// iterates through the list and deletes each node
			DNode* tmp = current;				// current is being used as a tmp2 equivalent
			current = current->next;
			delete tmp;							// this is preferred to doing everything with one tmp
		}
		first = NULL; // clears the head and tail assignment
		last = NULL;
	}
