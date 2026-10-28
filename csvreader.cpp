#include "csvreader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extras

// splitting a line into columns
// dates are quoted ("Jul 5, 2024") so commas inside quotes stay in the column
vector<string> CSVReader::splitLine(string line) {
    vector<string> columns;
    string current;
    bool inQuotes = false;

    for (int i = 0; i < line.size(); i++) {
        char c = line[i];

        if (inQuotes) {
            // "" inside quotes = a real quote
            if (c == '"' && i + 1 < line.size() && line[i + 1] == '"') {
                current += '"';
                i++;
            }
            else if (c == '"') {
                inQuotes = false;
            }
            else {
                current += c;
            }
        }
        else if (c == '"') {
            inQuotes = true;
        }
        else if (c == ',') {
            columns.push_back(current);
            current = "";
        }
        // skip windows line endings
        else if (c != '\r') {
            current += c;
        }
    }
    columns.push_back(current);

    return columns;
}

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

int CSVReader::loadCSV(string fileName, gameData& database) {
    ifstream file(fileName);
    string line;
    int loaded = 0;

    if (!file.is_open()) {
        cerr << "couldnt open " << fileName << endl;
        return 0;
    }

    // skip header 
    getline(file, line);

    // go through all
    while (getline(file, line)) {
        vector<string> columns = splitLine(line);

        // skip broken rows
        if (columns.size() != 10) {
            continue;
        }

        try {
            // reg values
            int appid = stoi(columns[0]);
            string title = columns[1];
            int releaseYear = stoi(columns[2]);

            // if multi vals 
            vector<string> genres = split(columns[4], ';');
            vector<string> categories = split(columns[5], ';');

            // more reg nums
            double price = stod(columns[6]);
            int recommendations = stoi(columns[7]);

            // single strings
            string developer = columns[8];
            string publisher = columns[9];

            // creating game based on vals 
            game newGame(appid, price, recommendations, releaseYear, title, developer, publisher, genres, categories);
        
            // adding the new game into the large list 
            database.addGame(newGame);
            loaded++;
        }
        catch (const exception& e) {
            // bad number in this row -> skip it
            continue;
        }
    }

    return loaded;
}
