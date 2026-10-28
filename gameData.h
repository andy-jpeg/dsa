#ifndef DSA_GAMEDATA_H
#define DSA_GAMEDATA_H

// my includes:
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Heap.h"

// namespace <3
using namespace std;

/////////////////////// data heaps ////////////////////////////// 
// making heaps for all of the dif data types
class gameData {
private:
	// all of the games
	vector<game> allGames;

	// heaps for each cataporgy 
	unordered_map<string, maxHeap> genreHeaps;
	unordered_map<string, maxHeap> developerHeaps;
	unordered_map<string, maxHeap> publisherHeaps;
	unordered_map<string, maxHeap> categoryHeaps;

public:
	// adding new games to the heaps
	void addGame(game newGame);

	// starts with all games, then it filters based on if it fits what they want 
	vector<game> filterGames(string publisher, string genre, string category, double maxPrice);
};


#endif //DSA_GAMEDATA_H
