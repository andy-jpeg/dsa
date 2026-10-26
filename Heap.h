#ifndef DSA_HEAP_H
#define DSA_HEAP_H
// my added includes 
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// making games class
class game {
private:
	// numbers: 
	int appid;
	double price;
	int recommendations;

	// one iterm strings
	std::string title;
	std::string developer;
	std::string publisher;

	// multiple adjectives 
	std::vector<std::string> genres;
	std::vector<std::string> catagories;

public:
	// constructors: 
	game();
	game(int appid, double price, int recommendations, const std::string& title, const std::string& developer, const std::string& publisher, const std::vector<std::string>& genres, const std::vector<std::string>& catagories);

	// getting numbers: 
	int get_appid() const;
	double get_price() const;
	int get_recomendations() const;

	// getting one iterm strings
	std::string get_title() const;
	std::string get_developer() const;
	std::string get_publisher() const;

	// getting multiple adjectives 
	std::vector<std::string> get_genres() const;
	std::vector<std::string> get_catagories() const;
};

// making max heap
class maxHeap {
private:
	std::vector<game> heap;

	// nodes:
	int parent(int index);
	int right(int index);  // these are right/left children i just dont want to write kid
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
	int right(int index); // these are right/left children i just dont want to write kid
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

#endif //DSA_HEAP_H#pragma once
