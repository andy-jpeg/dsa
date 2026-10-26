#ifndef DSA_HEAP_H
#define DSA_HEAP_H

// my includes:
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <stdexcept>

// namespace <3
using namespace std;

/////////////////////// games ////////////////////////////// 
// making games class
class game {
private:
	// numbers: 
	int appid;
	double price;
	int recommendations;
	int releaseYear;

	// one iterm strings
	string title;
	string developer;
	string publisher;

	// multiple adjectives 
	vector<string> genres;
	vector<string> categories;

public:
	// constructors: 
	game();
	game(int appid, double price, int recommendations, int releaseYear, const string& title, const string& developer, const string& publisher, const vector<string>& genres, const vector<string>& categories);

	// getting numbers: 
	int get_appid() const;
	double get_price() const;
	int get_recommendations() const;
	int get_releaseYear() const;

	// getting one iterm strings
	string get_title() const;
	string get_developer() const;
	string get_publisher() const;

	// getting multiple adjectives 
	vector<string> get_genres() const;
	vector<string> get_categories() const;
};

/////////////////////// max heap ////////////////////////////// 
// making max heap
class maxHeap {
private:
	vector<game> heap;

	// nodes:
	int parent(int index);
	int right(int index);
	int left(int index);

	// chosing what type of data want to make a heap out of 
	string infoNeeded;

	// sorting the heap
	void heapUp(int index);
	void heapDown(int index);

public:
	//constructors: 
	maxHeap();
	maxHeap(string infoNeeded);

	// funcs:
	void insert(game newGame);
	game extractMax();
	game top();
	bool empty();
	int size();
	double getInfo(game currentGame);

};

/////////////////////// min heap ////////////////////////////// 
// making min heap 
class minHeap {
private:
	vector<game> heap;

	// nodes:
	int parent(int index);
	int right(int index);
	int left(int index);

	// chosing what type of data want to make a heap out of 
	string infoNeeded;

	// sorting the heap
	void heapUp(int index);
	void heapDown(int index);

public:
	//constructors: 
	minHeap(string infoNeeded);

	// funcs:
	void insert(game newGame);
	game extractMin();
	game top();
	bool empty();
	int size();
	double getInfo(game currentGame);

};

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


/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extras
class CSVReader {
public:
	vector<string> split(string text, char delimiter);
	void loadCSV(string fileName, gameData& database);
};


#endif //DSA_HEAP_H
