// adding header
#include "HeapSort.h"


/////////////////////// heap sort //////////////////////////////
heapSorter::heapSorter(string infoNeeded) {
    this->infoNeeded = infoNeeded;
};


//// nodes:
int heapSorter::parent(int index) {
    return (index - 1) / 2;
};

int heapSorter::left(int index) {
    return (2 * index) + 1;
};

int heapSorter::right(int index) {
    return (2 * index) + 2;
};


//// sorting the heap:
// like maxHeap::heapDown, but stops at heapSize
void heapSorter::heapDown(vector<game>& games, int index, int heapSize) {
    int largest = index;

    if (left(index) < heapSize && getInfo(games[left(index)]) > getInfo(games[largest])) {
        largest = left(index);
    }
    if (right(index) < heapSize && getInfo(games[right(index)]) > getInfo(games[largest])) {
        largest = right(index);
    }
    if (largest != index) {
        swap(games[index], games[largest]);
        heapDown(games, largest, heapSize);
    }
};

// heapDown from the last parent up -> O(n)
void heapSorter::buildHeap(vector<game>& games) {
    int heapSize = games.size();

    for (int i = parent(heapSize - 1); i >= 0; i--) {
        heapDown(games, i, heapSize);
    }
};


//// funcs:
// lowest -> highest
void heapSorter::sort(vector<game>& games) {
    buildHeap(games);

    // move max to the back, shrink heap
    for (int end = games.size() - 1; end > 0; end--) {
        swap(games[0], games[end]);
        heapDown(games, 0, end);
    }
};

// k highest, highest first (reorders games)
vector<game> heapSorter::topK(vector<game>& games, int k) {
    vector<game> best;

    if (k > (int)games.size()) {
        k = games.size();
    }
    if (k <= 0) {
        return best;
    }

    buildHeap(games);
    int heapSize = games.size();

    for (int i = 0; i < k; i++) {
        best.push_back(games[0]);

        heapSize--;
        swap(games[0], games[heapSize]);
        heapDown(games, 0, heapSize);
    }

    return best;
};

double heapSorter::getInfo(const game& currentGame) {
    if (infoNeeded == "recommendations") {
        return currentGame.get_recommendations();
    }
    if (infoNeeded == "price") {
        return currentGame.get_price();
    }
    return 0;
};
