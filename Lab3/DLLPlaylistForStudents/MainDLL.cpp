#include <iostream>
#include <stdlib.h>
#include "Playlist.hpp" // I still have to include everything for this to work
#include "Playlist.cpp"
#include "DLL.hpp"
#include "DLL.cpp"
#include "Song.hpp"
#include "Song.cpp"
#include "DNode.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	// Playlist *list = new Playlist;
	Playlist *list = new Playlist("ShortListofSongs.txt");
	// DLL* playlist = new DLL();
	//list->readList("ShortListofSongs.txt");
	//Playlist myPlaylist;
	// myPlaylist.readList("ShortListofSongs.txt");
}

