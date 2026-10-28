#ifndef DSA_GAMEINFO_H
#define DSA_GAMEINFO_H

// my includes:
#include <vector>
#include <string>

// namespace <3
using namespace std;

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


#endif //DSA_GAMEINFO_H
