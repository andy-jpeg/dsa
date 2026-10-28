#ifndef DSA_MERGESORT_H
#define DSA_MERGESORT_H

// my includes:
#include <vector>
#include <string>
#include <utility>
#include "Heap.h"

// namespace <3
using namespace std;

/////////////////////// merge sort //////////////////////////////
class mergeSorter {
private:
	// what to sort by
	string infoNeeded;

	// sorting
	void mergeSort(vector<game>& games, vector<game>& temp, int left, int right);
	void merge(vector<game>& games, vector<game>& temp, int left, int mid, int right);

public:
	//constructors:
	mergeSorter(string infoNeeded = "recommendations");

	// funcs:
	void sort(vector<game>& games);
	vector<game> topK(vector<game>& games, int k);
	double getInfo(const game& currentGame);

};


#endif //DSA_MERGESORT_H
