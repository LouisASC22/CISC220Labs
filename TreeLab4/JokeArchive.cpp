//
// Created by Deb on 3/30/2025.
//

#include "JokeArchive.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

JokeArchive::JokeArchive() {
    jokefile = "Jokes2.txt";
	tree = new BSTJokes();
    ReadInFile();
}
JokeArchive::JokeArchive(const string filename) {
	jokefile = filename;
	tree = new BSTJokes();

	/*********Part 1 (and 2) ****************/
	ReadInFile();
	// tree->printTreeIO();
	/*********************************/

	/*********Part 3 *****************/
	// tree->printTreePre();
	// tree->printTreePost();
	/*********************************/

	/*********Part 4 *****************/
	cout <<"*****************************************" << endl;
	cout <<"Testing Find"<<endl;
	tree->find("Smith","Mary","P")->printNode();
	tree->find("Smith","Mary","M")->printNode();

	/*********Part 5 *****************/
	// cout <<"*****************************************" << endl;
	// tree->remove("Patel","Haiya","X");
	// tree->printTreeIO();
	// cout <<"*****************************************" << endl;
	// tree->remove("Campbell","John","P");
	// tree->printTreeIO();

	/*********Part 6 *****************/
	// cout <<"*****************************************" << endl;
	// tree->remove("Dove","Kacey","J");
	// tree->printTreeIO();


	// delete tree;
	// jokefile = "Jokes2.txt";
	// tree = new BSTJokes();
	// ReadInFile();
	// tree->printTreeIO();
	// Menu();
}

void JokeArchive::Menu() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"______________________________________________"<<endl;
		cout <<"Choose Option:\n  f\tFind Student Info\n  a\tAdd a student\n  r\tremove a student\n  p\tprint tree\n  q\tquit"<< endl;
		cout <<endl<<"______________________________________________"<<endl;
		cin >> c;
		switch (c) {
		case 'f': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			cout << "Enter Middle Initial: "<<endl;
			string m;
			cin >> m;
			TNode *t = tree->find(l,f,m);
			if (t == NULL) {
				char k;
				cout << f << " " << l <<" "<<m<<"not found in database.  " << endl;
			}
			else {
				t->printNode();
			}
			break;
		}
		case 'a':{
			string lname;
			string fname;
			string mid;
			string jk;
			cout << "Enter Last: "<<endl;
			cin >> lname;
			cout << "Enter First: " << endl;
			cin >> fname;
			cout << "Enter Middle Initial " << endl;
			cin >> mid;
			cout << endl << "Enter your favorite joke: ";
			cin.ignore();
			getline(cin, jk);

			if (tree->add(lname, fname, mid, jk)) {
				cout << endl <<fname << "\t" << lname<< " inserted successfully "<<endl;
			}
			else {
				TNode *t = tree->find(lname,fname,mid);
				t->printNode();
				cout << "... already in tree with " << endl;
			}
			break;
		}
		case 'r': {
			cout << "Enter Last: "<<endl;
			string l;
			cin >> l;
			cout << "Enter First: "<<endl;
			string f;
			cin >> f;
			cout << "Enter Middle Initial: "<<endl;
			string m;
			cin >> m;
			tree->remove(l,f,m);
			break;
		}
		case 'p': {
			cout << "Choose a for pre, b for in, or c for post-order\t";
			char k;
			cin >> k;
			cout << endl;
			cout <<endl<<"______________________________________________"<<endl;
			if (k == 'a') {
				cout << "*********** Printing Tree Pre Order ************"<<endl;
				cout <<endl<<"______________________________________________"<<endl;
				tree->printTreePre();
			}
			else if (k == 'b') {
				cout << "*********** Printing Tree In Order *************"<<endl;
				cout <<endl<<"______________________________________________"<<endl;
				tree->printTreeIO();
			}
			if (k == 'c') {
				cout << "*********** Printing Tree Post Order ***********"<<endl;
				cout <<endl<<"______________________________________________"<<endl;
				tree->printTreePost();
			}

			break;
		}
		}
	}
}
void  JokeArchive::ReadInFile() {
	ifstream file(jokefile.c_str());
	string word;
	string phrase;
	string f;
	string l;
	string m;
	string j;
	int n;
	file >> l;
	while (!file.eof()) {
		file >> f;
		file >> m;
		getline(file,phrase);
		// cout << "Read: "<< phrase << endl;
		strip(phrase, &j);
		// for testing as I read in -
		// cout << l << ", " << f << ", " << m << ", "<< j << endl;
		// add: you can comment this out until you've gotten add working in BSTJokes
		tree->add(l, f, m, j);
		file >> l;
	}
	// tree->printTreeIO();
	return;
}
void JokeArchive::strip(string s, string *j) {
	const char* WhiteSpace = " \t\n";
	const char* EndChar = "\t\n";
		size_t start = s.find_first_not_of(WhiteSpace);
		//cout << start << endl;
		int len = s.length();
		s = s.substr(start,len-start+1);
		size_t end = s.find_first_of(EndChar);
		//cout << end << endl;

		start = s.find_first_not_of(WhiteSpace);
		len = s.length();
		s = s.substr(start,len-start+1);
		end = s.find_first_of(EndChar);
		/*int num;
		if (end > 0){
			stringstream k(s.substr(0,end));
			num = 0;
			k>>num;
			s = s.substr(end+1, len-end);
		}

		start = s.find_first_not_of(WhiteSpace);
		len = s.length();
		s = s.substr(start,len-start+1);
		end = s.find_first_of(EndChar);
		*/
		if (end > 0){
			*j = s.substr(0,end);
			s = s.substr(end+1, len-end);
		}

	return;

}
