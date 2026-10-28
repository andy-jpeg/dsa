#include "gameInfo.h"

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



