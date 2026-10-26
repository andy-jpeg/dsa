// adding header
#include "Heap.h"

#ifndef DSA_HEAP_CPP
#define DSA_HEAP_CPP

/////////////////////// games ////////////////////////////// 
// base case
game::game() {
	appid = 0;
	price = 0.0;
	recommendations = 0;
	title = "";
	developer = "";
	publisher = "";
};

// other cases
game::game(int appid, double price, int recommendations, const std::string& title, const std::string& developer, const std::string& publisher, const std::vector<std::string>& genres, const std::vector<std::string>& categories) {
	this->appid = appid;
	this->price = price;
	this->recommendations = recommendations;
	this->title = title;
	this->developer = developer;
	this->publisher = publisher;
	this->genres = genres;
	this->categories = categories;
};

//// getting numbers: 
// id
int game::get_appid() const {
	return appid;
};

// price
double game::get_price() const {
	return price;
};

// recomend
int game::get_recommendations() const {
	return recommendations;

};

//// getting one iterm strings
// title
std::string game::get_title() const {
	return title;
};

//dev
std::string game::get_developer() const {
	return developer;
};

// pub
std::string game::get_publisher() const {
	return publisher;
};

//// getting multiple adjectives 
// genre
std::vector<std::string> game::get_genres() const {
	return genres;
};

// cat
std::vector<std::string> game::get_categories() const {
	return categories;
};

/////////////////////// max heap ////////////////////////////// 
//// making max heap
maxHeap::maxHeap() {
    heap = vector<game>();
};

//// nodes:
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
// when added to bottom left leaf:
void maxHeap::heapUp(int index) {
    while (index > 0) {
        int parIndex = parent(index);

        // if smallest val
        if (heap[index].get_recommendations() <= heap[parIndex].get_recommendations()) {
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
void maxHeap::heapDown(int index) {
    // big val
    int largest = index;

    // if left child is bigger than the max atm
    if (left(index) < heap.size() && heap[left(index)].get_recommendations() > heap[largest].get_recommendations()) {
        largest = left(index);
    }
    // if right child is bigger than the max atm/left
    if (right(index) < heap.size() && heap[right(index)].get_recommendations() > heap[largest].get_recommendations()) {
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
    // getting max value from heap
    game maxGame = heap[0];

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if (!heap.empty()) {
        heapDown(0);
    }
    else if (heap.empty()) {
      return game();
    }
  
    return maxGame;
};

// highest val
game maxHeap::top() {
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
