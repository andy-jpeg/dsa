// adding header
#include "heap.h"
#include "gameinfo.h"


/////////////////////// max heap ////////////////////////////// 
//// making max heap
//having = recomendations gives it something to sort by inside of each heap catagory 
maxHeap::maxHeap() {
    infoNeeded = "recommendations";
};

// if already has something to sort by 
maxHeap::maxHeap(string infoNeeded) {
    heap = vector<game>();

    this->infoNeeded = infoNeeded;
};

//// nodes:
// parent 
int maxHeap::parent(int index) {
    return (index - 1) / 2;
};

// left child
int maxHeap::left(int index) {
    return (2 * index) + 1;
};

// right child
int maxHeap::right(int index) {
    return (2 * index) + 2;
};


//// sorting the heap:
// when added to bottom left leaf: heapify
void maxHeap::heapUp(int index) {
    while (index > 0) {
        int parIndex = parent(index);
        
        // if smallest val
        if (getInfo(heap[index]) <= getInfo(heap[parIndex])) {
            break;
        }

        //// if bigger val than above
        // getting info
        game child = heap[index];
        game parent = heap[parIndex];

        // swaping two
        heap[index] = parent;
        heap[parIndex] = child;

        index = parIndex;
    }
};

// when removing top ele: heapify
void maxHeap::heapDown(int index) {
    // big val
    int largest = index;

    // if left child is bigger than the max atm
    if (left(index) < heap.size() && getInfo(heap[left(index)]) > getInfo(heap[largest])) {
        largest = left(index);
    }
    // if right child is bigger than the max atm/left
    if (right(index) < heap.size() && getInfo(heap[right(index)]) > getInfo(heap[largest])) {
        largest = right(index);
    }
    // if one of the children is bigger than max, then you swap the vals 
    if (largest != index) {
        // getting the child/par info
        game parent = heap[index];
        game child = heap[largest];

        //swapping
        heap[index] = child;
        heap[largest] = parent;

        //doing again
        heapDown(largest);
    }
};


//// getting info:
// insert
void maxHeap::insert(game newGame) {
    heap.push_back(newGame);
    heapUp(heap.size() - 1);
};

// getting highest val -> taking it out
game maxHeap::extractMax() {
    // making sure values exist:
    if (heap.empty()) {
        return game();
    }

    // getting max value from heap
    game maxGame = heap[0];

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if (!heap.empty()) {
        heapDown(0);
    }
    return maxGame;
};

// highest val
game maxHeap::top() {
    if (heap.empty())
    {
        return game();
    }
    return heap[0];
};

// if empty 
bool maxHeap::empty() {
    return heap.empty();
};

// size of the heap
int maxHeap::size() {
    return heap.size();
};

// getting the type of info that you are sorting by 
double maxHeap::getInfo(game currentGame) {
    if (infoNeeded == "recommendations") {
        return currentGame.get_recommendations();
    }
    if (infoNeeded == "price") {
        return currentGame.get_price();
    }
    return 0;
};


/////////////////////// min heap ////////////////////////////// 
//// making min heap 
//constructors: 
minHeap::minHeap(string infoNeeded) {
    heap = vector<game>();

    this->infoNeeded = infoNeeded;
};


//// nodes:
// parent: 
int minHeap::parent(int index) {
    return (index - 1) / 2;
};

// left child
int minHeap::left(int index) {
    return (2 * index) + 1;
};

// right child
int minHeap::right(int index) {
    return (2 * index) + 2;
};


//// sorting the heap
// when added to bottom left leaf:
void minHeap::heapUp(int index) {
    while (index > 0) {
        int parIndex = parent(index);

        // if smallest val
        if (getInfo(heap[index]) > getInfo(heap[parIndex])) {
            break;
        }

        //// if bigger val than above
        // getting info
        game child = heap[index];
        game parent = heap[parIndex];

        // swaping two
        heap[index] = parent;
        heap[parIndex] = child;

        index = parIndex;
    }
};

// when removing top ele: 
void minHeap::heapDown(int index) {
    // big val
    int smallest = index;

    // if left child is bigger than the max atm
    if (left(index) < heap.size() && getInfo(heap[left(index)]) < getInfo(heap[smallest])) {
        smallest = left(index);
    }
    // if right child is bigger than the max atm/left
    if (right(index) < heap.size() && getInfo(heap[right(index)]) < getInfo(heap[smallest])) {
        smallest = right(index);
    }
    // if one of the children is bigger than max, then you swap the vals 
    if (smallest != index) {
        // getting the child/par info
        game parent = heap[index];
        game child = heap[smallest];

        //swapping
        heap[index] = child;
        heap[smallest] = parent;

        //doing again
        heapDown(smallest);
    }
};


//// funcs:
// insert new val:
void minHeap::insert(game newGame) {
    heap.push_back(newGame);
    heapUp(heap.size() - 1);
};

// getting top val -> remove after 
game minHeap::extractMin() {
    // making sure values exist:
    if (heap.empty()) {
        return game();
    }
    // getting max value from heap
    game minGame = heap[0];

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if (!heap.empty()) {
        heapDown(0);
    }

    return minGame;
};

// getting the min val
game minHeap::top() {
    if (heap.empty()) {
        return game();
    }
    return heap[0];
};

// seeing if empty 
bool minHeap::empty() {
    return heap.empty();
};

// finding the size of the heap
int minHeap::size() {
    return heap.size();
};

double minHeap::getInfo(game currentGame) {
    if (infoNeeded == "recommendations") {
        return currentGame.get_recommendations();
    }
    if (infoNeeded == "price") {
        return currentGame.get_price();
    }
    return 0;
};
