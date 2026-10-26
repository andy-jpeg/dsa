// adding header
#include "heap.h"


/////////////////////// games ////////////////////////////// 
// base case
game::game() {
	appid = 0;
	price = 0.0;
	recommendations = 0;
    releaseYear = 0;
	title = "";
	developer = "";
	publisher = "";
};

// other cases
game::game(int appid, double price, int recommendations, int releaseYear, const string& title, const string& developer, const string& publisher, const vector<string>& genres, const vector<string>& categories) {
	this->appid = appid;
	this->price = price;
	this->recommendations = recommendations;
    this->releaseYear = releaseYear;
	this->title = title;
	this->developer = developer;
	this->publisher = publisher;
	this->genres = genres;
	this->categories = categories;
};

//// getting numbers: 
int game::get_appid() const {
	return appid;
};

double game::get_price() const {
	return price;
};

int game::get_recommendations() const {
	return recommendations;
};

int game::get_releaseYear() const {
    return releaseYear;
};


//// getting one iterm strings
string game::get_title() const {
	return title;
};

string game::get_developer() const {
	return developer;
};

string game::get_publisher() const {
	return publisher;
};


//// getting multiple adjectives 
vector<string> game::get_genres() const {
	return genres;
};

vector<string> game::get_categories() const {
	return categories;
};


/////////////////////// max heap ////////////////////////////// 
//// making max heap
maxHeap::maxHeap() {
    infoNeeded = "recommendations";
};

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
// when added to bottom left leaf:
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

// when removing top ele: 
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


/////////////////////// data heaps ////////////////////////////// 
// creating a filter of all of the games, if they are matching what they want it will go in the new list:
vector<game> gameData::filterGames(string publisher, string genre, string category, double maxPrice) {
    // creating a vector for the games that fit
    vector<game> matchingGames;

    for (const game& currentGame:allGames) {
        // if has all things: 
        if (!publisher.empty() && currentGame.get_publisher() != publisher) {
            continue;
        }
        if (currentGame.get_price() > maxPrice) {
            continue;
        }
        vector<string> genres = currentGame.get_genres();
        if (!genre.empty() && find(genres.begin(), genres.end(), genre) == genres.end()) {
            continue;
        }
        vector<string> categories = currentGame.get_categories();
        if (!category.empty() && find(categories.begin(), categories.end(), category) == categories.end()) {
            continue;
        }
        matchingGames.push_back(currentGame);
    }
    return matchingGames;
};

// adding new games to the heaps/ with correct data 
void gameData::addGame(game newGame) {
    // adding game to the list of all games:
    allGames.push_back(newGame);

    //// developer heap
    // if the genre doesnt exist yet:
    if (developerHeaps.find(newGame.get_developer()) == developerHeaps.end()) {
        maxHeap newHeap("recommendations");
        developerHeaps.insert({newGame.get_developer(), newHeap});
    }
    // add new game:
    developerHeaps[newGame.get_developer()].insert(newGame);

    //// publisher heap
    if (publisherHeaps.find(newGame.get_publisher()) == publisherHeaps.end()) {
        maxHeap newHeap("recommendations");
        publisherHeaps.insert({newGame.get_publisher(), newHeap});
    }
    publisherHeaps[newGame.get_publisher()].insert(newGame);

    //// genre heaps
    for (string genre:newGame.get_genres()) {
        if (genreHeaps.find(genre) == genreHeaps.end()) {
            maxHeap newHeap("recommendations");
            genreHeaps.insert({genre, newHeap});
        }
        genreHeaps[genre].insert(newGame);
    }

    //// category heaps
    for (string category : newGame.get_categories()) {
        if (categoryHeaps.find(category) == categoryHeaps.end()) {
            maxHeap newHeap("recommendations");
            categoryHeaps.insert({category, newHeap});
        }
        categoryHeaps[category].insert(newGame);
    }
};

/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extras
// get rid of ;
