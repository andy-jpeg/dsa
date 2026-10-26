#include "heap.h"


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
	string releaseDate;

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
