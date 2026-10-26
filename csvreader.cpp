#include "csvreader.h"
#include <stdexcept>

/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extras

// get rid of ;
vector<string> CSVReader::split(string text, char delimiter) {
    vector<string> result;
    
    // read text
    stringstream ss(text);
    string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

void CSVReader::loadCSV(string fileName, gameData& database) {
    ifstream file(fileName);
    string line;

    // skip header 
    getline(file, line);

    // go through all
    while (getline(file, line)) {
        vector<string> columns = split(line, ',');

        // reg values
        int appid = stoi(columns[0]);
        string title = columns[1];
        string releaseDate = columns[3];

        // if multi vals 
        vector<string> genres = split(columns[4], ';');
        vector<string> categories = split(columns[5], ';');

        // more reg nums
        double price = stod(columns[6]);
        int recommendations = stoi(columns[7]);

        // single strings
        string developer = columns[8];
        string publisher = columns[9];

        // getting release year:
        // 
        // creating game based on vals 
        game newGame(appid, price, recommendations, releaseYear, title, developer, publisher, genres, categories);
    
        // adding the new game into the large list 
        database.addGame(newGame);
    }
}