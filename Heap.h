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

#include "gameInfo.h"

// namespace <3
using namespace std;


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

	// sorting the heap/heapify
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

	// sorting the heap/heapify
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


#endif //DSA_HEAP_H
