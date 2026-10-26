#ifndef DSA_HEAP_H
#define DSA_HEAP_H

// my includes:
#include <vector>
#include <algorithm>
#include <string>

// namespace <3
using namespace std;

// making games class
class game {
private:
	// numbers: 
	int appid;
	double price;
	int recommendations;

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
	game(int appid, double price, int recommendations, const string& title, const string& developer, const string& publisher, const vector<string>& genres, const vector<string>& categories);

	// getting numbers: 
	int get_appid() const;
	double get_price() const;
	int get_recommendations() const;

	// getting one iterm strings
	string get_title() const;
	string get_developer() const;
	string get_publisher() const;

	// getting multiple adjectives 
	vector<string> get_genres() const;
	vector<string> get_categories() const;
};

// making max heap
class maxHeap {
private:
	vector<game> heap;

	// nodes:
	int parent(int index);
	int right(int index);
	int left(int index);

	// sorting the heap
	void heapUp(int index);
	void heapDown(int index);

public:
	//constructors: 
	maxHeap();

	// funcs:
	void insert(game newGame);
	game extractMax();
	game top();
	bool empty();
	int size();

};

// making min heap 
class minHeap {
private:
	std::vector<game> heap;

	// nodes:
	int parent(int index);
	int right(int index);
	int left(int index);

	// sorting the heap
	void heapUp(int index);
	void heapDown(int index);

public:
	//constructors: 
	minHeap();

	// funcs:
	void insert(game newGame);
	game extractMin();
	game top();
	bool empty();
	int size();
};

#endif //DSA_HEAP_H
