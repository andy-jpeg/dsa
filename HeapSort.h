#ifndef DSA_HEAPSORT_H
#define DSA_HEAPSORT_H

// my includes:
#include <vector>
#include <string>
#include <utility>
#include "Heap.h"

// namespace <3
using namespace std;

/////////////////////// heap sort //////////////////////////////
class heapSorter {
private:
	// nodes:
	int parent(int index);
	int right(int index);
	int left(int index);

	// what to sort by
	string infoNeeded;

	// sorting the heap
	void heapDown(vector<game>& games, int index, int heapSize);
	void buildHeap(vector<game>& games);

public:
	//constructors:
	heapSorter(string infoNeeded = "recommendations");

	// funcs:
	void sort(vector<game>& games);
	vector<game> topK(vector<game>& games, int k);
	double getInfo(const game& currentGame);

};


#endif //DSA_HEAPSORT_H
